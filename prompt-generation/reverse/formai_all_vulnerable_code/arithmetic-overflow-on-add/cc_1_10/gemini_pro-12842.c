//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a date from Gregorian to Julian
int gregorian_to_julian(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

// Function to convert a date from Julian to Gregorian
int julian_to_gregorian(int day, int month, int year) {
    int a = year + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (b * 146097) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (d * 1461) / 4;
    int m = (5 * e + 2) / 153;
    int day_of_month = day + (153 * m + 2) / 5 + (d + 1) * 31 - (b * 146097) / 4;
    int month_of_year = m + 3 - 12 * (m / 10);
    int year_of_era = b * 100 + d - 4800 + (m / 10);
    return day_of_month + (month_of_year - 1) * 30 + (year_of_era - 1) * 365 + (year_of_era - 1) / 4 - (year_of_era - 1) / 100 + (year_of_era - 1) / 400;
}

// Function to print the date in a given format
void print_date(int day, int month, int year) {
    printf("%d/%d/%d\n", day, month, year);
}

int main() {
    // Get the date from the user
    int day, month, year;
    printf("Enter the date (day/month/year): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Convert the date from Gregorian to Julian
    int julian_day = gregorian_to_julian(day, month, year);

    // Convert the date from Julian to Gregorian
    int gregorian_day = julian_to_gregorian(julian_day, month, year);

    // Print the dates in the Gregorian and Julian calendars
    printf("Gregorian date: ");
    print_date(day, month, year);
    printf("Julian date: ");
    print_date(julian_day, month, year);

    return 0;
}