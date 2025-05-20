//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void convert_date(int day, int month, int year) {
    char weekday[10];
    char month_name[10];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(weekday, 10, "%A", t);
    strftime(month_name, 10, "%B", t);
    printf("Today is %s, %d %s %d\n", weekday, day, month_name, year);
}

int main() {
    int day, month, year;
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    // Convert the input to a valid date format
    if (day < 1 || day > 31) {
        printf("Invalid day!\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }

    // Check for leap year
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        if (month == 2) {
            if (day < 1 || day > 29) {
                printf("Invalid day!\n");
                return 1;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day < 1 || day > 30) {
                printf("Invalid day!\n");
                return 1;
            }
        } else {
            if (day < 1 || day > 31) {
                printf("Invalid day!\n");
                return 1;
            }
        }
    } else {
        if (month == 2) {
            if (day < 1 || day > 28) {
                printf("Invalid day!\n");
                return 1;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day < 1 || day > 30) {
                printf("Invalid day!\n");
                return 1;
            }
        } else {
            if (day < 1 || day > 31) {
                printf("Invalid day!\n");
                return 1;
            }
        }
    }

    // Convert the valid date to a natural language format
    convert_date(day, month, year);

    return 0;
}