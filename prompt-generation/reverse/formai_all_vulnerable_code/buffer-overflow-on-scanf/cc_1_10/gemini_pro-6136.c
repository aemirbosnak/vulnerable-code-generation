//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the date
typedef struct {
    int year;
    int month;
    int day;
} Date;

// Define the function to convert a string to a date
Date stringToDate(char *string) {
    Date date;

    // Check if the string is in the correct format
    if (strlen(string) != 10 || string[2] != '-' || string[5] != '-') {
        fprintf(stderr, "Error: Invalid date format\n");
        exit(EXIT_FAILURE);
    }

    // Convert the year to an integer
    date.year = atoi(string);

    // Convert the month to an integer
    date.month = atoi(string + 3);

    // Convert the day to an integer
    date.day = atoi(string + 6);

    // Return the date
    return date;
}

// Define the function to convert a date to a string
char *dateToString(Date date) {
    // Allocate memory for the string
    char *string = malloc(11);

    // Convert the year to a string
    sprintf(string, "%d", date.year);

    // Convert the month to a string
    sprintf(string + 3, "-%02d", date.month);

    // Convert the day to a string
    sprintf(string + 6, "-%02d", date.day);

    // Return the string
    return string;
}

// Define the main function
int main(void) {
    // Get the date from the user
    char string[11];
    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", string);

    // Convert the string to a date
    Date date = stringToDate(string);

    // Convert the date to a string
    char *newString = dateToString(date);

    // Print the date
    printf("The date is: %s\n", newString);

    // Free the memory allocated for the string
    free(newString);

    return 0;
}