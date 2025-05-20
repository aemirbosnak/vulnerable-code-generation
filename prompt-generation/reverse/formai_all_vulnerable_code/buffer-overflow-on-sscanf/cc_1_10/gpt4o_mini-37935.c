//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_MONTH_NAME_SIZE 20

// Function to check if the input string is a valid date
int is_valid_date(int day, int month, int year) {
    // Validate month
    if (month < 1 || month > 12) return 0;

    // Validate day based on the month and leap year
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month[2] = 29;
        }
    }

    // Validate day
    if (day < 1 || day > days_in_month[month]) return 0;

    return 1;
}

// Function to convert month name to month number
int month_name_to_number(const char *month_name) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_name, months[i]) == 0) {
            return i + 1; // Month number starts from 1
        }
    }
    return 0; // Invalid month
}

// Function to convert a natural date string to a structured date
void convert_date(const char *input) {
    char month_name[MAX_MONTH_NAME_SIZE];
    int day, year;

    // Scan the input for day, month name, and year
    if (sscanf(input, "%d %s %d", &day, month_name, &year) != 3) {
        printf("Invalid input format. Please use 'Day Month Year' format.\n");
        return;
    }

    // Convert month name to number
    int month = month_name_to_number(month_name);
    
    // Validate the date
    if (!is_valid_date(day, month, year)) {
        printf("The date '%s' is invalid!\n", input);
        return;
    }

    // Print the structured date
    printf("You entered a valid date: %02d-%02d-%04d\n", day, month, year);
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter a date in the format: 'Day Month Year' e.g., 25 December 2023\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("Enter a date: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Check for exit condition
        if (strcasecmp(input, "exit") == 0) {
            printf("Thank you for using the converter! Goodbye!\n");
            break;
        }

        // Convert the entered date
        convert_date(input);
    }

    return 0;
}