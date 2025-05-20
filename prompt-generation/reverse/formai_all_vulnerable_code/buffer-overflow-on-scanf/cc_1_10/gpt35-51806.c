//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getYear() {
    int year;
    printf("Enter the year of your choice: ");
    scanf("%d", &year);
    return year;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int getMonth() {
    int month;
    printf("Enter the month of your choice: ");
    scanf("%d", &month);
    return month;
}

int getDay(int year, int month) {
    int day;
    if (month == 2) {
        if (isLeapYear(year)) {
            day = 29;
        } else {
            day = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        day = 30;
    } else {
        day = 31;
    }
    printf("Enter the day of your choice (1 - %d): ", day);
    scanf("%d", &day);
    return day;
}

void travel(int day, int month, int year) {
    int daysOfMonth = getDay(year, month);

    if (day > daysOfMonth || day < 1) {
        printf("Invalid day entered for the month of your choice.");
        return;
    }

    printf("You have chosen to travel to the date: %d/%d/%d", day, month, year);

    int days = day;
    for (int i = 1; i < month; i++) {
        days += getDay(year, i);
    }

    if (days > 365 && !isLeapYear(year)) {
        printf("\nThis year does not have enough days for your selected date.");
        return;
    } else if (days > 366) {
        printf("\nInvalid date! Please enter a date between January 1st, %d and December 31st, %d.", year, year+1);
        return;
    }

    char direction;
    printf("\nDo you want to travel forward or backward in time? (F/B): ");
    scanf(" %c", &direction);

    int years;
    printf("Enter the number of years you wish to travel: ");
    scanf("%d", &years);

    int newDay, newMonth, newYear;
    if (direction == 'F') {
        newDay = (days + years*365 + (years/4) - (years/100) + (years/400)) % 365;
        newMonth = 1;
        while (newDay > getDay(year+newYear, newMonth)) {
            newDay -= getDay(year+newYear, newMonth++);
        }
        newMonth += month-1 + ((days + years*365 + (years/4) - (years/100) + (years/400)) / 365);
        newYear = year + ((days + years*365 + (years/4) - (years/100) + (years/400)) / 365);
    } else if (direction == 'B') {
        newDay = (days - years*365 - (years/4) + (years/100) - (years/400) + 365) % 365;
        newMonth = 12;
        while (newDay > getDay(year-newYear, newMonth)) {
            newDay -= getDay(year-newYear, newMonth--);
        }
        newMonth -= ((days - years*365 - (years/4) + (years/100) - (years/400) + 365) / 365);
        newYear = year - ((days - years*365 - (years/4) + (years/100) - (years/400) + 365) / 365);
    } else {
        printf("Invalid direction entered. Please enter F or B.");
        return;
    }

    printf("\n\nYou have successfully traveled to: %d/%d/%d", newDay, newMonth, newYear);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("This program simulates time travel.\n");

    int year = getYear();
    int month = getMonth();
    int day = getDay(year, month);

    travel(day, month, year);

    return 0;
}