//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_COMMAND_LENGTH 100

void print_usage() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter dates in the following formats:\n");
    printf("1. 'next Monday'\n");
    printf("2. 'January 21, 2023'\n");
    printf("3. 'tomorrow'\n");
    printf("4. '3 days ago'\n");
    printf("5. 'in 2 weeks'\n");
    printf("Type 'exit' to quit the program.\n");
}

const char* get_day_of_week(int day_offset) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    
    // Calculate the current day of the week
    int day_of_week = (tm_now->tm_wday + day_offset) % 7;
    
    static const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day_of_week];    
}

void convert_date(const char *input) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Handle different interpretations
    if (strcmp(input, "tomorrow") == 0) {
        timeinfo->tm_mday += 1;
    } else if (strcmp(input, "yesterday") == 0) {
        timeinfo->tm_mday -= 1;
    } else if (strstr(input, "days ago") != NULL) {
        int days;
        sscanf(input, "%d days ago", &days);
        timeinfo->tm_mday -= days;
    } else if (strstr(input, "in ") != NULL) {
        int weeks = 0, days = 0;
        if (sscanf(input, "in %d weeks", &weeks)) {
            timeinfo->tm_mday += weeks * 7;
        } else if (sscanf(input, "in %d days", &days)) {
            timeinfo->tm_mday += days;
        }
    } else {
        // Parse specific dates
        if (sscanf(input, "%s %d, %d", buffer, &timeinfo->tm_mday, &timeinfo->tm_year) == 3) {
            timeinfo->tm_year -= 1900; // Year needs to start from 1900
            // Convert month name to month number
            if (strcmp(buffer, "January") == 0) timeinfo->tm_mon = 0;
            else if (strcmp(buffer, "February") == 0) timeinfo->tm_mon = 1;
            else if (strcmp(buffer, "March") == 0) timeinfo->tm_mon = 2;
            else if (strcmp(buffer, "April") == 0) timeinfo->tm_mon = 3;
            else if (strcmp(buffer, "May") == 0) timeinfo->tm_mon = 4;
            else if (strcmp(buffer, "June") == 0) timeinfo->tm_mon = 5;
            else if (strcmp(buffer, "July") == 0) timeinfo->tm_mon = 6;
            else if (strcmp(buffer, "August") == 0) timeinfo->tm_mon = 7;
            else if (strcmp(buffer, "September") == 0) timeinfo->tm_mon = 8;
            else if (strcmp(buffer, "October") == 0) timeinfo->tm_mon = 9;
            else if (strcmp(buffer, "November") == 0) timeinfo->tm_mon = 10;
            else if (strcmp(buffer, "December") == 0) timeinfo->tm_mon = 11;
        } else {
            printf("Invalid input format. Please try again.\n");
            return;
        }
    }

    // Normalize date
    mktime(timeinfo);
    
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    printf("Converted date: %s\n", buffer);
}

int main() {
    char input[BUFFER_SIZE];

    print_usage();

    while (1) {
        printf("Enter a natural language date (or 'exit' to quit): ");
        fgets(input, BUFFER_SIZE, stdin);
        
        // Remove newline character from fgets
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        convert_date(input);
    }

    printf("Thank you for using the Natural Language Date Converter!\n");
    return 0;
}