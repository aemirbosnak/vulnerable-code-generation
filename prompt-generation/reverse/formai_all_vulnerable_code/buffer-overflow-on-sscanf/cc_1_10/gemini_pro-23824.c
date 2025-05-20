//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct representing a date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Define the function to convert a string date to a Date struct
Date stringToDate(char *dateString) {
    // Allocate memory for the Date struct
    Date *date = malloc(sizeof(Date));

    // Parse the date string
    sscanf(dateString, "%d/%d/%d", &date->day, &date->month, &date->year);

    // Return the Date struct
    return *date;
}

// Define the function to convert a Date struct to a string
char *dateToString(Date date) {
    // Allocate memory for the string
    char *dateString = malloc(sizeof(char) * 11);

    // Format the date string
    sprintf(dateString, "%02d/%02d/%04d", date.day, date.month, date.year);

    // Return the string
    return dateString;
}

// Define the main function
int main() {
    // Get the input date string
    char dateString[11];
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", dateString);

    // Convert the string date to a Date struct
    Date date = stringToDate(dateString);

    // Print the Date struct
    printf("Date: %d/%d/%d\n", date.day, date.month, date.year);

    // Convert the Date struct to a string
    char *newDateString = dateToString(date);

    // Print the new date string
    printf("New date string: %s\n", newDateString);

    // Free the allocated memory
    free(newDateString);
    free(&date);

    return 0;
}