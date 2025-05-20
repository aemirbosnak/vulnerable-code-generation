//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Function declarations
void to_lowercase(char *str);
int parse_date(const char *input, struct tm *date);
void print_date(const struct tm *date);

int main() {
    char input[BUFFER_SIZE];
    struct tm date = {0}; // Initialize date structure

    printf("Welcome to the Brave Natural Language Date Converter!\n");
    printf("You can enter dates in various formats like:\n");
    printf("> 'Today'\n");
    printf("> 'Tomorrow'\n");
    printf("> 'Next Friday'\n");
    printf("> '1st March 2023'\n");
    printf("> 'March 1, 2023'\n");
    printf("Please enter a date: ");

    while (fgets(input, BUFFER_SIZE, stdin) != NULL) {
        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        if (parse_date(input, &date) == 0) {
            print_date(&date);
        } else {
            printf("I'm afraid I couldn't understand that date.\n");
        }

        printf("\nPlease enter another date: ");
    }

    return 0;
}

// Convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Parse the user's date input
int parse_date(const char *input, struct tm *date) {
    time_t now = time(NULL);
    struct tm *current_date = localtime(&now);
    int day, month, year;

    // Prepare input for parsing
    char input_copy[BUFFER_SIZE];
    strcpy(input_copy, input);
    to_lowercase(input_copy);

    // Handle special cases
    if (strcmp(input_copy, "today") == 0) {
        *date = *current_date;
        return 0;
    } else if (strcmp(input_copy, "tomorrow") == 0) {
        *date = *current_date;
        date->tm_mday += 1;
        mktime(date);
        return 0;
    } else if (strncmp(input_copy, "next", 4) == 0) {
        char *day_of_week = input_copy + 5; // Skip "next "
        for (int i = 0; i < 7; i++) {
            if (strstr(day_of_week, "sunday")) { date->tm_wday = 0; }
            else if (strstr(day_of_week, "monday")) { date->tm_wday = 1; }
            else if (strstr(day_of_week, "tuesday")) { date->tm_wday = 2; }
            else if (strstr(day_of_week, "wednesday")) { date->tm_wday = 3; }
            else if (strstr(day_of_week, "thursday")) { date->tm_wday = 4; }
            else if (strstr(day_of_week, "friday")) { date->tm_wday = 5; }
            else if (strstr(day_of_week, "saturday")) { date->tm_wday = 6; }
            else return -1;
        }
        date->tm_mday = current_date->tm_mday + (7 - current_date->tm_wday + date->tm_wday) % 7 + 1;
        date->tm_mon = current_date->tm_mon; 
        date->tm_year = current_date->tm_year;
        return 0;
    }

    // Handle "1st March 2023" or "March 1, 2023"
    if (sscanf(input_copy, "%d %[^ ] %d", &day, input_copy, &year) == 3 ||
        sscanf(input_copy, "%[^ ] %d, %d", input_copy, &day, &year) == 3) {
        // Convert month name to number
        if (strcmp(input_copy, "january") == 0) month = 0;
        else if (strcmp(input_copy, "february") == 0) month = 1;
        else if (strcmp(input_copy, "march") == 0) month = 2;
        else if (strcmp(input_copy, "april") == 0) month = 3;
        else if (strcmp(input_copy, "may") == 0) month = 4;
        else if (strcmp(input_copy, "june") == 0) month = 5;
        else if (strcmp(input_copy, "july") == 0) month = 6;
        else if (strcmp(input_copy, "august") == 0) month = 7;
        else if (strcmp(input_copy, "september") == 0) month = 8;
        else if (strcmp(input_copy, "october") == 0) month = 9;
        else if (strcmp(input_copy, "november") == 0) month = 10;
        else if (strcmp(input_copy, "december") == 0) month = 11;
        else return -1;

        // Fill the date structure
        date->tm_mday = day;
        date->tm_mon = month;
        date->tm_year = year - 1900; // Adjust for struct tm
        return 0;
    }

    return -1; // Parsing failed
}

// Print the date in YYYY-MM-DD format
void print_date(const struct tm *date) {
    char formatted_date[11]; // YYYY-MM-DD + '\0'
    snprintf(formatted_date, sizeof(formatted_date), "%04d-%02d-%02d",
             date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);
    printf("Converted date: %s\n", formatted_date);
}