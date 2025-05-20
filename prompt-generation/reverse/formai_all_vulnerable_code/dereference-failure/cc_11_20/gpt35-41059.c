//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char date[50];
    int day, month, year;
    printf("Enter a date in natural language format (e.g. January 1st, 2022): ");
    fgets(date, sizeof(date), stdin);

    // Remove the newline character from the string
    date[strcspn(date, "\n")] = 0;

    // Convert month to a number
    char *month_str = strtok(date, " ");
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
        printf("Invalid month\n");
        return 1;
    }

    // Get the day and year
    char *day_str = strtok(NULL, ",");
    char *year_str = strtok(NULL, " ");
    day = atoi(day_str + 1);
    year = atoi(year_str);

    // Print in yyyy/mm/dd format
    printf("The date in yyyy/mm/dd format is: %04d/%02d/%02d", year, month, day);

    return 0;
}