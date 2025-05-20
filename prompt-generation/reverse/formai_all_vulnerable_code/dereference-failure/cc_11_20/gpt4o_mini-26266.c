//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INPUT_SIZE 256

// Function declarations
int get_month_number(char *month);
int get_day_of_month(char *day);
void convert_to_date(char *input);

int main() {
    char input[INPUT_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Type a date in the format 'on [Day] [Month] [Year]' or 'today' or 'tomorrow':\n");

    while (1) {
        printf("> ");
        fgets(input, INPUT_SIZE, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the date converter. Goodbye!\n");
            break; // Exit loop if the user enters 'exit'
        }

        convert_to_date(input);
    }
    
    return 0;
}

// Function to convert the input sentence to a date
void convert_to_date(char *input) {
    time_t now;
    struct tm *timeinfo;
    char *token;
    
    // Initialize time info struct
    time(&now);
    timeinfo = localtime(&now);

    // Check for keywords 'today' or 'tomorrow'
    if (strcmp(input, "today") == 0) {
        printf("Today's date is: %s", asctime(timeinfo));
        return;
    } else if (strcmp(input, "tomorrow") == 0) {
        timeinfo->tm_mday += 1; // Increment the day for tomorrow
        mktime(timeinfo);       // Normalize the date
        printf("Tomorrow's date is: %s", asctime(timeinfo));
        return;
    }

    // Parse input to extract day, month and year
    token = strtok(input, " ");
    
    // First token should be 'on'
    if (strcmp(token, "on") != 0) {
        printf("Invalid input. Please start with 'on'.\n");
        return;
    }

    // Get day
    token = strtok(NULL, " ");
    int day = get_day_of_month(token);
    
    // Get month
    token = strtok(NULL, " ");
    int month = get_month_number(token);
    
    // Get year, either from input or current year
    token = strtok(NULL, " ");
    int year = (token == NULL) ? timeinfo->tm_year + 1900 : atoi(token);

    // Check for valid conversion
    if (day < 1 || day > 31 || month < 0) {
        printf("Invalid date input. Please try again.\n");
        return;
    }

    // Construct date and print
    timeinfo->tm_mday = day;
    timeinfo->tm_mon = month;
    timeinfo->tm_year = year - 1900;

    mktime(timeinfo); // Normalize date for any overflow
    printf("Converted date is: %s", asctime(timeinfo));
}

// Function to convert month name to month number
int get_month_number(char *month) {
    if (strcmp(month, "January") == 0) return 0;
    else if (strcmp(month, "February") == 0) return 1;
    else if (strcmp(month, "March") == 0) return 2;
    else if (strcmp(month, "April") == 0) return 3;
    else if (strcmp(month, "May") == 0) return 4;
    else if (strcmp(month, "June") == 0) return 5;
    else if (strcmp(month, "July") == 0) return 6;
    else if (strcmp(month, "August") == 0) return 7;
    else if (strcmp(month, "September") == 0) return 8;
    else if (strcmp(month, "October") == 0) return 9;
    else if (strcmp(month, "November") == 0) return 10;
    else if (strcmp(month, "December") == 0) return 11;
    else return -1; // Invalid month
}

// Function to convert day string to an integer
int get_day_of_month(char *day) {
    if (strcmp(day, "first") == 0) return 1;
    else if (strcmp(day, "second") == 0) return 2;
    else if (strcmp(day, "third") == 0) return 3;
    else if (strcmp(day, "fourth") == 0) return 4;
    else if (strcmp(day, "fifth") == 0) return 5;
    else if (strcmp(day, "sixth") == 0) return 6;
    else if (strcmp(day, "seventh") == 0) return 7;
    else if (strcmp(day, "eighth") == 0) return 8;
    else if (strcmp(day, "ninth") == 0) return 9;
    else if (strcmp(day, "tenth") == 0) return 10;
    else if (strcmp(day, "eleventh") == 0) return 11;
    else if (strcmp(day, "twelfth") == 0) return 12;
    else if (strcmp(day, "thirteenth") == 0) return 13;
    else if (strcmp(day, "fourteenth") == 0) return 14;
    else if (strcmp(day, "fifteenth") == 0) return 15;
    else if (strcmp(day, "sixteenth") == 0) return 16;
    else if (strcmp(day, "seventeenth") == 0) return 17;
    else if (strcmp(day, "eighteenth") == 0) return 18;
    else if (strcmp(day, "nineteenth") == 0) return 19;
    else if (strcmp(day, "twentieth") == 0) return 20;
    else if (strcmp(day, "twenty-first") == 0) return 21;
    else if (strcmp(day, "twenty-second") == 0) return 22;
    else if (strcmp(day, "twenty-third") == 0) return 23;
    else if (strcmp(day, "twenty-fourth") == 0) return 24;
    else if (strcmp(day, "twenty-fifth") == 0) return 25;
    else if (strcmp(day, "twenty-sixth") == 0) return 26;
    else if (strcmp(day, "twenty-seventh") == 0) return 27;
    else if (strcmp(day, "twenty-eighth") == 0) return 28;
    else if (strcmp(day, "twenty-ninth") == 0) return 29;
    else if (strcmp(day, "thirtieth") == 0) return 30;
    else if (strcmp(day, "thirty-first") == 0) return 31;
    else return -1; // Invalid day
}