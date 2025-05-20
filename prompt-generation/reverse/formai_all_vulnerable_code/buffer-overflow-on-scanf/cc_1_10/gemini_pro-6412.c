//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define months
char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// define days of the week
char *days[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

// define leap year function
int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// define days in month function
int days_in_month(int month, int year) {
    switch (month) {
        case 2:
            // February has 29 days in a leap year
            return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            // April, June, September, and November have 30 days
            return 30;
        default:
            // All other months have 31 days
            return 31;
    }
}

// define day of week function
int day_of_week(int day, int month, int year) {
    int y = year - (month <= 2);
    int m = month <= 2 ? month + 12 : month;
    int c = y / 100;
    int y0 = y - c * 100;
    int d = day;
    int w = (c / 4) - 2 * c + (y0 + y0 / 4) + (m / 4) + d - 1;
    return (w % 7 + 7) % 7;
}

// define date converter function
void date_converter(int day, int month, int year) {
    // check if the date is valid
    if (day < 1 || day > days_in_month(month, year)) {
        printf("Invalid day\n");
        return;
    }
    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return;
    }
    if (year < 1) {
        printf("Invalid year\n");
        return;
    }

    // print the date in the format "Saturday, July 4, 2023"
    printf("%s, %s %d, %d\n",
        days[day_of_week(day, month, year)],
        months[month - 1],
        day,
        year
    );
}

int main() {
    // get the date from the user
    int day, month, year;
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    // convert the date to the format "Saturday, July 4, 2023"
    date_converter(day, month, year);

    return 0;
}