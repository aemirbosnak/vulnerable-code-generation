//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 11
#define BUFFER_SIZE 100

// Function Prototypes
void prompt_user_for_date();
int parse_date(const char* input, int* day, int* month, int* year);
const char* convert_to_words(int day, int month, int year);
void display_date(const char* date_in_words);

// Main function to convert date from string to words
int main() {
    prompt_user_for_date();
    return 0;
}

// Function to prompt the user for a date
void prompt_user_for_date() {
    char date_input[MAX_DATE_LEN];
    printf("Enter a date in the format DD-MM-YYYY (e.g., 25-04-2023): ");
    fgets(date_input, sizeof(date_input), stdin);
    // Remove newline character from the input
    date_input[strcspn(date_input, "\n")] = 0;

    int day, month, year;
    if (parse_date(date_input, &day, &month, &year)) {
        const char* date_in_words = convert_to_words(day, month, year);
        display_date(date_in_words);
    } else {
        printf("Invalid date format! Please try again.\n");
    }
}

// Function to parse the date string into day, month, and year
int parse_date(const char* input, int* day, int* month, int* year) {
    return sscanf(input, "%d-%d-%d", day, month, year) == 3 &&
           *day > 0 && *day <= 31 &&
           *month > 0 && *month <= 12 &&
           *year > 0;
}

// Function to convert date parts into a human-readable string
const char* convert_to_words(int day, int month, int year) {
    static char date_in_words[BUFFER_SIZE];
    const char* month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    char day_suffix[3];
    if (day == 1 || day == 21 || day == 31) {
        strcpy(day_suffix, "st");
    } else if (day == 2 || day == 22) {
        strcpy(day_suffix, "nd");
    } else if (day == 3 || day == 23) {
        strcpy(day_suffix, "rd");
    } else {
        strcpy(day_suffix, "th");
    }

    snprintf(date_in_words, sizeof(date_in_words), "%d%s of %s, %d", day, day_suffix, month_names[month - 1], year);
    return date_in_words;
}

// Function to display the formatted date
void display_date(const char* date_in_words) {
    printf("Formatted Date: %s\n", date_in_words);
    printf("Thank you for using the Date Converter!\n");
}