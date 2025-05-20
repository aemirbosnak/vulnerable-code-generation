//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_DATE_LENGTH 11

/**
 * This program takes a date string in natural language format and
 * converts it to the corresponding numerical format.
 *
 * Example Input: "Today is Wednesday, August 12th, 2020"
 * Example Output: "08-12-2020"
 */

// Function to convert month name to month number
int month_to_number(char* month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    } else {
        return -1;
    }
}

// Function to convert natural language date to numerical date
char* convert_date(char* date) {
    char month[20];
    int day, year;
    char* pch;

    // Find month
    pch = strstr(date, " ");
    pch = strstr(pch+1, " ");
    pch = strstr(pch+1, " ");
    pch = strstr(pch+1, " ");
    sscanf(pch+1, "%s", month);

    // Find day
    pch = strstr(date, ",");
    sscanf(pch+2, "%d", &day);

    // Find year
    pch = strstr(date, ",");
    pch = strstr(pch+1, ",");
    sscanf(pch+2, "%d", &year);

    // Convert month to number
    int month_number = month_to_number(month);

    // Construct numerical date string
    char* numerical_date = (char*) malloc(MAX_DATE_LENGTH * sizeof(char));
    sprintf(numerical_date, "%02d-%02d-%04d", month_number, day, year);
    return numerical_date;
}

int main() {
    // Example input
    char* date = "Today is Wednesday, August 12th, 2020";
    printf("Input: %s\n", date);

    // Convert date
    char* numerical_date = convert_date(date);
    printf("Output: %s\n", numerical_date);

    // Clean up
    free(numerical_date);

    return 0;
}