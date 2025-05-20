//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int isLeapYear(int year);
void gregorianToJulian(int day, int month, int year);
void julianToGregorian(int day, int month, int year);

int main() {
    int day, month, year, choice;

    printf("Welcome to the Natural Language Date Converter\n");
    printf("Choose the operation you would like to perform:\n");
    printf("1. Convert Gregorian Date to Julian Date\n");
    printf("2. Convert Julian Date to Gregorian Date\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the Gregorian Date (DD MM YYYY): ");
        scanf("%d %d %d", &day, &month, &year);
        gregorianToJulian(day, month, year);
    } else if (choice == 2) {
        printf("Enter the Julian Date (DD MM YYYY): ");
        scanf("%d %d %d", &day, &month, &year);
        julianToGregorian(day, month, year);
    } else {
        printf("Invalid choice! Please restart the program.\n");
    }

    return 0;
}

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to convert Gregorian date to Julian date
void gregorianToJulian(int day, int month, int year) {
    if (month < 3) {
        year--;
        month += 12;
    }

    int julianDay = day + ((153 * (month + 1)) / 5) + 365 * year + (year / 4) - (year / 100) + (year / 400) - 32045;

    printf("The Julian date is: %d\n", julianDay);
}

// Function to convert Julian date to Gregorian date
void julianToGregorian(int day, int month, int year) {
    int julianDay = day + (153 * (month + 1)) / 5 + 365 * year + (year / 4) - 32083;

    int temp = julianDay + 32044;
    int g = temp / 146097;
    int dg = temp % 146097;
    int c = (dg / 36524 + 1) * 3 / 4;
    int dc = dg - c * 36524;
    int b = dc / 1461;
    int db = dc % 1461;
    int a = (db / 365 + 1);
    int d = db - (365 * (a - 1));

    int monthNum = (d * 5 + 2) / 153;
    int dayNum = d - (153 * monthNum + 2) / 5 + 1;

    int monthGregorian = monthNum + 3 - 12 * (monthNum / 10);
    int yearGregorian = g * 400 + c * 100 + b * 4 + a - 2800;

    printf("The Gregorian date is: %02d/%02d/%04d\n", dayNum, monthGregorian, yearGregorian);
}