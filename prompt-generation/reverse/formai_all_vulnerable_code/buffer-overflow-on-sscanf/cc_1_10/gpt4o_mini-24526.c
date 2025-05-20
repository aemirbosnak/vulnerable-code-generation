//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Structure to hold date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to convert natural language date to Date struct
Date parseDate(const char* dateInput) {
    Date date = {0, 0, 0};
    char month[20];

    // Sample format: "10th of October 2021" or "March 5, 2019"
    sscanf(dateInput, "%d %s %d", &date.day, month, &date.year);
    
    // Month name to integer mapping
    if (strcmp(month, "January") == 0) date.month = 1;
    else if (strcmp(month, "February") == 0) date.month = 2;
    else if (strcmp(month, "March") == 0) date.month = 3;
    else if (strcmp(month, "April") == 0) date.month = 4;
    else if (strcmp(month, "May") == 0) date.month = 5;
    else if (strcmp(month, "June") == 0) date.month = 6;
    else if (strcmp(month, "July") == 0) date.month = 7;
    else if (strcmp(month, "August") == 0) date.month = 8;
    else if (strcmp(month, "September") == 0) date.month = 9;
    else if (strcmp(month, "October") == 0) date.month = 10;
    else if (strcmp(month, "November") == 0) date.month = 11;
    else if (strcmp(month, "December") == 0) date.month = 12;
    else {
        printf("Invalid month input.\n");
        exit(EXIT_FAILURE);
    }

    return date;
}

// Function to validate the date
int isValidDate(Date date) {
    if (date.year < 1900 || date.year > 2100 || date.month < 1 || date.month > 12) {
        return 0;
    }

    // Days in month based on month and leap year
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) {
        daysInMonth[2] = 29; // February leap year
    }
    return date.day > 0 && date.day <= daysInMonth[date.month];
}

// Function to convert Date struct to string
void formatDate(Date date, char* output) {
    sprintf(output, "%02d/%02d/%04d", date.day, date.month, date.year);
}

// Function to print the Date in natural language
void printDateInNaturalLanguage(Date date) {
    const char* monthNames[] = { "", "January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December" };
    printf("You entered: %d %s %d\n", date.day, monthNames[date.month], date.year);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char formattedDate[11]; // For "dd/mm/yyyy"
    
    printf("Enter a date in natural language (e.g., '10 October 2021'): ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Clean the input by removing the newline character
    input[strcspn(input, "\n")] = 0;

    Date date = parseDate(input);
    
    if (!isValidDate(date)) {
        printf("The date you entered is not valid.\n");
        return EXIT_FAILURE;
    }

    formatDate(date, formattedDate);
    printDateInNaturalLanguage(date);
    
    printf("Formatted Date: %s\n", formattedDate);
    
    return EXIT_SUCCESS;
}