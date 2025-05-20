//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert month name to number
int monthToNumber(const char *month) {
    if (strcasecmp(month, "January") == 0) return 1;
    else if (strcasecmp(month, "February") == 0) return 2;
    else if (strcasecmp(month, "March") == 0) return 3;
    else if (strcasecmp(month, "April") == 0) return 4;
    else if (strcasecmp(month, "May") == 0) return 5;
    else if (strcasecmp(month, "June") == 0) return 6;
    else if (strcasecmp(month, "July") == 0) return 7;
    else if (strcasecmp(month, "August") == 0) return 8;
    else if (strcasecmp(month, "September") == 0) return 9;
    else if (strcasecmp(month, "October") == 0) return 10;
    else if (strcasecmp(month, "November") == 0) return 11;
    else if (strcasecmp(month, "December") == 0) return 12;
    return 0; // Invalid month
}

// Function to format date
void formatDate(int day, int month, int year) {
    printf("Converted Date: %02d-%02d-%04d\n", day, month, year);
}

// Main date converting function
void convertDate(const char *input) {
    int day, month, year; 
    char month_name[20], year_str[5];
    
    // Scan the input for a typical date format example: "25 December 2023"
    int matches = sscanf(input, "%d %s %s", &day, month_name, year_str);
    
    if (matches == 3) {
        month = monthToNumber(month_name);
        year = atoi(year_str);

        if (month != 0 && year > 0 && day > 0 && day <= 31) {
            formatDate(day, month, year);
        } else {
            printf("Error: Invalid date information provided.\n");
        }
    } else {
        printf("Error: Unable to parse the date. Please use the format: 'DD Month YYYY'\n");
    }
}

// Entry point of the program
int main(void) {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'DD Month YYYY': \n");
    
    char input[50];
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    convertDate(input);
    
    printf("Thank you for using the Date Converter! Have a wonderful day!\n");
    return 0;
}