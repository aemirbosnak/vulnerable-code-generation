//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Function to convert a given date string into a date object
struct tm* stringToDate(char* dateStr) {
    struct tm* date = malloc(sizeof(struct tm));
    strptime(dateStr, "%B %d, %Y", date);
    return date;
}

// Function to convert a date object into a natural language string
char* dateToString(struct tm* date, int format) {
    char* dateStr;
    switch (format) {
        case 1:
            dateStr = malloc(sizeof(char) * 50);
            strftime(dateStr, 50, "Today is %A, %B %d, %Y", date);
            break;
        case 2:
            dateStr = malloc(sizeof(char) * 50);
            strftime(dateStr, 50, "%A, %B %d, %Y", date);
            break;
        default:
            dateStr = malloc(sizeof(char) * 50);
            strftime(dateStr, 50, "%A, %B %d, %Y", date);
            break;
    }
    return dateStr;
}

// Main function to take user input and display the result
int main() {
    char input[100];
    int choice;
    struct tm* date;

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'Month Day, Year': ");
    scanf("%s", input);

    date = stringToDate(input);

    printf("Please choose a format for the converted date:\n1. Today is...\n2....\n3. Default\n");
    scanf("%d", &choice);

    char* result;
    switch (choice) {
        case 1:
            result = dateToString(date, 1);
            printf("%s\n", result);
            break;
        case 2:
            result = dateToString(date, 2);
            printf("%s\n", result);
            break;
        default:
            result = dateToString(date, 3);
            printf("%s\n", result);
            break;
    }

    free(date);
    free(result);

    return 0;
}