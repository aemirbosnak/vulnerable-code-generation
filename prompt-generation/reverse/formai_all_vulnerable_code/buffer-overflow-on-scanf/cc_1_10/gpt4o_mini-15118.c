//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void display_menu();
void convert_to_date(char *input);
int month_to_number(char *month);
void clear_buffer();

int main() {
    char input[100];
    int choice;

    // Program introduction
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("You can enter dates in a natural language format, and I will convert them for you.\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);
        clear_buffer();  // Clear the buffer before taking string input

        switch (choice) {
            case 1:
                printf("Enter a date in natural language (e.g., 'January 1, 2023' or '1st Jan 2023'):\n");
                fgets(input, sizeof(input), stdin);
                convert_to_date(input);
                break;
            case 2:
                printf("Thank you for using the Date Converter! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

// Function to display the menu
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Convert a natural language date\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to convert natural language to a date
void convert_to_date(char *input) {
    char month[20], date[10], year[10];
    int day;

    // Parsing the input based on natural language conventions
    if (sscanf(input, "%s %d, %s", month, &day, year) == 3 || 
        sscanf(input, "%d %s %s", &day, month, year) == 3) {
        
        int month_num = month_to_number(month);
        if (month_num == 0) {
            printf("Error: Invalid month entered.\n");
            return;
        }

        // Displaying the processed date
        printf("Converted date: %04d-%02d-%02d\n", atoi(year), month_num, day);
    } else {
        printf("Error: Could not parse the date. Please use a valid format.\n");
    }
}

// Function to convert month name to a number
int month_to_number(char *month) {
    if (strcasecmp(month, "January") == 0 || strcasecmp(month, "Jan") == 0) return 1;
    if (strcasecmp(month, "February") == 0 || strcasecmp(month, "Feb") == 0) return 2;
    if (strcasecmp(month, "March") == 0 || strcasecmp(month, "Mar") == 0) return 3;
    if (strcasecmp(month, "April") == 0 || strcasecmp(month, "Apr") == 0) return 4;
    if (strcasecmp(month, "May") == 0) return 5;
    if (strcasecmp(month, "June") == 0 || strcasecmp(month, "Jun") == 0) return 6;
    if (strcasecmp(month, "July") == 0 || strcasecmp(month, "Jul") == 0) return 7;
    if (strcasecmp(month, "August") == 0 || strcasecmp(month, "Aug") == 0) return 8;
    if (strcasecmp(month, "September") == 0 || strcasecmp(month, "Sep") == 0) return 9;
    if (strcasecmp(month, "October") == 0 || strcasecmp(month, "Oct") == 0) return 10;
    if (strcasecmp(month, "November") == 0 || strcasecmp(month, "Nov") == 0) return 11;
    if (strcasecmp(month, "December") == 0 || strcasecmp(month, "Dec") == 0) return 12;
    return 0; // Invalid month
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Clear the input until newline
}