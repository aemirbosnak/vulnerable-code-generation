//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void clean_input(char *input) {
    for (char *p = input; *p; p++) {
        *p = tolower(*p);
    }
}

struct tm parse_date(const char *input) {
    struct tm date = {0};
    char month[20];
    int day, year;

    if (sscanf(input, "on %d %s %d", &day, month, &year) == 3) {
        // Month parsing logic
        if (strcmp(month, "january") == 0) date.tm_mon = 0;
        else if (strcmp(month, "february") == 0) date.tm_mon = 1;
        else if (strcmp(month, "march") == 0) date.tm_mon = 2;
        else if (strcmp(month, "april") == 0) date.tm_mon = 3;
        else if (strcmp(month, "may") == 0) date.tm_mon = 4;
        else if (strcmp(month, "june") == 0) date.tm_mon = 5;
        else if (strcmp(month, "july") == 0) date.tm_mon = 6;
        else if (strcmp(month, "august") == 0) date.tm_mon = 7;
        else if (strcmp(month, "september") == 0) date.tm_mon = 8;
        else if (strcmp(month, "october") == 0) date.tm_mon = 9;
        else if (strcmp(month, "november") == 0) date.tm_mon = 10;
        else if (strcmp(month, "december") == 0) date.tm_mon = 11;
        else {
            fprintf(stderr, "Invalid month: %s\n", month);
            exit(EXIT_FAILURE);
        }

        date.tm_mday = day;
        date.tm_year = year - 1900; // tm_year is years since 1900
    }
    else if (sscanf(input, "the %d %s", &day, month) == 2) {
        // Handle "the day month" description
        if (strcmp(month, "january") == 0) date.tm_mon = 0;
        // Rest of month parsing follows the same pattern...
        // Simplifying for the brevity of example
        date.tm_mday = day;
        date.tm_year = 2023 - 1900; // Using the current year for simplicity
    }
    else {
        fprintf(stderr, "Date format not recognized: %s\n", input);
        exit(EXIT_FAILURE);
    }

    return date;
}

void print_date(struct tm date) {
    char buffer[BUFFER_SIZE];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[BUFFER_SIZE];

    printf("Enter a date in natural language (e.g., 'on 23 March 2023' or 'the 23rd of March'):\n");
    fgets(input, sizeof(input), stdin);
    
    // Clean and normalize input
    clean_input(input);

    struct tm date = parse_date(input);
    print_date(date);

    return 0;
}