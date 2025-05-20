//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

char* monthToString(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid Month";
    }
}

char* dayToString(int day) {
    switch (day) {
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
        case 7:
            return "Sunday";
        default:
            return "Invalid Day";
    }
}

int main() {
    time_t now = time(NULL);
    struct tm* currentTime = localtime(&now);
    Date today;
    today.day = currentTime->tm_mday;
    today.month = currentTime->tm_mon + 1;
    today.year = currentTime->tm_year + 1900;
    printf("Today is %s, %s %d, %d\n", dayToString(today.day), monthToString(today.month), today.day, today.year);
    return 0;
}