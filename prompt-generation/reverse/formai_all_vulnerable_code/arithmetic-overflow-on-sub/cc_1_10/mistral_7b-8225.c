//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to calculate the number of days in a given month
int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to convert a given date in the format "MM/DD/YYYY" to its corresponding Julian Day Number
int julian_day(int month, int day, int year) {
    int a, y, m;

    y = year;
    m = month;
    a = (15 * (m - 3) / 5) + day;
    day = a + 30 * (m - 2) / 12;

    if (m < 3) {
        y--;
        m += 12;
    }

    a = y / 100;
    day += (a + y / 4 - (a / 400) + 32045) % 7;

    return day;
}

// Main function to read a date from user input and print its Julian Day Number
int main() {
    char input[11];
    int month, day, year;

    printf("Enter a date in the format MM/DD/YYYY: ");
    scanf("%s", input);

    sscanf(input, "%d/%d/%d", &month, &day, &year);

    if (month < 1 || month > 12 || day < 1 || day > days_in_month(month, year)) {
        printf("Invalid date\n");
        return 1;
    }

    printf("Julian Day Number for %02d/%02d/%04d is %d\n", month, day, year, julian_day(month, day, year));

    return 0;
}