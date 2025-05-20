//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function to convert month name to month number
int month_to_number(const char *month_name) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_name, months[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Month not found
}

// Function to convert date string in natural language format
void convert_natural_language_date(const char *input, struct tm *output_date) {
    char month_name[20];
    int day, year;
    
    // Scan the string for the day, month name and year
    if (sscanf(input, "%d %s %d", &day, month_name, &year) != 3) {
        fprintf(stderr, "Invalid date format. Please use: 'day month year'\n");
        exit(EXIT_FAILURE);
    }

    // Convert month name to number
    int month = month_to_number(month_name);
    if (month == -1) {
        fprintf(stderr, "Invalid month name: %s\n", month_name);
        exit(EXIT_FAILURE);
    }

    // Fill the tm structure
    output_date->tm_mday = day;
    output_date->tm_mon = month - 1; // tm_mon is 0-indexed
    output_date->tm_year = year - 1900; // tm_year years since 1900
    output_date->tm_hour = 0;
    output_date->tm_min = 0;
    output_date->tm_sec = 0;
    output_date->tm_isdst = -1; // Not considering daylight saving
}

// Function to display date in a standardized format
void display_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char input[MAX_LENGTH];
    struct tm output_date;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the following format: 'day month year'\n");
    printf("Example: '21 March 2023'\n");

    // Read the input from user
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    // Convert the input into the tm structure
    convert_natural_language_date(input, &output_date);

    // Display the converted date
    display_date(&output_date);

    return 0;
}