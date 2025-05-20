//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

int main() {

    // Declare necessary variables
    int year, month, day;
    bool leapYear = false;

    // Get user input for date
    printf("Enter a date in format 'yyyy-mm-dd': ");
    scanf("%d-%d-%d", &year, &month, &day);

    // Check for leap year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leapYear = true;
            }
        } else {
            leapYear = true;
        }
    }

    // Validate user input for date
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date entered.");
        return 0;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("Invalid date entered.");
        return 0;
    } else if (month == 2 && leapYear == true) {
        if (day > 29) {
            printf("Invalid date entered.");
            return 0;
        }
    } else if (month == 2 && leapYear == false) {
        if (day > 28) {
            printf("Invalid date entered.");
            return 0;
        }
    }

    // Get user input for time travel
    int yearsToTravel, monthsToTravel, daysToTravel;
    printf("Enter years to travel: ");
    scanf("%d", &yearsToTravel);
    printf("Enter months to travel: ");
    scanf("%d", &monthsToTravel);
    printf("Enter days to travel: ");
    scanf("%d", &daysToTravel);

    // Add time travel to user input date
    day += daysToTravel;
    month += monthsToTravel;
    year += yearsToTravel;

    // Determine maximum days for month after time travel
    int maxDays;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    } else if (month == 2 && leapYear == true) {
        maxDays = 29;
    } else if (month == 2 && leapYear == false) {
        maxDays = 28;
    } else {
        maxDays = 31;
    }

    // Adjust for month overflow
    if (day > maxDays) {
        day -= maxDays;
        month++;
    }

    // Adjust for year overflow
    if (month > 12) {
        month -= 12;
        year++;
    }

    // Print result
    printf("Time travel result: %d-%02d-%02d", year, month, day);

    return 0;
}