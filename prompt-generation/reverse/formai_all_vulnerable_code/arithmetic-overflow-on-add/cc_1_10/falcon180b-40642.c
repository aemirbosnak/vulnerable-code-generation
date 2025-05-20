//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 20
#define DAYS_IN_WEEK 7
#define MONTHS_IN_YEAR 12

// Function to check if a string is a valid date
int is_valid_date(char* date) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    return!mktime(&tm);
}

// Function to convert a given date to natural language
void convert_date_to_string(char* date, char* result) {
    struct tm tm;
    strptime(date, "%d/%m/%Y", &tm);
    strftime(result, MAX_DATE_LENGTH, "%A, %d %B %Y", &tm);
}

// Main function
int main() {
    char date[MAX_DATE_LENGTH];
    char result[MAX_DATE_LENGTH];
    int month, day, year;

    // Get the current date
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    month = current_time->tm_mon + 1;
    day = current_time->tm_mday;
    year = current_time->tm_year + 1900;

    // Get the date from the user
    printf("Enter a date (DD/MM/YYYY): ");
    scanf("%s", date);

    // Validate the date
    if (is_valid_date(date)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Convert the date to natural language
    convert_date_to_string(date, result);
    printf("The natural language representation of %s is %s.\n", date, result);

    return 0;
}