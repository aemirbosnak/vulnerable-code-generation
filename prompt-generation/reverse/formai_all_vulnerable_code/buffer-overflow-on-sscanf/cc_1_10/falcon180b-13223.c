//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a valid date
bool isValidDate(char *date) {
    int day, month, year;
    if (sscanf(date, "%d-%d-%d", &day, &month, &year)!= 3)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (year < 1000 || year > 9999)
        return false;
    return true;
}

// Function to convert a date string to a timestamp
time_t stringToTimestamp(char *date) {
    struct tm tm;
    strptime(date, "%d-%m-%Y", &tm);
    return mktime(&tm);
}

// Function to convert a timestamp to a date string
void timestampToString(time_t timestamp, char *date) {
    struct tm tm;
    localtime_r(&timestamp, &tm);
    strftime(date, 20, "%d-%m-%Y", &tm);
}

int main() {
    char input[100];
    char *date;
    char *month;
    char *day;
    char *year;
    char result[20];

    // Get user input
    printf("Enter a date (dd-mm-yyyy): ");
    scanf("%s", input);

    // Extract day, month, and year from input
    date = strtok(input, "-");
    month = strtok(NULL, "-");
    year = strtok(NULL, "-");

    // Check if input is a valid date
    if (!isValidDate(input)) {
        printf("Invalid date!\n");
        return 1;
    }

    // Convert input date to timestamp
    time_t timestamp = stringToTimestamp(input);

    // Convert timestamp to natural language date string
    timestampToString(timestamp, result);

    // Output the result
    printf("The natural language representation of %s is %s.\n", input, result);

    return 0;
}