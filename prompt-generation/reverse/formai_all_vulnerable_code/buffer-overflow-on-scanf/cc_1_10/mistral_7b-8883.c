//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS_IN_MONTH 31
#define FEBRUARY_EXTRA_DAYS 1

int isLeapYear(int year) {
    if (year % 4 != 0) return 0;
    if (year % 100 != 0) return 1;
    if (year % 400 != 0) return 0;
    return 1;
}

int main(void) {
    int day, month, year, days_in_month[13] = {0, 31, 28 + FEBRUARY_EXTRA_DAYS, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *months[] = {"the wolf of the moon", "the lamb of the spring", "the budding flower", "the singing bird", "the longing heart", "the radiant rose", "the harvest moon", "the vintage wine", "the autumn leaf", "the quiet storm", "the winter's chill", "the end of the year"};
    int target_day;

    printf("Enter a day, month and year in the following format: day month year\n");
    printf("For example: 22 March 2022\n");
    printf("Enter 0 to exit\n");

    while (1) {
        scanf("%d %s %d", &day, months, &year);

        if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (day > days_in_month[month] && isLeapYear(year)) {
            days_in_month[month] += FEBRUARY_EXTRA_DAYS;
        }

        if (day > days_in_month[month]) {
            printf("The entered day is greater than the number of days in the entered month.\n");
            continue;
        }

        target_day = day;
        int total_days = 0;

        for (int i = 0; i < month - 1; i++) {
            total_days += days_in_month[i];
        }

        total_days += day;

        if (isLeapYear(year) && month > 2) {
            total_days++;
        }

        printf("You entered the date: %s %d, %d\n", months[month - 1], day, year);
        printf("The total number of days elapsed since the beginning of the year is: %d\n", total_days);
        printf("Enter the next date or 0 to exit\n");

        scanf("%d %s %d", &day, months, &year);
    }

    return EXIT_SUCCESS;
}