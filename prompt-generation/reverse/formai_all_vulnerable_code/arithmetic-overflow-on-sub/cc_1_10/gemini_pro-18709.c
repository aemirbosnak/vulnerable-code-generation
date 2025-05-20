//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the struct for a date
typedef struct date {
    int day;
    int month;
    int year;
} date;

// Define the function to convert a date to a number of days
int date_to_days(date d) {
    int days = d.day;

    // Add the number of days in each month leading up to the current month
    for (int i = 1; i < d.month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 2:
                if (d.year % 4 == 0 && (d.year % 100 != 0 || d.year % 400 == 0)) {
                    days += 29;
                } else {
                    days += 28;
                }
                break;
            default:
                days += 30;
                break;
        }
    }

    // Add the number of days in the years leading up to the current year
    days += (d.year - 1) * 365;

    // Add the number of days in the leap years leading up to the current year
    days += (d.year - 1) / 4 - (d.year - 1) / 100 + (d.year - 1) / 400;

    return days;
}

// Define the main function
int main() {
    // Get the input date from the user
    date d;
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d.day, &d.month, &d.year);

    // Convert the date to a number of days
    int days = date_to_days(d);

    // Print the number of days
    printf("The date %d/%d/%d is equivalent to %d days.\n", d.day, d.month, d.year, days);

    return 0;
}