//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31

struct Date {
    int year;
    int month;
    int day;
};

void printDate(struct Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

int isValidDate(struct Date date) {
    if (date.year < 1000 || date.year > MAX_YEAR) {
        return 0;
    }
    if (date.month < 1 || date.month > MAX_MONTH) {
        return 0;
    }
    if (date.day < 1 || date.day > MAX_DAY) {
        return 0;
    }
    return 1;
}

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
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

int main() {
    int targetYear, targetMonth, targetDay;
    struct Date currentDate, targetDate;
    time_t now;

    time(&now);
    currentDate.year = 1900 + (now % 40000) / 365.25;
    currentDate.month = 1;
    currentDate.day = 1;

    printf("Current date: ");
    printDate(currentDate);

    printf("Enter target date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &targetYear, &targetMonth, &targetDay);

    targetDate.year = targetYear;
    targetDate.month = targetMonth;
    targetDate.day = targetDay;

    if (!isValidDate(targetDate)) {
        printf("Invalid date.\n");
        return 1;
    }

    int daysLeft = (targetDate.year - currentDate.year) * 365 +
                   (targetDate.month - currentDate.month) * daysInMonth(currentDate.month, currentDate.year) +
                   (targetDate.day - currentDate.day);

    printf("Number of days left until target date: %d\n", daysLeft);

    return 0;
}