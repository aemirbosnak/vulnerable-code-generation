//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

int extractDateComponents(const char *dateInput, int *day, int *month, int *year) {
    char monthStr[20];
    int scannedItems;

    // Attempt to match 'day month year' structure
    scannedItems = sscanf(dateInput, "%d %s %d", day, monthStr, year);
    if (scannedItems == 3) {
        if (strcmp(monthStr, "January") == 0) *month = 1;
        else if (strcmp(monthStr, "February") == 0) *month = 2;
        else if (strcmp(monthStr, "March") == 0) *month = 3;
        else if (strcmp(monthStr, "April") == 0) *month = 4;
        else if (strcmp(monthStr, "May") == 0) *month = 5;
        else if (strcmp(monthStr, "June") == 0) *month = 6;
        else if (strcmp(monthStr, "July") == 0) *month = 7;
        else if (strcmp(monthStr, "August") == 0) *month = 8;
        else if (strcmp(monthStr, "September") == 0) *month = 9;
        else if (strcmp(monthStr, "October") == 0) *month = 10;
        else if (strcmp(monthStr, "November") == 0) *month = 11;
        else if (strcmp(monthStr, "December") == 0) *month = 12;
        else return 0; // Invalid month
        
        return 1; // Success
    }
    return 0; // Failed to parse
}

void printDateInFormat(int day, int month, int year) {
    printf("Converted date: %04d-%02d-%02d\n", year, month, day);
}

int main() {
    char input[MAX_INPUT_SIZE];
    int day, month, year;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in the format: 'day month year'.\n");
    printf("For example: '2 January 2023'\n");
    printf("Just type your date and press Enter:\n");

    // Get the user input
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Parse the input
    if (extractDateComponents(input, &day, &month, &year)) {
        printDateInFormat(day, month, year);
    } else {
        printf("Oops! That doesn't seem to be a correct date format.\n");
        printf("Please try again with 'day month year'.\n");
    }

    printf("Thanks for using the Natural Language Date Converter. Have a great day!\n");
    return 0;
}