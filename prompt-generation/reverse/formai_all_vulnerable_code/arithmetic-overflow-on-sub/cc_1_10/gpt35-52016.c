//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
// Welcome to the mind-bending world of date conversion!
#include <stdio.h>

// Let's define some constants to make our life easier
#define DAYS_IN_MONTH 30
#define MONTHS_IN_YEAR 12

// This function takes a date in the format dd/mm/yyyy and converts it to the number of days since the year 0
int from_normal_date_to_days(char date[]) {
    int day, month, year, days_since_year_0 = 0;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    for (int y = 0; y < year; y++) {
        if (y % 4 == 0) {
            days_since_year_0 += 366;
        } else {
            days_since_year_0 += 365;
        }
    }
    for (int m = 1; m < month; m++) {
        if (m == 2) {
            if (year % 4 == 0) {
                days_since_year_0 += 29;
            } else {
                days_since_year_0 += 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            days_since_year_0 += 30;
        } else {
            days_since_year_0 += 31;
        }
    }
    days_since_year_0 += day - 1;
    return days_since_year_0;
}

// This function takes a number of days since the year 0 and converts it to the date in the format dd/mm/yyyy
void from_days_to_normal_date(int days_since_year_0) {
    int year = 0, month = 1, day = 1;
    while (days_since_year_0 >= 365) {
        if (year % 4 == 0) {
            days_since_year_0 -= 366;
        } else {
            days_since_year_0 -= 365;
        }
        year++;
    }
    while (days_since_year_0 >= DAYS_IN_MONTH) {
        if (month == 2) {
            if (year % 4 == 0) {
                days_since_year_0 -= 29;
            } else {
                days_since_year_0 -= 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days_since_year_0 -= 30;
        } else {
            days_since_year_0 -= 31;
        }
        month++;
    }
    day += days_since_year_0;
    printf("%02d/%02d/%04d\n", day, month, year);
}

int main() {
    char date[11];
    printf("[Mind-bending Date Converter]\n");
    printf("Enter a date in the format dd/mm/yyyy: ");
    fgets(date, 11, stdin);
    int days_since_year_0 = from_normal_date_to_days(date);
    printf("That's the same as %d days since the year 0.\n", days_since_year_0);
    printf("Enter a number of days since the year 0: ");
    scanf("%d", &days_since_year_0);
    from_days_to_normal_date(days_since_year_0);
    printf("Thanks for using the Mind-bending Date Converter!\n");
    return 0;
}