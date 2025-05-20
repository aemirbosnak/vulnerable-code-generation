//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void clear_input_buffer();
int parse_date(const char *input_date, struct tm *date_info);
void convert_and_print_date(const struct tm *date_info);
void display_options();
void to_lower_case(char *str);

int main() {
    char input_date[MAX_INPUT_SIZE];
    struct tm date_info;
    int result;

    display_options();

    while (1) {
        printf("Enter a date (or type 'exit' to quit): ");
        fgets(input_date, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character from the input
        input_date[strcspn(input_date, "\n")] = 0;

        // Check for exit condition
        to_lower_case(input_date);
        if (strcmp(input_date, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Parse the input date
        result = parse_date(input_date, &date_info);

        if (result == 0) {
            // If parsing was successful, print the converted date
            convert_and_print_date(&date_info);
        } else {
            printf("Invalid date format. Please try again.\n");
        }
    }

    return 0;
}

void clear_input_buffer() {
    while (getchar() != '\n') {}
}

int parse_date(const char *input_date, struct tm *date_info) {
    // Initialize the date information structure
    memset(date_info, 0, sizeof(struct tm));
    
    // Try to parse different formats
    // Format: DD/MM/YYYY
    if (sscanf(input_date, "%d/%d/%d", 
               &date_info->tm_mday, &date_info->tm_mon, &date_info->tm_year) == 3) {
        date_info->tm_mon -= 1; // Adjust month from 1-12 to 0-11
        date_info->tm_year -= 1900; // Adjust year to be years since 1900
        return 0;
    }

    // Format: Month DD, YYYY (e.g., January 1, 2023)
    char month_name[20];
    if (sscanf(input_date, "%s %d, %d", month_name, &date_info->tm_mday, 
               &date_info->tm_year) == 3) {
        const char* month_names[] = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        
        to_lower_case(month_name);

        for (int i = 0; i < 12; i++) {
            if (strcmp(month_name, month_names[i]) == 0) {
                date_info->tm_mon = i; // Set the month index
                date_info->tm_year -= 1900; // Adjust year
                return 0;
            }
        }
    }

    // Format: YYYY-MM-DD
    if (sscanf(input_date, "%d-%d-%d", 
               &date_info->tm_year, &date_info->tm_mon, &date_info->tm_mday) == 3) {
        date_info->tm_year -= 1900; // Adjust year
        date_info->tm_mon -= 1; // Adjust month
        return 0;
    }
    
    return -1; // Parsing failed
}

void convert_and_print_date(const struct tm *date_info) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y", date_info);
    printf("Converted date: %s\n", buffer);
}

void display_options() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can enter dates in the following formats:\n");
    printf("1. DD/MM/YYYY\n");
    printf("2. Month DD, YYYY (e.g., January 1, 2023)\n");
    printf("3. YYYY-MM-DD\n");
    printf("Type 'exit' to quit the program.\n");
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}