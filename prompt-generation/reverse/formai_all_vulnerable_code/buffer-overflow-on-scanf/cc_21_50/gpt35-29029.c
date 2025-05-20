//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>

int main() {
    int day, month, year;
    printf("Enter date in format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    /* Checking if the date is valid or not */
    if (month < 1 || month > 12 || day < 1 || day > 31 ||
       (month == 4 || month == 6 || month == 9 || month == 11) && day == 31 ||
       (month == 2 && (day == 29 && (year % 4 != 0 || year % 100 == 0 && year % 400 != 0))
                    || day > 29)) {
        printf("Invalid date!\n");
        return 0;
    }

    /* Determining the day of the week of the given date */
    int century, year_in_century, day_of_week;
    century = year / 100;
    year_in_century = year % 100;
    switch (month) {
        case 1:
            if (year_in_century == 0) {
                day_of_week = (5 + day + (31 * (month + 10)) / 12 + (5 * (century - 1)) / 4) % 7;
            } else {
                day_of_week = (5 + day + (31 * (month + 10)) / 12 + (5 * century) / 4 + (year_in_century + (year_in_century / 4))) % 7;
            }
            break;
        case 2:
            if (year_in_century == 0) {
                day_of_week = (1 + day + (31 * (month + 10)) / 12 + (5 * (century - 1)) / 4) % 7;
            } else {
                day_of_week = (1 + day + (31 * (month + 10)) / 12 + (5 * century) / 4 + (year_in_century + (year_in_century / 4))) % 7;
            }
            break;
        default:
            if (year_in_century == 0) {
                day_of_week = (day + ((153 * (month + 10)) / 5) - 122 + (5 * (century - 1)) / 4) % 7;
            } else {
                day_of_week = (day + ((153 * (month + 10)) / 5) - 122 + (5 * century) / 4 + (year_in_century + (year_in_century / 4))) % 7;
            }
            break;
    }

    /* Printing the day of the week */
    switch (day_of_week) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }

    return 0;
}