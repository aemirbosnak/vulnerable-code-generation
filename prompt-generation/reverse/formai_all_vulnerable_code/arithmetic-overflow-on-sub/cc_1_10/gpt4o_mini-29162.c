//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_STRING 100
#define MAX_MONTH_NAME 20

// Function prototypes
void convertNaturalLanguageDate(const char *dateStr, struct tm *date);
int isValidDate(struct tm date);
void printDate(struct tm date);
void toLowerCase(char *str);

int main() {
    char dateInput[MAX_DATE_STRING];
    struct tm date = {0};

    printf("Enter a date in natural language (e.g., \"January 1, 2020\" or \"1st of February 2021\"): ");
    fgets(dateInput, sizeof(dateInput), stdin);
    dateInput[strcspn(dateInput, "\n")] = 0; // Remove newline character

    convertNaturalLanguageDate(dateInput, &date);

    if (isValidDate(date)) {
        printDate(date);
    } else {
        printf("Invalid date provided, please try again.\n");
    }

    return 0;
}

void convertNaturalLanguageDate(const char *dateStr, struct tm *date) {
    char monthStr[MAX_MONTH_NAME];
    int day, year;

    // Pattern: Month Day, Year or Day of Month Month Year
    if (sscanf(dateStr, "%s %d, %d", monthStr, &day, &year) == 3) {
        // Handle "January 1, 2020"
        date->tm_year = year - 1900; // tm_year is years since 1900
        date->tm_mday = day;
        toLowerCase(monthStr); // Convert month to lowercase
        
        if (strcmp(monthStr, "january") == 0) date->tm_mon = 0;
        else if (strcmp(monthStr, "february") == 0) date->tm_mon = 1;
        else if (strcmp(monthStr, "march") == 0) date->tm_mon = 2;
        else if (strcmp(monthStr, "april") == 0) date->tm_mon = 3;
        else if (strcmp(monthStr, "may") == 0) date->tm_mon = 4;
        else if (strcmp(monthStr, "june") == 0) date->tm_mon = 5;
        else if (strcmp(monthStr, "july") == 0) date->tm_mon = 6;
        else if (strcmp(monthStr, "august") == 0) date->tm_mon = 7;
        else if (strcmp(monthStr, "september") == 0) date->tm_mon = 8;
        else if (strcmp(monthStr, "october") == 0) date->tm_mon = 9;
        else if (strcmp(monthStr, "november") == 0) date->tm_mon = 10;
        else if (strcmp(monthStr, "december") == 0) date->tm_mon = 11;
    } else if (sscanf(dateStr, "%d of %s %d", &day, monthStr, &year) == 3) {
        // Handle "1st of February 2021"
        date->tm_year = year - 1900;
        date->tm_mday = day;
        toLowerCase(monthStr); // Convert month to lowercase
        
        if (strcmp(monthStr, "january") == 0) date->tm_mon = 0;
        else if (strcmp(monthStr, "february") == 0) date->tm_mon = 1;
        else if (strcmp(monthStr, "march") == 0) date->tm_mon = 2;
        else if (strcmp(monthStr, "april") == 0) date->tm_mon = 3;
        else if (strcmp(monthStr, "may") == 0) date->tm_mon = 4;
        else if (strcmp(monthStr, "june") == 0) date->tm_mon = 5;
        else if (strcmp(monthStr, "july") == 0) date->tm_mon = 6;
        else if (strcmp(monthStr, "august") == 0) date->tm_mon = 7;
        else if (strcmp(monthStr, "september") == 0) date->tm_mon = 8;
        else if (strcmp(monthStr, "october") == 0) date->tm_mon = 9;
        else if (strcmp(monthStr, "november") == 0) date->tm_mon = 10;
        else if (strcmp(monthStr, "december") == 0) date->tm_mon = 11;
    } else {
        printf("Could not convert date: %s\n", dateStr);
    }
}

int isValidDate(struct tm date) {
    // Normalize the tm structure and check validity
    time_t rawtime;
    rawtime = mktime(&date);
    return rawtime != -1;
}

void printDate(struct tm date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "Date: %A, %B %d, %Y", &date);
    printf("%s\n", buffer);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}