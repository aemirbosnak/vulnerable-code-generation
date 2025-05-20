//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to check if a string is a valid date
int isValidDate(char* dateStr) {
    struct tm tm;
    strptime(dateStr, "%d-%m-%Y", &tm);
    return mktime(&tm)!= -1;
}

// Function to print a date in a given format
void printDate(struct tm* tm, char* format) {
    char dateStr[100];
    strftime(dateStr, sizeof(dateStr), format, tm);
    printf("%s", dateStr);
}

// Function to parse a date string and print it in different formats
void parseDate(char* dateStr) {
    // Parse the date string
    struct tm tm;
    strptime(dateStr, "%d-%m-%Y", &tm);

    // Print the date in different formats
    printDate(&tm, "%d-%m-%Y");
    printDate(&tm, "%d/%m/%Y");
    printDate(&tm, "%A, %d %B %Y");
    printDate(&tm, "%d %B %Y");
    printDate(&tm, "%A, %B %d, %Y");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "en_US.UTF-8");

    // Get the date string from the user
    char dateStr[100];
    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", dateStr);

    // Convert the string to lowercase
    toLowerCase(dateStr);

    // Check if the string is a valid date
    if (isValidDate(dateStr)) {
        // Convert the string to uppercase
        toUpperCase(dateStr);

        // Parse the date string and print it in different formats
        printf("\nDate entered: %s\n", dateStr);
        parseDate(dateStr);
    } else {
        printf("\nInvalid date entered.\n");
    }

    return 0;
}