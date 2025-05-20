//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

void convertToDate(int dayOfYear, int year);
void convertToDay(int month, int day, int year);

int main() {
    int choice;
    printf("Welcome to the CNL Date Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert day of year to date\n");
    printf("2. Convert date to day of year\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int doy, year;
            printf("Enter day of year and year: ");
            scanf("%d %d", &doy, &year);
            convertToDate(doy, year);
            break;
        }
        case 2: {
            int month, day, year;
            printf("Enter month, day, and year: ");
            scanf("%d %d %d", &month, &day, &year);
            convertToDay(month, day, year);
            break;
        }
        default: {
            printf("Invalid choice! Try again.\n");
            break;
        }
    }

    return 0;
}

void convertToDate(int dayOfYear, int year) {
    int month, day, maxDays = 365;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        maxDays = 366;
    }
    if(dayOfYear < 1 || dayOfYear > maxDays) {
        printf("Invalid day of year! Try again.\n");
        return;
    }
    if(maxDays == 366 && dayOfYear == 366) {
        month = DEC;
        day = 31;
        printf("Day %d of %d is %02d/%02d/%d.\n", dayOfYear, year, month, day, year);
        return;
    }
    if(dayOfYear <= 31) {
        month = JAN;
        day = dayOfYear;
    } else if(dayOfYear <= 59 + (maxDays == 366)) {
        month = FEB;
        day = dayOfYear - 31;
    } else if(dayOfYear <= 90 + (maxDays == 366)) {
        month = MAR;
        day = dayOfYear - 59 - (maxDays == 366);
    } else if(dayOfYear <= 120 + (maxDays == 366)) {
        month = APR;
        day = dayOfYear - 90 - (maxDays == 366);
    } else if(dayOfYear <= 151 + (maxDays == 366)) {
        month = MAY;
        day = dayOfYear - 120 - (maxDays == 366);
    } else if(dayOfYear <= 181 + (maxDays == 366)) {
        month = JUN;
        day = dayOfYear - 151 - (maxDays == 366);
    } else if(dayOfYear <= 212 + (maxDays == 366)) {
        month = JUL;
        day = dayOfYear - 181 - (maxDays == 366);
    } else if(dayOfYear <= 243 + (maxDays == 366)) {
        month = AUG;
        day = dayOfYear - 212 - (maxDays == 366);
    } else if(dayOfYear <= 273 + (maxDays == 366)) {
        month = SEP;
        day = dayOfYear - 243 - (maxDays == 366);
    } else if(dayOfYear <= 304 + (maxDays == 366)) {
        month = OCT;
        day = dayOfYear - 273 - (maxDays == 366);
    } else if(dayOfYear <= 334 + (maxDays == 366)) {
        month = NOV;
        day = dayOfYear - 304 - (maxDays == 366);
    } else {
        month = DEC;
        day = dayOfYear - 334 - (maxDays == 366);
    }
    printf("Day %d of %d is %02d/%02d/%d.\n", dayOfYear, year, month, day, year);
}

void convertToDay(int month, int day, int year) {
    int dayOfYear = 0, i, maxDays = 365;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        maxDays = 366;
    }
    if(month < 1 || month > 12) {
        printf("Invalid month! Try again.\n");
        return;
    }
    if(day < 1 || day > 31) {
        printf("Invalid day! Try again.\n");
        return;
    }
    if((month == APR || month == JUN || month == SEP || month == NOV) && day == 31) {
        printf("Invalid day! Try again.\n");
        return;
    }
    if(month == FEB && day == 29 && maxDays == 365) {
        printf("Invalid day! Try again.\n");
        return;
    }
    for(i = 1; i < month; i++) {
        if(i == APR || i == JUN || i == SEP || i == NOV) {
            dayOfYear += 30;
        } else if(i == FEB) {
            dayOfYear += 28 + (maxDays == 366);
        } else {
            dayOfYear += 31;
        }
    }
    dayOfYear += day;
    printf("%02d/%02d/%d is day %d of %d.\n", month, day, year, dayOfYear, year);
}