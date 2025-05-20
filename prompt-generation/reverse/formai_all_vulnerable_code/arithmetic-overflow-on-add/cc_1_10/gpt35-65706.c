//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

DateTime getCurrentDateTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    DateTime dt;
    dt.year = tm.tm_year + 1900;
    dt.month = tm.tm_mon + 1;
    dt.day = tm.tm_mday;
    dt.hour = tm.tm_hour;
    dt.minute = tm.tm_min;
    dt.second = tm.tm_sec;
    return dt;
}

void printDateTime(DateTime dt) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

DateTime timeTravel(DateTime currentDateTime, int years, int months, int days, int hours, int minutes, int seconds) {
    currentDateTime.second += seconds;
    currentDateTime.minute += minutes;
    currentDateTime.hour += hours;
    currentDateTime.day += days;

    while (currentDateTime.day > 31 || (currentDateTime.month == 2 && currentDateTime.day > 28) || (currentDateTime.day > 30 && (currentDateTime.month == 4 || currentDateTime.month == 6 || currentDateTime.month == 9 || currentDateTime.month == 11))) {
        if (currentDateTime.month == 2) {
            if (currentDateTime.year % 4 == 0 && (currentDateTime.year % 100 != 0 || currentDateTime.year % 400 == 0)) {
                if (currentDateTime.day > 29) {
                    currentDateTime.day -= 29;
                    currentDateTime.month++;
                } else {
                    break;
                }
            } else {
                if (currentDateTime.day > 28) {
                    currentDateTime.day -= 28;
                    currentDateTime.month++;
                } else {
                    break;
                }
            }
        } else {
            if (currentDateTime.day > 30) {
                currentDateTime.day -= 30;
                currentDateTime.month++;
            } else {
                break;
            }
        }
    }

    currentDateTime.month += months;
    while (currentDateTime.month > 12) {
        currentDateTime.month -= 12;
        currentDateTime.year++;
    }

    currentDateTime.year += years;
    return currentDateTime;
}

int main() {
    DateTime currentDateTime = getCurrentDateTime();

    printf("Current Date and Time:\n");
    printDateTime(currentDateTime);

    // Travel to 1 year, 2 months, 3 days, 4 hours, 5 minutes, and 6 seconds into the future
    currentDateTime = timeTravel(currentDateTime, 1, 2, 3, 4, 5, 6);

    printf("Travelled 1 year, 2 months, 3 days, 4 hours, 5 minutes, and 6 seconds into the future:\n");
    printDateTime(currentDateTime);

    // Travel to 5 years, 0 months, 0 days, 0 hours, 0 minutes, and 0 seconds into the past
    currentDateTime = timeTravel(currentDateTime, -5, 0, 0, 0, 0, 0);

    printf("Travelled 5 years into the past:\n");
    printDateTime(currentDateTime);

    return 0;
}