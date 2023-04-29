/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
bool checkPrime(int n) {
    if (n < 2) return false;
    else {
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}
void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}
string addString(string a, string b) {
    string result = "";
    int du = 0;
    for (int i = 0; i < 10; ++i) {
        result += to_string((stoi(a.substr(i, 1)) + stoi(b.substr(i, 1)) + du) % 10);
        du = (stoi(a.substr(i, 1)) + stoi(b.substr(i, 1)) + du) / 10;
    }
    return result;
}
struct Toado {
    int x;
    int y;
};
string notebook1(string ntb1) {
    ifstream input(ntb1);
    input.is_open();

    string result = "";
    string line1;
    getline(input, line1);
    line1 = line1.substr(11);
    // cout<<line1;
    if (line1[0] == '0' && line1[1] == '0' && line1[2] == '0') return "0000000000";
    if (line1[0] < 48 || line1[0] > 57) return "0000000000";
    if (line1[1] < 48 || line1[1] > 57) return "0000000000";
    if (line1[2] < 48 || line1[2] > 57) return "0000000000";

    int cap = stoi(line1);
    // cout << cap;
    int* data = new int[cap];
    int result_int[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < cap; ++i) {
        input >> data[i];
        if (data[i] == 0) { result_int[0]++; result_int[0] = result_int[0] % 10; }
        if (data[i] == 1) { result_int[1]++; result_int[1] = result_int[1] % 10; }
        if (data[i] == 2) { result_int[2]++; result_int[2] = result_int[2] % 10; }
        if (data[i] == 3) { result_int[3]++; result_int[3] = result_int[3] % 10; }
        if (data[i] == 4) { result_int[4]++; result_int[4] = result_int[4] % 10; }
        if (data[i] == 5) { result_int[5]++; result_int[5] = result_int[5] % 10; }
        if (data[i] == 6) { result_int[6]++; result_int[6] = result_int[6] % 10; }
        if (data[i] == 7) { result_int[7]++; result_int[7] = result_int[7] % 10; }
        if (data[i] == 8) { result_int[8]++; result_int[8] = result_int[8] % 10; }
        if (data[i] == 9) { result_int[9]++; result_int[9] = result_int[9] % 10; }
        // cout << data[i] <<' ';
    }
    for (int i = 0; i < 10; ++i) {
        result += to_string(result_int[i]);
    }
    delete[] data;
    input.close();
    return result;
}

string notebook2(string ntb2) {
    ifstream input(ntb2);
    input.is_open();

    string line1;
    getline(input, line1);
    if (line1.size() != 5) return "1111111111";
    else {
        for (int i = 0; i < 5; ++i) {
            if (line1[i] < 48 || line1[i] > 57) return "1111111111";
        }
    }
    int cap = stoi(line1);
    if (cap < 5 || cap > 500) return "1111111111";
    string* data = new string[cap];

    for (int i = 0; i < cap; i++) {
        getline(input, data[i]);
        // cout << data[i] << endl;
    }

    int count = 0;
    for (int i = 0; i < cap; ++i) {
        int size = data[i].size();
        int k = 0;
        while (data[i][k] != '\0') {
            if (data[i].find("pink", k) != -1) {
                ++count;
                k = data[i].find("pink", k) + 1;
            }
            else break;
        }
        k = 0;
        while (data[i][k] != '\0') {
            if (data[i].find("Pink", k) != -1) {
                ++count;
                k = data[i].find("Pink", k) + 1;
            }
            else break;
        }
    }
    if (count / 10000 == 0) count = count * count;
    string result = to_string(count);
    while (result.size() < 10) {
        result += '9';
    }
    delete[] data;
    input.close();
    return result;
}

