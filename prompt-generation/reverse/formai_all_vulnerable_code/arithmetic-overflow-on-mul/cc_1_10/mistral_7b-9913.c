//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

// Function to calculate the number of days in a given month
int daysInMonth(int month, int year) {
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Function to calculate the Julian Day Number
int julianDay(int month, int day, int year) {
    int jdn;
    int m, y, k;

    y = year;
    m = month;
    k = day;

    jdn = (k + (153 * m - 457) / 5 + (int)(30601 * y / 100) + (int)(y / 4) + (int)(5 * (y / 100)) - (int)((y / 100) / 4) + 68563);

    if (m < 3 || (m == 3 && k < 22))
        jdn--;

    return jdn;
}

int main() {
    int month, day, year;
    char input[11];

    printf("Enter a date in MM/DD/YYYY format: ");
    scanf("%s", input);

    sscanf(input, "%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        printf("Invalid date. Please try again.\n");
        return 1;
    }

    int jdn = julianDay(month, day, year);
    printf("Julian Day Number for %d/%d/%d is %d.\n", month, day, year, jdn);

    return 0;
}