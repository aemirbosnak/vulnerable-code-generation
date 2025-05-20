//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

// Month names for easier conversion
const char* MONTHS[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function to parse date in natural language
int parse_date(const char* input, struct tm* date) {
    char month_str[20];
    int day, year;
    char period[3] = {0};

    // Initialize date structure
    memset(date, 0, sizeof(struct tm));

    // Use sscanf to extract components from the string
    if (sscanf(input, "%d %s %d %2s", &day, month_str, &year, period) < 3) {
        printf("Invalid date format. Please use: <day> <month> <year> [AM/PM]\n");
        return -1; // Error
    }

    // Normalize month to number
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_str, MONTHS[i]) == 0) {
            date->tm_mon = i; // Set month (0-11)
            break;
        }
    }
    if (date->tm_mon < 0) {
        printf("Invalid month: %s\n", month_str);
        return -1; // Error
    }

    date->tm_mday = day;
    date->tm_year = year - 1900; // Years since 1900

    // Handle AM/PM (Optional)
    if (strlen(period) > 0) {
        if (strcasecmp(period, "AM") == 0) {
            date->tm_hour = 0; // Reset hour
        } else if (strcasecmp(period, "PM") == 0) {
            date->tm_hour = 12; // Set to noon (12 PM)
        }
    }

    date->tm_isdst = -1; // Not considering daylight saving time

    return 0; // Success
}

// Function to print date in standard format
void print_standard_date(const struct tm* date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", date);
    printf("Converted date: %s\n", buffer);
}

int main() {
    char input[MAX_INPUT];
    struct tm date;
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter a date in the format: <day> <month> <year> [AM/PM] (e.g. 25 December 2023 PM)\n");

    while (1) {
        printf("Please enter a date (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcasecmp(input, "exit") == 0) {
            printf("Thank you for using the Date Converter! Goodbye!\n");
            break;
        }

        // Parse date
        if (parse_date(input, &date) == 0) {
            print_standard_date(&date);
        }
    }

    return 0;
}