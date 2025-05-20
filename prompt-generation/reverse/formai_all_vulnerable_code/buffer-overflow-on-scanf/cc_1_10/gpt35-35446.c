//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int countDays(int day, int month, int year) {
    int days = day;

    for (int i = 1; i < month; i++) {
        days += getDaysInMonth(i, year);
    }

    return days;
}

void convertToDate(int num) {
    int year = 0, month = 0, day = 0, daysInYear = 0;

    while (num > daysInYear) {
        year++;
        daysInYear += isLeapYear(year) ? 366 : 365;
        num -= isLeapYear(year) ? 366 : 365;
    }

    int daysInMonth = 0;

    for (int i = 1; i <= 12; i++) {
        daysInMonth = getDaysInMonth(i, year);

        if (num <= daysInMonth) {
            month = i;
            day = num;
            break;
        }

        num -= daysInMonth;
    }

    printf("The date corresponding to the number %d is %d/%d/%d\n", num+countDays(day, month, year), month, day, year);
}

int main() {
    int num;

    printf("Enter the number of days: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input!\n");
        return 0;
    }

    convertToDate(num);

    return 0;
}