//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Day, Month, and Year structure
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to convert Gregorian Date to Julian Day Number
int toJulianDay(Date gregorianDate) {
    int a = (14 - gregorianDate.month) / 12;
    int y = gregorianDate.year + 4800 - a;
    int m = gregorianDate.month + 12*a - 3;
    int julianDay = gregorianDate.day + (153*m + 2)/5 + y*365 + y/4 - y/100 + y/400 - 32045;
    return julianDay;
}

// Function to convert Julian Day Number to Gregorian Date
Date toGregorianDate(int julianDay) {
    int a, b, c, d, e, m, day, month, year;
    int f = julianDay + 1401 + (((4*julianDay + 274277)/146097)*3)/4 - 38;
    int g = f/1461;
    e = (4*f - 87 - 4*g)/4;
    d = 5*e + 2;
    c = (d%153)/5 + 1;
    b = (d/153 + 2)%12 + 1;
    a = g - 4716 + (14 - b)/12;
    year = a;
    month = b;
    day = c;
    Date gregorianDate = {day, month, year};
    return gregorianDate;
}

int main() {
    int choice;
    printf("Date Converter Menu\n");
    printf("1. Convert Julian Day Number to Gregorian Date\n");
    printf("2. Convert Gregorian Date to Julian Day Number\n");
    printf("Please enter your choice (1/2): ");
    scanf("%d", &choice);
    if(choice == 1) {
        int julianDay;
        printf("Enter Julian Day Number: ");
        scanf("%d", &julianDay);
        Date gregorianDate = toGregorianDate(julianDay);
        printf("Gregorian Date: %d/%d/%d\n", gregorianDate.day, gregorianDate.month, gregorianDate.year);
    } else if(choice == 2) {
        Date gregorianDate;
        printf("Enter Gregorian Date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &gregorianDate.day, &gregorianDate.month, &gregorianDate.year);
        int julianDay = toJulianDay(gregorianDate);
        printf("Julian Day Number: %d\n", julianDay);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    return 0;
}