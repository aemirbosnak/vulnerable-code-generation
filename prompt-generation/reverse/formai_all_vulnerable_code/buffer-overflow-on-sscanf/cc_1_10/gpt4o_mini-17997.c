//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert a natural language date to a struct tm representation
int parse_date(const char *input, struct tm *date) {
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    
    memset(date, 0, sizeof(struct tm));
    date->tm_year = current->tm_year;
    date->tm_mon = current->tm_mon;
    date->tm_mday = current->tm_mday;

    if (strcmp(input, "today") == 0) {
        // No change needed; today's date is already set
    } else if (strcmp(input, "tomorrow") == 0) {
        date->tm_mday += 1;
    } else if (sscanf(input, "next %d", &date->tm_wday) == 1) {
        date->tm_mday += 7; // Move forward 7 days for 'next'
        // Adjust based on day of the week
        int today_wday = current->tm_wday;
        date->tm_mday += (date->tm_wday - today_wday + 7) % 7;
    } else if (sscanf(input, "on %d %d", &date->tm_mday, &date->tm_year) == 2) {
        date->tm_year -= 1900;  // Adjust year to tm_year format
    } else if (sscanf(input, "%d %d ", &date->tm_mday, &date->tm_mon) == 2) {
        date->tm_mon -= 1; // Convert to zero-based month
        date->tm_year = current->tm_year; // Assume current year
    } else {
        printf("Unrecognized date format\n");
        return -1;
    }

    // Normalize the date structure
    mktime(date);
    return 0;
}

// Function to format the date into a readable format
void print_date(struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("The parsed date is: %s\n", buffer);
}

int main() {
    struct tm date;
    char input[256];

    printf("Enter a natural language date (e.g., 'today', 'tomorrow', 'next Friday'): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    if (parse_date(input, &date) == 0) {
        print_date(&date);
    } else {
        printf("Failed to parse the date.\n");
    }

    return 0;
}