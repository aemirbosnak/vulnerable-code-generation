//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int month_in_days [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int check_leap_year(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int days_in_month(int year, int month) {
    int days = month_in_days[month];
    if (month == 1 && check_leap_year(year))
        days++;
    return days;
}

void increment_date(int *year, int *month, int *day) {
    (*day)++;
    if (*day > days_in_month(*year, *month)) {
        (*day) = 1;
        (*month)++;
        if (*month >= 12) {
            (*month) = 0;
            (*year)++;
        }
    }
}

void convert_date(char *date_str) {
    int year, month, day;
    sscanf(date_str, "%d%*c%d%*c%d", &year, &month, &day);
    printf("\nInput date: %s\n", date_str);
    printf("Output date: %s %d, %d\n", month_names[month], day, year);

    // loop for next 7 days.
    for (int i = 0; i < 7; i++) {
        increment_date(&year, &month, &day);
        printf("Next date %d: %s %d, %d\n", i+1, month_names[month], day, year);
    }
}

int main(void) {
    char date_str[10];
    printf("Enter a date (yyyy-mm-dd): ");
    scanf("%s", date_str);
    convert_date(date_str);
    return 0;
}