//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct tm get_current_time() {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);

    return *timeinfo;
}

char* convert_month(int month) {
    switch(month) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            return "Invalid month";
    }
}

char* convert_day_of_week(int day_of_week) {
    switch(day_of_week) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid day of week";
    }
}

int main() {
    struct tm current_time = get_current_time();
    char* month = convert_month(current_time.tm_mon + 1);
    char* day_of_week = convert_day_of_week(current_time.tm_wday);

    printf("Today is %s, %s %d, %d\n", day_of_week, month, current_time.tm_mday, current_time.tm_year + 1900);

    return 0;
}