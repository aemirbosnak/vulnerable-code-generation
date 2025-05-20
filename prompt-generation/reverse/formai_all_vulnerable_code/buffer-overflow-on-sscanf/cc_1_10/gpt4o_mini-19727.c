//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function to convert month string to month number
int month_string_to_number(const char *month) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Month numbers are 1-12
        }
    }
    return -1; // Invalid month
}

// Function to convert natural language date to struct tm
int convert_date(const char *date_str, struct tm *date) {
    char month[20];
    int day, year;

    // Check for a format "Day Month Year"
    if (sscanf(date_str, "%d %19s %d", &day, month, &year) == 3) {
        date->tm_mday = day;
        date->tm_year = year - 1900; // tm_year is years since 1900
        date->tm_mon = month_string_to_number(month) - 1; // tm_mon is 0-11
        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_isdst = -1; // Not considering Daylight Saving Time, set to -1 for auto
        return 1; // Successful conversion
    }
    return 0; // Failed conversion
}

// Function to get current date in string format
void get_current_date(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(buffer, size, "%d %B %Y", tm_now);
}

// Function to display the date in user-friendly format
void display_date(struct tm *date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y", date);
    printf("The converted date is: %s\n", buffer);
}

// Main function to handle user inputs and conversions
int main() {
    char input[MAX_INPUT_LENGTH];
    struct tm date_info;

    // Initialize struct tm
    memset(&date_info, 0, sizeof(struct tm));

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in the format: \"Day Month Year\" (e.g., 12 March 2023)\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("\nPlease enter a date: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        // Check if the user wants to exit
        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Attempt to convert and display the date
        if (convert_date(input, &date_info)) {
            display_date(&date_info);
        } else {
            printf("Error: Invalid date format. Please try again.\n");
        }
    }
    return 0;
}