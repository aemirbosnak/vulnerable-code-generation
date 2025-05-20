//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

// Function prototypes
void convert_to_natural_language(const char *date_input);
void parse_date(const char *input, int *day, int *month, int *year);
void int_to_month(int month, char *month_str);

// Main function
int main() {
    char date_input[BUFFER_SIZE];
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format 'DD/MM/YYYY': ");
    
    if (fgets(date_input, BUFFER_SIZE, stdin) != NULL) {
        date_input[strcspn(date_input, "\n")] = 0; // Remove newline character
        convert_to_natural_language(date_input);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Function to convert the input date to a natural language format
void convert_to_natural_language(const char *date_input) {
    int day, month, year;
    parse_date(date_input, &day, &month, &year);

    char month_str[20];
    int_to_month(month, month_str);

    printf("The date you entered: %s\n", date_input);
    printf("In natural language, it's: %d %s %d\n", day, month_str, year);
}

// Function to parse the date from the input string
void parse_date(const char *input, int *day, int *month, int *year) {
    if (sscanf(input, "%d/%d/%d", day, month, year) != 3) {
        fprintf(stderr, "Invalid date format. Please use 'DD/MM/YYYY'.\n");
        exit(EXIT_FAILURE);
    }

    if (*day < 1 || *day > 31 || *month < 1 || *month > 12) {
        fprintf(stderr, "The day or month is out of valid range.\n");
        exit(EXIT_FAILURE);
    }
    
    // Basic validation for year (could be expanded)
    if (*year < 1) {
        fprintf(stderr, "Year must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to convert integer month to month name
void int_to_month(int month, char *month_str) {
    switch(month) {
        case 1: strcpy(month_str, "January"); break;
        case 2: strcpy(month_str, "February"); break;
        case 3: strcpy(month_str, "March"); break;
        case 4: strcpy(month_str, "April"); break;
        case 5: strcpy(month_str, "May"); break;
        case 6: strcpy(month_str, "June"); break;
        case 7: strcpy(month_str, "July"); break;
        case 8: strcpy(month_str, "August"); break;
        case 9: strcpy(month_str, "September"); break;
        case 10: strcpy(month_str, "October"); break;
        case 11: strcpy(month_str, "November"); break;
        case 12: strcpy(month_str, "December"); break;
        default: strcpy(month_str, "Invalid Month"); break;
    }
}