//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_YEARS 1000

struct Date {
    int year;
    int month;
    int day;
};

void calculate_date(struct Date *date, int years_to_add) {
    int current_year = 1990; // Starting year

    date->year = current_year + years_to_add;

    if (date->year % 4 == 0 && (date->year % 100 != 0 || date->year % 400 == 0)) {
        date->month = 2;
        date->day = 29;
    } else if (date->year % 4 == 0) {
        date->month = 2;
        date->day = 28;
    } else if (date->year % 100 == 0) {
        if (date->year % 400 == 0) {
            date->month = 2;
            date->day = 29;
        } else {
            date->month = 2;
            date->day = 28;
        }
    } else {
        switch (date->year % 100) {
            case 0:
                date->month = 2;
                date->day = 28;
                break;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                date->month = 2;
                date->day = 29;
                break;
            default:
                date->month = 2;
                date->day = 28;
        }
    }

    int leap_year = date->year % 4;

    if (date->month < 3) {
        date->month -= 1;
        current_year--;
    }

    while (date->month < 1 || date->month > 12) {
        int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (leap_year) {
            if (date->month == 2) {
                days_in_month[1] = 29;
            }
        }

        int current_month_days = days_in_month[date->month - 1];

        if (date->day > current_month_days) {
            date->day -= current_month_days;
            date->month--;
        }

        if (date->month < 1) {
            current_year--;
            for (int i = 1; i <= 12; i++) {
                if (current_year % 4 == 0 && (current_year % 100 != 0 || current_year % 400 == 0)) {
                    days_in_month[i - 1] = 29;
                } else {
                    days_in_month[i - 1] = 30;
                }
            }
            date->month = 1;
            date->day += current_year % 4 == 0 ? 1 : 0;
        }
    }
}

int main() {
    int years_to_travel;
    struct Date date;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the number of years you'd like to travel: ");
    scanf("%d", &years_to_travel);

    calculate_date(&date, years_to_travel);

    printf("\nTraveling %d years back in time...\n", years_to_travel);
    printf("The current date is: %d-%02d-%02d\n", date.year, date.month, date.day);

    return 0;
}