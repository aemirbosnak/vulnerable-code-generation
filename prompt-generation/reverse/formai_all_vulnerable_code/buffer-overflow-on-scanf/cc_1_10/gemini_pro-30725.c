//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Converts a date in the format "dd/mm/yyyy" to the number of days since the start of the Gregorian calendar.
int date_to_days(int day, int month, int year) {
    int days = 0;

    // Add the days in the previous months.
    for (int i = 1; i < month; i++) {
        days += 30 + (i % 2 == 0);
    }

    // Add the days in the current month.
    days += day;

    // Add the days in the previous years.
    days += (year - 1) * 365;

    // Add the days in the leap years.
    days += (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

    return days;
}

// Converts a number of days since the start of the Gregorian calendar to a date in the format "dd/mm/yyyy".
void days_to_date(int days, int *day, int *month, int *year) {
    // Remove the days in the previous years.
    *year = days / 365;
    days -= *year * 365;

    // Remove the days in the leap years.
    *year -= days / 146097;
    days -= *year / 146097 * 146097;

    // Remove the days in the previous months.
    for (*month = 1; *month <= 12; (*month)++) {
        int days_in_month = 30 + (*month % 2 == 0);
        if (days < days_in_month) {
            break;
        }
        days -= days_in_month;
    }

    // The remaining days are the day of the month.
    *day = days + 1;
}

int main() {
    // Get the date from the user.
    int day, month, year;
    printf("Enter the date in the format \"dd/mm/yyyy\": ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Convert the date to the number of days since the start of the Gregorian calendar.
    int days = date_to_days(day, month, year);

    // Print the number of days.
    printf("The number of days since the start of the Gregorian calendar is: %d\n", days);

    // Convert the number of days back to a date.
    days_to_date(days, &day, &month, &year);

    // Print the date.
    printf("The date is: %d/%d/%d\n", day, month, year);

    return 0;
}