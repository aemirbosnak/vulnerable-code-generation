//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the months of the year
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

// Constants for the days of the week
#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

// Function to convert a date from the Gregorian calendar to the Julian calendar
void gregorian_to_julian(int year, int month, int day, int *julian_year, int *julian_month, int *julian_day)
{
    // Calculate the Julian day number
    int julian_day_number = (year * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + (month * 30) + (day - 1);

    // Convert the Julian day number to the Julian calendar date
    *julian_year = (julian_day_number - 1) / 365 + 1;
    *julian_month = ((julian_day_number - 1) % 365) / 30 + 1;
    *julian_day = ((julian_day_number - 1) % 365) % 30 + 1;
}

// Function to convert a date from the Julian calendar to the Gregorian calendar
void julian_to_gregorian(int year, int month, int day, int *gregorian_year, int *gregorian_month, int *gregorian_day)
{
    // Calculate the Gregorian day number
    int gregorian_day_number = (year * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + (month * 30) + (day - 1);

    // Convert the Gregorian day number to the Gregorian calendar date
    *gregorian_year = (gregorian_day_number - 1) / 365 + 1;
    *gregorian_month = ((gregorian_day_number - 1) % 365) / 30 + 1;
    *gregorian_day = ((gregorian_day_number - 1) % 365) % 30 + 1;
}

// Function to print a date in the Gregorian calendar
void print_gregorian_date(int year, int month, int day)
{
    // Print the date in the format YYYY-MM-DD
    printf("%04d-%02d-%02d\n", year, month, day);
}

// Function to print a date in the Julian calendar
void print_julian_date(int year, int month, int day)
{
    // Print the date in the format YYYY-MM-DD
    printf("%04d-%02d-%02d\n", year, month, day);
}

// Main function
int main(void)
{
    // Declare variables to store the Gregorian calendar date
    int gregorian_year, gregorian_month, gregorian_day;

    // Declare variables to store the Julian calendar date
    int julian_year, julian_month, julian_day;

    // Get the Gregorian calendar date from the user
    printf("Enter the Gregorian calendar date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &gregorian_year, &gregorian_month, &gregorian_day);

    // Convert the Gregorian calendar date to the Julian calendar date
    gregorian_to_julian(gregorian_year, gregorian_month, gregorian_day, &julian_year, &julian_month, &julian_day);

    // Print the Julian calendar date
    printf("The Julian calendar date is: ");
    print_julian_date(julian_year, julian_month, julian_day);

    // Convert the Julian calendar date to the Gregorian calendar date
    julian_to_gregorian(julian_year, julian_month, julian_day, &gregorian_year, &gregorian_month, &gregorian_day);

    // Print the Gregorian calendar date
    printf("The Gregorian calendar date is: ");
    print_gregorian_date(gregorian_year, gregorian_month, gregorian_day);

    return 0;
}