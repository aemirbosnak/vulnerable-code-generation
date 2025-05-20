//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to convert a month name to its corresponding number
int get_month_number(char* month_name) {
    int month_number;
    if (strcmp(month_name, "January") == 0) {
        month_number = 1;
    } else if (strcmp(month_name, "February") == 0) {
        month_number = 2;
    } else if (strcmp(month_name, "March") == 0) {
        month_number = 3;
    } else if (strcmp(month_name, "April") == 0) {
        month_number = 4;
    } else if (strcmp(month_name, "May") == 0) {
        month_number = 5;
    } else if (strcmp(month_name, "June") == 0) {
        month_number = 6;
    } else if (strcmp(month_name, "July") == 0) {
        month_number = 7;
    } else if (strcmp(month_name, "August") == 0) {
        month_number = 8;
    } else if (strcmp(month_name, "September") == 0) {
        month_number = 9;
    } else if (strcmp(month_name, "October") == 0) {
        month_number = 10;
    } else if (strcmp(month_name, "November") == 0) {
        month_number = 11;
    } else if (strcmp(month_name, "December") == 0) {
        month_number = 12;
    } else {
        month_number = -1;      // Invalid month name
    }
    return month_number;
}

int main() {
    // Take user input
    char input_date[30];
    printf("Enter a date in the format [Month Day Year]: ");
    fgets(input_date, 30, stdin);

    // Extract the month, day and year
    char* month_name = strtok(input_date, " ");
    int day = atoi(strtok(NULL, " "));
    int year = atoi(strtok(NULL, " "));

    // Convert the month name to its corresponding number
    int month_number = get_month_number(month_name);
    if(month_number == -1) {
        printf("Invalid month name. Please enter a valid month.\n");
        return 0;
    }

    // Check if the day is within the valid range for that month and year
    int max_day = -1;
    if(month_number == 2) {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    } else if(month_number == 4 || month_number == 6 || month_number == 9 || month_number == 11) {
        max_day = 30;
    } else {
        max_day = 31;
    }

    if(day < 1 || day > max_day) {
        printf("Invalid day for the given month and year.\n");
        return 0;
    }

    // Print the date in the required format
    printf("The date is %02d-%02d-%d", day, month_number, year);

    return 0;
}