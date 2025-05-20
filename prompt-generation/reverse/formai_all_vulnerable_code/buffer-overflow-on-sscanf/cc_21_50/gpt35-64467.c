//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to the Medieval Date Converter!\n");
    printf("Please enter the date in the following format: 'May xx, xxxx' where xx is the day and xxxx is the year:\n");

    char input[100];
    fgets(input, 100, stdin);

    char month[10];
    int day;
    int year;

    sscanf(input, "%s %d, %d", month, &day, &year);

    // convert month to lowercase for easier matching
    for (int i = 0; month[i]; i++) {
        month[i] = tolower(month[i]);
    }

    // determine the month number based on the input
    int month_num;
    if (strcmp(month, "january") == 0) {
        month_num = 1;
    } else if (strcmp(month, "february") == 0) {
        month_num = 2;
    } else if (strcmp(month, "march") == 0) {
        month_num = 3;
    } else if (strcmp(month, "april") == 0) {
        month_num = 4;
    } else if (strcmp(month, "may") == 0) {
        month_num = 5;
    } else if (strcmp(month, "june") == 0) {
        month_num = 6;
    } else if (strcmp(month, "july") == 0) {
        month_num = 7;
    } else if (strcmp(month, "august") == 0) {
        month_num = 8;
    } else if (strcmp(month, "september") == 0) {
        month_num = 9;
    } else if (strcmp(month, "october") == 0) {
        month_num = 10;
    } else if (strcmp(month, "november") == 0) {
        month_num = 11;
    } else if (strcmp(month, "december") == 0) {
        month_num = 12;
    } else {
        printf("Error: Invalid month entered!\n");
        exit(1);
    }

    // check for leap year so we know whether to subtract 1 from the total days
    bool is_leap_year = false;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                is_leap_year = true;
            }
        } else {
            is_leap_year = true;
        }
    }

    // calculate the total days up to this point in the year
    int total_days = 0;
    switch (month_num) {
        case 12: total_days += 30; // November
        case 11: total_days += 31; // October
        case 10: total_days += 30; // September
        case 9: total_days += 31; // August
        case 8: total_days += 31; // July
        case 7: total_days += 30; // June
        case 6: total_days += 31; // May
        case 5: total_days += 30; // April
        case 4: total_days += 31; // March
        case 3: total_days += is_leap_year ? 29 : 28; // February
        case 2: total_days += 31; // January
        case 1: total_days += day;
    }

    // output the result
    printf("The date you entered is equivalent to day %d in the year %d.\n", total_days, year);

    return 0;
}