string notebook3(string ntb3) {
    ifstream input(ntb3);
    input.is_open();
    string arr[10];

    for (int i = 0; i < 10; i++) {
        getline(input, arr[i]);
    }
    int data[10][10];
    for (int i = 0; i < 10; i++) {
        int j = 0;
        int count = 0;
        int pos = 0;
        int index = 0;
        while (arr[i][j] != '\0') {
            if (arr[i][j] == '|') {
                data[i][pos] = stoi(arr[i].substr(index, count));
                if (data[i][pos] < 0) data[i][pos] = -data[i][pos];
                index = j + 1;
                ++pos;
                count = 0;
            }
            ++j;
            ++count;
        }
        data[i][pos] = stoi(arr[i].substr(index, count));
        if (data[i][pos] < 0) data[i][pos] = -data[i][pos];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            while (!checkPrime(data[i][j])) {
                data[i][j] += 1;
            }
        }
    }
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 1; k < 50; ++k) {
                if (data[i][j] <= round((pow((1 + sqrt(5)) / 2, k) - pow((1 - (1 + sqrt(5)) / 2), k)) / sqrt(5))) {
                    data[i][j] = round((pow((1 + sqrt(5)) / 2, k) - pow((1 - (1 + sqrt(5)) / 2), k)) / sqrt(5));
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 7; j < 10; ++j) {
            for (int k = j + 1; k < 10; ++k) {
                if (data[i][j] > data[i][k]) swap(data[i][j], data[i][k]);
            }
        }
    }

    string result = "";
    for (int i = 0; i < 10; ++i) {
        int max = data[i][0];
        int index = 0;
        for (int j = 0; j < 10; ++j) {
            if (data[i][j] >= max) {
                max = data[i][j];
                index = j;
            }
        }
        result += to_string(index);
    }
    input.close();
    return result;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    string m4 = "", m5 = "", m6 = "", m7 = "", m8 = "", m9 = "";
    string result = "";
    m4 = addString(pwd1, pwd2);
    m5 = addString(pwd1, pwd3);
    m6 = addString(pwd2, pwd3);
    m7 = addString(addString(pwd1, pwd2), pwd3);
    m8 = addString(pwd1, addString(pwd2, pwd3));
    m9 = addString(addString(pwd1, pwd2), addString(pwd1, pwd3));
    result = pwd1 + ';' + pwd2 + ';' + pwd3 + ';' + m4 + ';' + m5 + ';' + m6 + ';' + m7 + ';' + m8 + ';' + m9;
    return result;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }
    arr[0][0] = 0;
    int size_move = moves.size();
    int x = 0;
    int y = 0;
    for (int i = 0; i < size_move; i++) {
        if (moves[i] == 'R') {
            if ((y + 1) < 100) {
                y += 1;
                arr[x][y] = arr[x][y - 1] + 9;
            }
        }
        if (moves[i] == 'L') {
            if ((y - 1) >= 0) {
                y -= 1;
                arr[x][y] = arr[x][y + 1] + 9;
            }
        }
        if (moves[i] == 'U') {
            if ((x - 1) >= 0) {
                x -= 1;
                arr[x][y] = arr[x + 1][y] + 9;
            }
        }
        if (moves[i] == 'D') {
            if ((x + 1) < 100) {
                x += 1;
                arr[x][y] = arr[x - 1][y] + 9;
            }
        }
    }

    int prePoint[2];
    Toado Diem[100];
    int pos = 1;
    int SIZE = points.size();
    Diem[0].x = 0;
    Diem[0].y = 0;
    for (int i = 0; i < SIZE; ++i) {
        int count = 0;
        int k = 0;
        if (points[i] == '(') {
            int k = i + 1;
            while (points[i] != ',') {
                ++count;
                ++i;
            }
            --count;
            Diem[pos].x = stoi(points.substr(k, count));
            k = i + 1;
            count = 0;
            while (points[i] != ')') {
                ++count;
                ++i;
            }
            --count;
            Diem[pos].y = stoi(points.substr(k, count));
            ++pos;
        }
    }
    int time = 0;
    bool check = false;
    for (int i = 1; i < pos; ++i) {
        time = time + 14 * (abs(Diem[i].x - Diem[i - 1].x) + abs(Diem[i].y - Diem[i - 1].y));
        if (time <= arr[Diem[i].x][Diem[i].y]) {
            check = true;
            if (i == 1) {
                outCatchUps += 'Y';
                outTimes += to_string(time);
            }
            else {
                outCatchUps += ";Y";
                outTimes += ';' + to_string(time);
            }
            for (int j = i; j < pos - 1; ++j) {
                outTimes += ";-";
                outCatchUps += ";-";
            }
            break;
        }
        else {
            if (i == 1) {
                outCatchUps += "N";
                outTimes += to_string(time);
            }
            else {
                outCatchUps += ";N";
                outTimes += ';' + to_string(time);
            }
        }
    }
    return check;
}

string enterLaptop(string tag, string message) {
    ifstream input(tag);
    input.is_open();
    string temp;
    string email;
    string n3;
    int n;
    getline(input, temp, ' ');
    getline(input, email);
    getline(input, temp, ' ');
    getline(input, n3, ' ');
    n = stoi(n3);
    email += ';';
    for (int i = 0; i < n; ++i) {
        email += message;
    }

    input.close();
    return email;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
