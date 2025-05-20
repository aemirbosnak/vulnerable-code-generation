//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void get_current_time();
void parse_date_string(char *inputDate);
void handle_display_date(struct tm *date);
int is_valid_date(struct tm *date);
void display_date(struct tm *date);

int main() {
    // Introductory message
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter dates in various formats like:\n");
    printf("1. 'today'\n");
    printf("2. 'next Monday'\n");
    printf("3. 'April 15, 2023'\n");
    printf("4. '2 days ago'\n");
    printf("5. and many more...\n");

    char inputDate[100];

    while (1) {
        // Prompt user for input
        printf("Enter a date (or type 'exit' to quit): ");
        fgets(inputDate, sizeof(inputDate), stdin);
        
        // Remove newline character if present
        inputDate[strcspn(inputDate, "\n")] = 0;

        // Exit condition
        if (strcmp(inputDate, "exit") == 0) {
            printf("Exiting the Date Converter. Have a great day!\n");
            break;
        }
        
        // Parse and display the date
        parse_date_string(inputDate);
    }

    return 0;
}

// Function to get the current system time
void get_current_time() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    printf("Current Date and Time: %s", asctime(tm_info));
}

// Function to parse a date string
void parse_date_string(char *inputDate) {
    struct tm date = {0};
    time_t now; 
    time(&now);
    localtime_r(&now, &date);

    // Simple parsing of common expressions and natural dates
    if (strcmp(inputDate, "today") == 0) {
        display_date(&date);
        return;
    } else if (strstr(inputDate, "next") != NULL) {
        // Handle next day logic
        // Find the day after today
        char *dayPointer = strtok(inputDate, " ");
        dayPointer = strtok(NULL, " ");

        if (dayPointer) {
            int dayOfWeek = -1;
            if (strcmp(dayPointer, "Monday") == 0) dayOfWeek = 1;
            if (strcmp(dayPointer, "Tuesday") == 0) dayOfWeek = 2;
            if (strcmp(dayPointer, "Wednesday") == 0) dayOfWeek = 3;
            if (strcmp(dayPointer, "Thursday") == 0) dayOfWeek = 4;
            if (strcmp(dayPointer, "Friday") == 0) dayOfWeek = 5;
            if (strcmp(dayPointer, "Saturday") == 0) dayOfWeek = 6;
            if (strcmp(dayPointer, "Sunday") == 0) dayOfWeek = 0;

            if (dayOfWeek != -1) {
                date.tm_mday += (dayOfWeek - date.tm_wday + 7) % 7 + 1;
                mktime(&date); // Normalize the date
                display_date(&date);
                return;
            }
        }
    } else if (strstr(inputDate, "ago") != NULL) {
        // Handle 'days ago' logic
        int days = 0;
        sscanf(inputDate, "%d days ago", &days);
        date.tm_mday -= days;
        mktime(&date);
        display_date(&date);
        return;
    } else {
        // Handle date parsing for formats like 'April 15, 2023'
        if (strptime(inputDate, "%B %d, %Y", &date) || strptime(inputDate, "%d %B %Y", &date)) {
            if (is_valid_date(&date)) {
                display_date(&date);
                return;
            }
        }
    }

    // If nothing matched, show an error message
    printf("Error: Unable to parse the date '%s'. Please try a different format.\n", inputDate);
}

// Function to check if the date is valid
int is_valid_date(struct tm *date) {
    if (date->tm_year >= 1900 && date->tm_year <= 2100) {
        return 1; // Valid year
    }
    return 0; // Invalid year
}

// Function to display the formatted date
void display_date(struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("Converted Date: %s\n", buffer);
}