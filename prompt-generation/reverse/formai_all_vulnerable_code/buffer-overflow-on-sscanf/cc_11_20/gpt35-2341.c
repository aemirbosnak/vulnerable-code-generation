//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Natural Language Date Converter\n");
    printf("Please enter a date in natural language (mm/dd/yyyy):\n");

    char input[50];
    fgets(input, 50, stdin);

    char month[10];
    char day[3];
    char year[5];

    sscanf(input, "%s %s %s", month, day, year);

    // Convert month to number
    int monthNum = 0;
    if (strcmp(month, "January") == 0) {
        monthNum = 1;
    } else if (strcmp(month, "February") == 0) {
        monthNum = 2;
    } else if (strcmp(month, "March") == 0) {
        monthNum = 3;
    } else if (strcmp(month, "April") == 0) {
        monthNum = 4;
    } else if (strcmp(month, "May") == 0) {
        monthNum = 5;
    } else if (strcmp(month, "June") == 0) {
        monthNum = 6;
    } else if (strcmp(month, "July") == 0) {
        monthNum = 7;
    } else if (strcmp(month, "August") == 0) {
        monthNum = 8;
    } else if (strcmp(month, "September") == 0) {
        monthNum = 9;
    } else if (strcmp(month, "October") == 0) {
        monthNum = 10;
    } else if (strcmp(month, "November") == 0) {
        monthNum = 11;
    } else if (strcmp(month, "December") == 0) {
        monthNum = 12;
    } else {
        printf("Invalid month\n");
        return 0;
    }

    // Convert day to number
    int dayNum = atoi(day);
    if (dayNum < 1 || dayNum > 31) {
        printf("Invalid day\n");
        return 0;
    }

    // Convert year to number
    int yearNum = atoi(year);
    if (yearNum < 1000 || yearNum > 9999) {
        printf("Invalid year\n");
        return 0;
    }

    printf("The date in mm/dd/yyyy format is: %02d/%02d/%04d\n", monthNum, dayNum, yearNum);

    return 0;
}