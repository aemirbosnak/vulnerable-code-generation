//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given year is a leap year or not
int is_leap_year(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

// Function to get the number of days in a month for the given year and month
int get_days_in_month(int year, int month) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_in_month[month - 1];
}

// Function to convert a date in natural language format to a standard date format (YYYY-MM-DD)
void convert_date(char *input_date) {
    int year, month, day;
    char month_str[10];
    sscanf(input_date, "%s %d, %d", month_str, &day, &year);
    if (strcmp(month_str, "January") == 0) {
        month = 1;
    } else if (strcmp(month_str, "February") == 0) {
        month = 2;
    } else if (strcmp(month_str, "March") == 0) {
        month = 3;
    } else if (strcmp(month_str, "April") == 0) {
        month = 4;
    } else if (strcmp(month_str, "May") == 0) {
        month = 5;
    } else if (strcmp(month_str, "June") == 0) {
        month = 6;
    } else if (strcmp(month_str, "July") == 0) {
        month = 7;
    } else if (strcmp(month_str, "August") == 0) {
        month = 8;
    } else if (strcmp(month_str, "September") == 0) {
        month = 9;
    } else if (strcmp(month_str, "October") == 0) {
        month = 10;
    } else if (strcmp(month_str, "November") == 0) {
        month = 11;
    } else if (strcmp(month_str, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month.\n");
        return;
    }
    if (day <= 0 || day > get_days_in_month(year, month)) {
        printf("Invalid day.\n");
        return;
    }
    printf("%d-%02d-%02d\n", year, month, day);
}

int main() {
    char input_date[50];
    printf("Enter a date in natural language format (e.g. January 1, 2022): ");
    fgets(input_date, 50, stdin);
    input_date[strlen(input_date) - 1] = '\0'; // Remove the newline character
    convert_date(input_date);
    return 0;
}