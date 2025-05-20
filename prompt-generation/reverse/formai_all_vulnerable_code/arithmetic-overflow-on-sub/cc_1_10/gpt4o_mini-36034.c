//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

// Function to convert a natural language date string to a structured time
struct tm* parse_date(const char* input_date) {
    struct tm *date_info = malloc(sizeof(struct tm));
    if (!date_info) {
        fprintf(stderr, "Memory allocation for date_info failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(date_info, 0, sizeof(struct tm));

    // Check if the input is in the format "Month Day, Year"
    if (sscanf(input_date, "%*s %d, %d", &date_info->tm_mday, &date_info->tm_year) == 2) {
        date_info->tm_year -= 1900;  // Adjust for tm_year
        return date_info;
    }
    
    // Check for "next <day_of_week>"
    char day[10];
    if (sscanf(input_date, "next %s", day) == 1) {
        time_t t = time(NULL);
        struct tm *current_time = localtime(&t);
        date_info->tm_hour = 0; // Set to midnight
        date_info->tm_min = 0;
        date_info->tm_sec = 0;

        // Find the next occurrence of the specified weekday
        int weekday = -1;
        if (strcmp(day, "Monday") == 0) weekday = 1;
        else if (strcmp(day, "Tuesday") == 0) weekday = 2;
        else if (strcmp(day, "Wednesday") == 0) weekday = 3;
        else if (strcmp(day, "Thursday") == 0) weekday = 4;
        else if (strcmp(day, "Friday") == 0) weekday = 5;
        else if (strcmp(day, "Saturday") == 0) weekday = 6;
        else if (strcmp(day, "Sunday") == 0) weekday = 0;

        if (weekday == -1) {
            fprintf(stderr, "Invalid day of the week specified: %s\n", day);
            free(date_info);
            exit(EXIT_FAILURE);
        }

        // Calculate the days until the next occurrence of that weekday
        int days_until_next = (7 + (weekday - current_time->tm_wday)) % 7;
        if (days_until_next == 0) days_until_next = 7; // Next week

        // Fill the date_info structure with the new date
        current_time->tm_mday += days_until_next;
        mktime(current_time); // Normalize
        *date_info = *current_time; // Store the result in date_info
        return date_info;
    }

    fprintf(stderr, "Unrecognized date format: %s\n", input_date);
    free(date_info);
    exit(EXIT_FAILURE);
}

// Helper function to display the parsed date
void display_date(struct tm* date_info) {
    char buffer[BUFFER_SIZE];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date_info);
    printf("Converted Date: %s\n", buffer);
}

// Main function of our grateful date converter
int main() {
    printf("Welcome to the Grateful Natural Language Date Converter!\n");
    printf("Please enter a date (e.g., 'March 5, 2023' or 'next Friday'): ");

    char input_date[BUFFER_SIZE];
    fgets(input_date, sizeof(input_date), stdin);

    // Remove newline character if present
    size_t len = strlen(input_date);
    if (len > 0 && input_date[len - 1] == '\n') {
        input_date[len - 1] = '\0';
    }

    // Parse the date string
    struct tm* parsed_date = parse_date(input_date);

    // Display the converted date
    display_date(parsed_date);

    // Free allocated memory
    free(parsed_date);
    printf("Thank you for using our Grateful Date Converter!\n");

    return 0;
}