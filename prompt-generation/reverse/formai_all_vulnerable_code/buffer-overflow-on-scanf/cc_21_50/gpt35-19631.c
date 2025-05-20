//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day, year, month, totalDays;

    printf("Enter date in natural language (e.g., September 7, 2021): ");
    scanf("%*s %d, %d", &day, &year);

    char monthStr[10];
    scanf("%s", monthStr);

    // convert monthStr to month number
    if(strcmp(monthStr, "January") == 0) {
        month = 1;
    } else if(strcmp(monthStr, "February") == 0) {
        month = 2;
    } else if(strcmp(monthStr, "March") == 0) {
        month = 3;
    } else if(strcmp(monthStr, "April") == 0) {
        month = 4;
    } else if(strcmp(monthStr, "May") == 0) {
        month = 5;
    } else if(strcmp(monthStr, "June") == 0) {
        month = 6;
    } else if(strcmp(monthStr, "July") == 0) {
        month = 7;
    } else if(strcmp(monthStr, "August") == 0) {
        month = 8;
    } else if(strcmp(monthStr, "September") == 0) {
        month = 9;
    } else if(strcmp(monthStr, "October") == 0) {
        month = 10;
    } else if(strcmp(monthStr, "November") == 0) {
        month = 11;
    } else if(strcmp(monthStr, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month\n");
        exit(1);
    }

    // calculate total number of days from Jan 1 to current date
    totalDays = 0;
    for(int i = 1; i < month; i++) {
        if(i == 2) {
            totalDays += 28;
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                totalDays += 1; // leap year
            }
        } else if(i == 4 || i == 6 || i == 9 || i == 11) {
            totalDays += 30;
        } else {
            totalDays += 31;
        }
    }
    totalDays += day;

    // print result
    printf("The date %s %d, %d is day %d of the year %d\n", monthStr, day, year, totalDays, year);

    return 0;
}