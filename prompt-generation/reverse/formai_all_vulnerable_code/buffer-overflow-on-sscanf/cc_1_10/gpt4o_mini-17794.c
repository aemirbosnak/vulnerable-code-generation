//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_DATE_SIZE 50

void parseDate(const char *inputDate, int *day, int *month, int *year);
void convertToDateFormat(int day, int month, int year, char *outputDate);
int isLeapYear(int year);

int main() {
    char input[MAX_INPUT_SIZE];
    char formattedDate[MAX_DATE_SIZE];
    int day = 0, month = 0, year = 0;

    printf("Enter a natural language date (e.g., '15 October 2023'): ");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n");  // Remove newline character

    // Parse the input date
    parseDate(input, &day, &month, &year);
    
    // Handle invalid date
    if (day <= 0 || month <= 0 || year <= 0 || month > 12 || day > 31) {
        printf("Sorry, the provided date is invalid.\n");
        return 1;
    }

    // Convert to formatted date
    convertToDateFormat(day, month, year, formattedDate);
    
    // Output the formatted date
    printf("Formatted date: %s\n", formattedDate);
    
    return 0;
}

void parseDate(const char *inputDate, int *day, int *month, int *year) {
    char monthName[20];
    sscanf(inputDate, "%d %s %d", day, monthName, year);

    if (strcmp(monthName, "January") == 0) *month = 1;
    else if (strcmp(monthName, "February") == 0) *month = 2;
    else if (strcmp(monthName, "March") == 0) *month = 3;
    else if (strcmp(monthName, "April") == 0) *month = 4;
    else if (strcmp(monthName, "May") == 0) *month = 5;
    else if (strcmp(monthName, "June") == 0) *month = 6;
    else if (strcmp(monthName, "July") == 0) *month = 7;
    else if (strcmp(monthName, "August") == 0) *month = 8;
    else if (strcmp(monthName, "September") == 0) *month = 9;
    else if (strcmp(monthName, "October") == 0) *month = 10;
    else if (strcmp(monthName, "November") == 0) *month = 11;
    else if (strcmp(monthName, "December") == 0) *month = 12;
    else *month = 0;  // Invalid month
}

void convertToDateFormat(int day, int month, int year, char *outputDate) {
    // Check for valid day in the month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0-indexed
    if (isLeapYear(year)) daysInMonth[2] = 29; // Check for leap year

    if (day > daysInMonth[month]) {
        strcpy(outputDate, "Invalid day for the specified month.");
        return;
    }

    // Format string: YYYY-MM-DD
    sprintf(outputDate, "%d-%02d-%02d", year, month, day);
}

int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}