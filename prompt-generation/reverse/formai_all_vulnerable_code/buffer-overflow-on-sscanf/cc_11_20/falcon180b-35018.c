//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char month[MAX_STRING_LENGTH];
    int day;
    int year;
} Date;

int main() {
    Date date;
    char input[MAX_STRING_LENGTH];
    char month_str[MAX_STRING_LENGTH];
    int day, year;

    // Prompt the user to enter the date in natural language format
    printf("Enter the date (e.g. \"January 1, 2022\"): ");
    fgets(input, MAX_STRING_LENGTH, stdin);

    // Parse the input string to extract the month, day, and year
    sscanf(input, "%s %d, %d", month_str, &day, &year);

    // Convert the month string to a number
    if (strcmp(month_str, "January") == 0) {
        date.month[0] = '0';
        strcat(date.month, "1");
    } else if (strcmp(month_str, "February") == 0) {
        date.month[0] = '0';
        strcat(date.month, "2");
    } else if (strcmp(month_str, "March") == 0) {
        date.month[0] = '0';
        strcat(date.month, "3");
    } else if (strcmp(month_str, "April") == 0) {
        date.month[0] = '0';
        strcat(date.month, "4");
    } else if (strcmp(month_str, "May") == 0) {
        date.month[0] = '0';
        strcat(date.month, "5");
    } else if (strcmp(month_str, "June") == 0) {
        date.month[0] = '0';
        strcat(date.month, "6");
    } else if (strcmp(month_str, "July") == 0) {
        date.month[0] = '0';
        strcat(date.month, "7");
    } else if (strcmp(month_str, "August") == 0) {
        date.month[0] = '0';
        strcat(date.month, "8");
    } else if (strcmp(month_str, "September") == 0) {
        date.month[0] = '0';
        strcat(date.month, "9");
    } else if (strcmp(month_str, "October") == 0) {
        date.month[0] = '0';
        strcat(date.month, "10");
    } else if (strcmp(month_str, "November") == 0) {
        date.month[0] = '0';
        strcat(date.month, "11");
    } else if (strcmp(month_str, "December") == 0) {
        date.month[0] = '0';
        strcat(date.month, "12");
    } else {
        printf("Invalid month!\n");
        return 1;
    }

    // Convert the day and year to integers
    date.day = day;
    date.year = year;

    // Print the date in natural language format
    printf("The date is %s %d, %d.\n", date.month, date.day, date.year);

    return 0;
}