//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if given year is a leap year
int leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to calculate number of days in a given month
int days_in_month(int month, int year) {
    int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leap_year(year) && month == 2) {
        return 29;
    }

    return num_days[month - 1];
}

// Function to convert given date to string representation
void date_to_string(char *date_str, int month, int day, int year) {
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int len = strlen(date_str);

    // Copy first two digits of year
    strncpy(&date_str[len - 4], &((char *) &year)[2], 2);

    // Copy month and day
    sprintf(&date_str[len - 7], "%d %s %d", day, months[month - 1], year);
}

int main() {
    char date_str[11];
    int month, day, year;

    // Input date in "mmddyyyy" format
    printf("Enter date (mmddyyyy): ");
    scanf("%d%d%d", &month, &day, &year);

    // Convert date to string representation
    date_to_string(date_str, month, day, year);

    // Output result
    printf("Date: %s\n", date_str);

    return 0;
}