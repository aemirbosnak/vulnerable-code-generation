//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_MONTH_NAME_SIZE 20

// Structure to hold the date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to convert month name to month number
int month_name_to_number(const char *month_name) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month_name, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Invalid month
}

// Function to validate the date
int is_valid_date(Date date) {
    if (date.year < 1) return 0; // Year should be positive

    // Array to hold the number of days in each month
    int days_in_month[] = {31, 28 + (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)), 
                            31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (date.month >= 1 && date.month <= 12 && date.day >= 1 && date.day <= days_in_month[date.month - 1]);
}

// Function to parse a natural language date input
Date parse_natural_date(const char *input) {
    Date date;
    char month_name[MAX_MONTH_NAME_SIZE];
    
    // Using sscanf to capture day, month name, and year
    if (sscanf(input, "%d %s %d", &date.day, month_name, &date.year) != 3) {
        fprintf(stderr, "Invalid date format. Use: <day> <month_name> <year>\n");
        exit(EXIT_FAILURE);
    }

    date.month = month_name_to_number(month_name);
    if (date.month == -1) {
        fprintf(stderr, "Invalid month name: %s\n", month_name);
        exit(EXIT_FAILURE);
    }

    return date;
}

// Function to print the date in a readable format
void print_date(Date date) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    if (is_valid_date(date)) {
        printf("The date is: %02d %s %d\n", date.day, months[date.month - 1], date.year);
    } else {
        fprintf(stderr, "The date %02d %s %d is invalid.\n", date.day, months[date.month - 1], date.year);
    }
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the date in 'day month_name year' format: ");
    
    // Read the user's input
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0;

    // Parse the input date
    Date date = parse_natural_date(input);
    
    // Print the formatted date
    print_date(date);

    return EXIT_SUCCESS;
}