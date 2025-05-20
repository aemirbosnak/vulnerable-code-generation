//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 256

// Function Declarations
void get_date_input(char *input);
int parse_date(const char *input, struct tm *date);
void print_date(const struct tm *date);
void display_usage();

int main() {
    char input[BUFFER_SIZE];
    struct tm date = {0};

    display_usage();
    
    get_date_input(input);

    if (parse_date(input, &date)) {
        printf("Parsed date:\n");
        print_date(&date);
    } else {
        printf("Failed to parse the date. Please check your input format.\n");
    }

    return 0;
}

// Function to display usage instructions
void display_usage() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in one of the following formats:\n");
    printf("1. '25 December 2020'\n");
    printf("2. 'April 12, 2021'\n");
    printf("3. '2021/04/25'\n");
    printf("Type 'exit' to quit the application.\n\n");
}

// Function to get date input from the user
void get_date_input(char *input) {
    printf("Enter the date: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character
}

// Function to parse the date string
int parse_date(const char *input, struct tm *date) {
    char month_str[20];
    int day, year;

    // Check for natural language format
    if (sscanf(input, "%d %s %d", &day, month_str, &year) == 3 ||
        sscanf(input, "%s %d, %d", month_str, &day, &year) == 3 ||
        sscanf(input, "%d/%d/%d", &year, &month_str, &day) == 3) {

        // Convert month string to month index
        int month = -1;
        const char *months[] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};

        for (int i = 0; i < 12; i++) {
            if (strcasecmp(months[i], month_str) == 0) {
                month = i;
                break;
            }
        }

        if (month == -1) {
            return 0; // Invalid month
        }

        // Set tm structure
        date->tm_year = year - 1900;
        date->tm_mon = month;
        date->tm_mday = day;
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_isdst = -1; // Not considering daylight saving for simplicity

        return 1; // Successfully parsed
    }

    return 0; // Parsing failed
}

// Function to print the date in a readable format
void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y", date);
    printf("%s\n", buffer);
}