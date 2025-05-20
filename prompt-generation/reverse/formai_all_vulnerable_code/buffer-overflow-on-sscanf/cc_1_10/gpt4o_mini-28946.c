//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert natural language date into a structured date format
int parseDate(char *inputDate, struct tm *dateStruct) {
    char month[20], day[10], year[10];
    // Initialize struct with default values
    memset(dateStruct, 0, sizeof(struct tm));

    // Scan the input date to find month, day, and year
    if (sscanf(inputDate, "%s %s %s", month, day, year) != 3) {
        printf("Invalid date format. Please use 'Month Day Year'.\n");
        return 1;
    }

    // Convert month name to number
    if (strcmp(month, "January") == 0) dateStruct->tm_mon = 0;
    else if (strcmp(month, "February") == 0) dateStruct->tm_mon = 1;
    else if (strcmp(month, "March") == 0) dateStruct->tm_mon = 2;
    else if (strcmp(month, "April") == 0) dateStruct->tm_mon = 3;
    else if (strcmp(month, "May") == 0) dateStruct->tm_mon = 4;
    else if (strcmp(month, "June") == 0) dateStruct->tm_mon = 5;
    else if (strcmp(month, "July") == 0) dateStruct->tm_mon = 6;
    else if (strcmp(month, "August") == 0) dateStruct->tm_mon = 7;
    else if (strcmp(month, "September") == 0) dateStruct->tm_mon = 8;
    else if (strcmp(month, "October") == 0) dateStruct->tm_mon = 9;
    else if (strcmp(month, "November") == 0) dateStruct->tm_mon = 10;
    else if (strcmp(month, "December") == 0) dateStruct->tm_mon = 11;
    else {
        printf("Unknown month: %s\n", month);
        return 2;
    }

    // Parse day and year
    dateStruct->tm_mday = atoi(day);
    dateStruct->tm_year = atoi(year) - 1900; // Years since 1900

    // Validate day and month
    if (dateStruct->tm_mday < 1 || dateStruct->tm_mday > 31 || dateStruct->tm_mon < 0 || dateStruct->tm_mon > 11) {
        printf("Invalid day or month.\n");
        return 3;
    }

    // Use mktime to normalize the date
    time_t rawTime = mktime(dateStruct);
    if (rawTime == -1) {
        printf("Failed to normalize date.\n");
        return 4;
    }

    return 0; // Success
}

void displayDate(struct tm *dateStruct) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", dateStruct);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char inputDate[100];
    struct tm dateStruct;

    printf("Enter a date in the format 'Month Day Year': ");
    if (fgets(inputDate, sizeof(inputDate), stdin) != NULL) {
        // Remove newline character if present
        inputDate[strcspn(inputDate, "\n")] = 0;

        int result = parseDate(inputDate, &dateStruct);
        if (result == 0) {
            displayDate(&dateStruct);
        } else {
            printf("Error in parsing date: code %d\n", result);
        }
    } else {
        printf("Input error.\n");
    }

    return 0;
}