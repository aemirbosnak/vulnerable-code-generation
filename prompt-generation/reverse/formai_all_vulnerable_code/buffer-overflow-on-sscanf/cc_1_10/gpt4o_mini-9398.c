//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define DATE_FORMAT_SIZE 11

// Function to extract day, month, and year from the input date string
int extractDateComponents(const char *input, int *day, int *month, int *year) {
    char monthStr[20];
    return sscanf(input, "%d %s %d", day, monthStr, year) == 3 && 
           (strlen(monthStr) > 0 && 
           (strncasecmp(monthStr, "January", 7) == 0 || strncasecmp(monthStr, "February", 8) == 0 ||
            strncasecmp(monthStr, "March", 5) == 0 || strncasecmp(monthStr, "April", 5) == 0 ||
            strncasecmp(monthStr, "May", 3) == 0 || strncasecmp(monthStr, "June", 4) == 0 ||
            strncasecmp(monthStr, "July", 4) == 0 || strncasecmp(monthStr, "August", 6) == 0 ||
            strncasecmp(monthStr, "September", 9) == 0 || strncasecmp(monthStr, "October", 7) == 0 ||
            strncasecmp(monthStr, "November", 8) == 0 || strncasecmp(monthStr, "December", 8) == 0));
}

// Function to convert month name to its corresponding number
int monthToNumber(const char *month) {
    if (strncasecmp(month, "January", 7) == 0) return 1;
    else if (strncasecmp(month, "February", 8) == 0) return 2;
    else if (strncasecmp(month, "March", 5) == 0) return 3;
    else if (strncasecmp(month, "April", 5) == 0) return 4;
    else if (strncasecmp(month, "May", 3) == 0) return 5;
    else if (strncasecmp(month, "June", 4) == 0) return 6;
    else if (strncasecmp(month, "July", 4) == 0) return 7;
    else if (strncasecmp(month, "August", 6) == 0) return 8;
    else if (strncasecmp(month, "September", 9) == 0) return 9;
    else if (strncasecmp(month, "October", 7) == 0) return 10;
    else if (strncasecmp(month, "November", 8) == 0) return 11;
    else if (strncasecmp(month, "December", 8) == 0) return 12;
    return -1; // Invalid month
}

// Function to generate date string in "YYYY-MM-DD" format
void formatDate(int day, int month, int year, char *output) {
    snprintf(output, DATE_FORMAT_SIZE, "%04d-%02d-%02d", year, month, day);
}

// Main date converter function
void dateConverter() {
    char input[MAX_INPUT_SIZE];
    int day, month, year;
    char output[DATE_FORMAT_SIZE];

    printf("Enter the date (e.g., 25 December 2023): ");
    if (fgets(input, sizeof(input), stdin)) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (extractDateComponents(input, &day, &month, &year)) {
            month = monthToNumber(strstr(input, " ") + 1); // Locate the month
            if (month == -1) {
                printf("Invalid month entered. Please try again.\n");
                return;
            }
            formatDate(day, month, year, output);
            printf("Converted date: %s\n", output);
        } else {
            printf("Invalid date format. Please enter in 'DD Month YYYY' format.\n");
        }
    } else {
        printf("Failed to read input.\n");
    }
}

// Entry point for the program
int main() {
    printf("Welcome to Natural Language Date Converter!\n");
    printf("You can enter dates in the format 'DD Month YYYY'.\n");
    
    dateConverter();
    
    return 0;
}