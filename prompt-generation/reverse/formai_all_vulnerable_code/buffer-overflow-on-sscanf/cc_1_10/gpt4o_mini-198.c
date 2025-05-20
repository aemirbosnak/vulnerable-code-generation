//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Function to convert natural language date to a Unix timestamp
time_t natural_language_to_timestamp(const char *date_str) {
    struct tm tm;
    char buffer[BUFFER_SIZE];

    // Initialize the time structure to zero
    memset(&tm, 0, sizeof(tm));

    // Check for specific formats
    if (sscanf(date_str, "%d %s %d", &tm.tm_mday, buffer, &tm.tm_year) == 3) {
        // Check month
        if (strcmp(buffer, "January") == 0) tm.tm_mon = 0;
        else if (strcmp(buffer, "February") == 0) tm.tm_mon = 1;
        else if (strcmp(buffer, "March") == 0) tm.tm_mon = 2;
        else if (strcmp(buffer, "April") == 0) tm.tm_mon = 3;
        else if (strcmp(buffer, "May") == 0) tm.tm_mon = 4;
        else if (strcmp(buffer, "June") == 0) tm.tm_mon = 5;
        else if (strcmp(buffer, "July") == 0) tm.tm_mon = 6;
        else if (strcmp(buffer, "August") == 0) tm.tm_mon = 7;
        else if (strcmp(buffer, "September") == 0) tm.tm_mon = 8;
        else if (strcmp(buffer, "October") == 0) tm.tm_mon = 9;
        else if (strcmp(buffer, "November") == 0) tm.tm_mon = 10;
        else if (strcmp(buffer, "December") == 0) tm.tm_mon = 11;

        // Adjust year since 'tm_year' is years since 1900
        tm.tm_year -= 1900;

        // Convert to time_t
        return mktime(&tm);
    }

    // Handling "today" or "tomorrow"
    if (strcmp(date_str, "today") == 0) {
        return time(NULL);
    }
    if (strcmp(date_str, "tomorrow") == 0) {
        time_t now = time(NULL);
        return now + 86400; // 24*60*60 seconds
    }

    // Handle invalid input
    fprintf(stderr, "Invalid date format: %s\n", date_str);
    return -1;
}

// Function to format timestamp to readable date string
void format_timestamp(time_t timestamp, char *buffer, size_t buf_size) {
    struct tm *tm_info;

    tm_info = localtime(&timestamp);
    strftime(buffer, buf_size, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Main function
int main() {
    char input[BUFFER_SIZE];
    time_t timestamp;
    char formatted_date[BUFFER_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter dates like:\n");
    printf("1. '12 March 2023'\n");
    printf("2. 'today'\n");
    printf("3. 'tomorrow'\n");
    printf("Enter a date or command (or type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Convert the natural language date to timestamp
        timestamp = natural_language_to_timestamp(input);
        if (timestamp == -1) {
            continue; // Skip to next iteration if error occurred
        }

        // Format the timestamp to a readable string
        format_timestamp(timestamp, formatted_date, sizeof(formatted_date));
        printf("The formatted date is: %s\n", formatted_date);
    }

    printf("Thank you for using the Natural Language Date Converter. Goodbye!\n");
    return 0;
}