//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert natural language date input to a time_t value
time_t convert_to_time_t(const char *input) {
    struct tm tm = {0};
    char week_day[10], month[10], rest[50];
    int day, year;

    // Check for day of the week (if provided)
    if (sscanf(input, "%s %s %d %s %d", week_day, month, &day, rest, &year) == 5) {
        // Skip the weekday
    } else if (sscanf(input, "%s %d %s %d", month, &day, rest, &year) == 4) {
        // Only have month, day, and year
    } else if (sscanf(input, "%s %d %d", month, &day, &year) == 3) {
        // Just month, day, and year without additional text
    } else {
        fprintf(stderr, "Date format not recognized.\n");
        exit(EXIT_FAILURE);
    }

    // Setting the month
    if (strcmp(month, "January") == 0) tm.tm_mon = 0;
    else if (strcmp(month, "February") == 0) tm.tm_mon = 1;
    else if (strcmp(month, "March") == 0) tm.tm_mon = 2;
    else if (strcmp(month, "April") == 0) tm.tm_mon = 3;
    else if (strcmp(month, "May") == 0) tm.tm_mon = 4;
    else if (strcmp(month, "June") == 0) tm.tm_mon = 5;
    else if (strcmp(month, "July") == 0) tm.tm_mon = 6;
    else if (strcmp(month, "August") == 0) tm.tm_mon = 7;
    else if (strcmp(month, "September") == 0) tm.tm_mon = 8;
    else if (strcmp(month, "October") == 0) tm.tm_mon = 9;
    else if (strcmp(month, "November") == 0) tm.tm_mon = 10;
    else if (strcmp(month, "December") == 0) tm.tm_mon = 11;
    else {
        fprintf(stderr, "Invalid month name: %s\n", month);
        exit(EXIT_FAILURE);
    }

    // Setting the day and year
    tm.tm_mday = day;
    tm.tm_year = year - 1900; // Year since 1900

    // Normalize and convert to time_t
    time_t time_value = mktime(&tm);
    
    if (time_value == -1) {
        fprintf(stderr, "Failed to create time_t from tm structure.\n");
        exit(EXIT_FAILURE);
    }
    
    return time_value;
}

// Function to print the date in a human-readable format
void print_human_readable_date(time_t timestamp) {
    struct tm *tm_info = localtime(&timestamp);
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", tm_info);
    
    printf("Parsed date: %s\n", buffer);
}

int main() {
    char input[100];
    printf("Enter a date in natural language format (e.g., 'Monday January 15 2023'): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Convert to time_t
    time_t timestamp = convert_to_time_t(input);

    // Print the human-readable date
    print_human_readable_date(timestamp);

    return 0;
}