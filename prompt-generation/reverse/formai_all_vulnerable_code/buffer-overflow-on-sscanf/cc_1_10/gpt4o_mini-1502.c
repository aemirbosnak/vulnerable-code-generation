//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to extract year, month, and day from a natural language date string
void parse_date(char *input, int *year, int *month, int *day) {
    char month_str[20];
    char day_str[10];
    
    // Splitting the input string by spaces
    sscanf(input, "%s %s %d", month_str, day_str, year);
    
    // Convert month string to number
    if (strcmp(month_str, "January") == 0) {
        *month = 1;
    } else if (strcmp(month_str, "February") == 0) {
        *month = 2;
    } else if (strcmp(month_str, "March") == 0) {
        *month = 3;
    } else if (strcmp(month_str, "April") == 0) {
        *month = 4;
    } else if (strcmp(month_str, "May") == 0) {
        *month = 5;
    } else if (strcmp(month_str, "June") == 0) {
        *month = 6;
    } else if (strcmp(month_str, "July") == 0) {
        *month = 7;
    } else if (strcmp(month_str, "August") == 0) {
        *month = 8;
    } else if (strcmp(month_str, "September") == 0) {
        *month = 9;
    } else if (strcmp(month_str, "October") == 0) {
        *month = 10;
    } else if (strcmp(month_str, "November") == 0) {
        *month = 11;
    } else if (strcmp(month_str, "December") == 0) {
        *month = 12;
    } else {
        fprintf(stderr, "Invalid month provided.\n");
        exit(EXIT_FAILURE);
    }

    // Extract the day, considering the input might be two or one-digit
    *day = atoi(day_str);
}

// Function to print gratitude for a successful date conversion
void express_gratitude(int year, int month, int day) {
    printf("Thank you for sharing the date!\n");
    printf("You entered: %d-%02d-%02d\n", year, month, day);
    printf("In gratitude, your date is beautifully transformed into: ");
}

// Main function that drives the program
int main() {
    char date_input[100];
    int year, month, day;

    printf("Please enter the date in the format: 'Month Day Year' (e.g., 'February 20 2023'):\n");
    
    // Getting input from the user
    fgets(date_input, sizeof(date_input), stdin);
    date_input[strcspn(date_input, "\n")] = 0; // Remove newline character

    // Parse the date
    parse_date(date_input, &year, &month, &day);

    // Express gratitude and show the formatted date
    express_gratitude(year, month, day);

    // Show the formatted date
    printf("%d-%02d-%02d\n", year, month, day);
    
    return 0;
}