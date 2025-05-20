//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#define LEN 100

struct tm get_current_time() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int get_month_days(int year, int month) {
    switch(month) {
        case 2:
            if (is_leap_year(year)) {
                return 29;
            }
            else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void convert_date(int day, int month, int year, char* date_str) {
    int i = 0;
    int month_days = get_month_days(year, month);
    if (day > month_days) {
        day = month_days;
    }
    if (month < 1 || month > 12) {
        sprintf(date_str, "Invalid month");
        return;
    }
    if (day < 1 || day > month_days) {
        sprintf(date_str, "Invalid day");
        return;
    }
    if (year < 1000 || year > 9999) {
        sprintf(date_str, "Invalid year");
        return;
    }
    if (month == 2) {
        if (is_leap_year(year)) {
            day++;
        }
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        day++;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        day += 2;
    }
    sprintf(date_str, "%d-%02d-%04d", day, month, year);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    char* input_date_str = (char*)malloc(LEN * sizeof(char));
    char* output_date_str = (char*)malloc(LEN * sizeof(char));
    struct tm current_time = get_current_time();
    int year = current_time.tm_year + 1900;
    int month = current_time.tm_mon + 1;
    int day = current_time.tm_mday;
    sprintf(input_date_str, "%d-%02d-%02d", day, month, year);
    convert_date(day, month, year, output_date_str);
    printf("Input date: %s\n", input_date_str);
    printf("Output date: %s\n", output_date_str);
    free(input_date_str);
    free(output_date_str);
    return 0;
}