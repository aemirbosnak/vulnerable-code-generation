//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_MONTH 12

const char *months[MAX_MONTH] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int monthToNumber(const char *monthStr) {
    for (int i = 0; i < MAX_MONTH; i++) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

void parseDate(const char *input, struct tm *dateStruct) {
    char monthStr[20];
    int day, year;
    
    // Try to match the date format: "Day Month Year"
    if (sscanf(input, "%d %s %d", &day, monthStr, &year) == 3) {
        dateStruct->tm_mday = day;
        dateStruct->tm_year = year - 1900; // Years since 1900
        dateStruct->tm_mon = monthToNumber(monthStr) - 1; // Months are 0-indexed
    } else {
        printf("Invalid date format. Please use 'Day Month Year' format.\n");
    }
}

void printFormattedDate(struct tm *dateStruct) {
    char buffer[80];
    // Create a formatted date string
    strftime(buffer, sizeof(buffer), "%d %B %Y", dateStruct);
    printf("Formatted Date: %s\n", buffer);
}

int main() {
    char input[MAX_INPUT];
    struct tm dateStruct = {0};
    
    // Prompt the user for input
    printf("Enter a date in the format 'Day Month Year' (e.g., '15 March 2021'): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;
    
    // Parse the input date
    parseDate(input, &dateStruct);
    
    // Check if the parsed date is valid
    if (dateStruct.tm_mon < 0 || dateStruct.tm_mon >= MAX_MONTH || 
        dateStruct.tm_mday < 1 || dateStruct.tm_year < 0) {
        printf("Date is invalid. Please try again.\n");
        return 1;
    }

    // Normalize the struct tm
    mktime(&dateStruct); // This also checks if the date is valid

    // Print the formatted date
    printFormattedDate(&dateStruct);

    return 0;
}