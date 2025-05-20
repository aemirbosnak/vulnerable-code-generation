//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900
#define MAX_MONTH 12
#define MAX_DAY 31
#define MIN_MONTH 1
#define MIN_DAY 1

struct date {
    int year;
    int month;
    int day;
};

int isValidDate(struct date date) {
    if (date.year < MIN_YEAR || date.year > MAX_YEAR) {
        return 0;
    }

    if (date.month < MIN_MONTH || date.month > MAX_MONTH) {
        return 0;
    }

    if (date.day < MIN_DAY || date.day > MAX_DAY) {
        return 0;
    }

    return 1;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        if (year % 4 == 0 && (year % 100!= 0 || year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s yyyy-mm-dd target-year\n", argv[0]);
        return 1;
    }

    struct date startDate, targetDate;
    sscanf(argv[1], "%d-%d-%d", &startDate.year, &startDate.month, &startDate.day);
    sscanf(argv[2], "%d", &targetDate.year);

    if (!isValidDate(startDate) ||!isValidDate(targetDate)) {
        printf("Invalid date format\n");
        return 1;
    }

    time_t startTime, targetTime;
    struct tm startTm, targetTm;

    startTm.tm_year = startDate.year - 1900;
    startTm.tm_mon = startDate.month - 1;
    startTm.tm_mday = startDate.day;
    startTm.tm_hour = 0;
    startTm.tm_min = 0;
    startTm.tm_sec = 0;

    targetTm.tm_year = targetDate.year - 1900;
    targetTm.tm_mon = targetDate.month - 1;
    targetTm.tm_mday = targetDate.day;
    targetTm.tm_hour = 0;
    targetTm.tm_min = 0;
    targetTm.tm_sec = 0;

    startTime = mktime(&startTm);
    targetTime = mktime(&targetTm);

    if (startTime == -1 || targetTime == -1) {
        printf("Invalid date\n");
        return 1;
    }

    int timeDiff = difftime(targetTime, startTime);
    int daysDiff = timeDiff / (24 * 60 * 60);

    printf("Time travel simulation from %d-%d-%d to %d-%d-%d\n", startDate.year, startDate.month, startDate.day, targetDate.year, targetDate.month, targetDate.day);
    printf("Time difference: %d days\n", daysDiff);

    return 0;
}