//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MONTHS_IN_YEAR 12

const char* MONTHS[MONTHS_IN_YEAR] = {
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

// Function to strip non-digit characters
void clean_date_input(const char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i]) || input[i] == ' ' || input[i] == ',') {
            cleaned[j++] = input[i];
        }
    }
    cleaned[j] = '\0';
}

// Function to parse month from user input
int parse_month(const char *month_str) {
    for (int i = 0; i < MONTHS_IN_YEAR; i++) {
        if (strcasecmp(month_str, MONTHS[i]) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

// Function to parse day from user input
int parse_day(const char *day_str) {
    int day = atoi(day_str);
    if (day >= 1 && day <= 31) {
        return day;
    }
    return -1; // Invalid day
}

// Function to parse year from user input
int parse_year(const char *year_str) {
    int year = atoi(year_str);
    if (year > 0) {
        return year;
    }
    return -1; // Invalid year
}

// Function to convert natural language date to formatted date
void convert_date(const char *input, char *output) {
    char cleaned_input[MAX_INPUT_LENGTH];
    clean_date_input(input, cleaned_input);
    
    char month_str[20], day_str[20], year_str[20];
    sscanf(cleaned_input, "%s %s %s", month_str, day_str, year_str);
    
    int month = parse_month(month_str);
    int day = parse_day(day_str);
    int year = parse_year(year_str);
    
    if (month != -1 && day != -1 && year != -1) {
        sprintf(output, "%04d-%02d-%02d", year, month, day);
    } else {
        sprintf(output, "Invalid date");
    }
}

// Function to display the converted date
void display_date(const char *formatted_date) {
    printf("Converted Date: %s\n", formatted_date);
}

// Function to handle user input and conversion
void handle_user_input() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    
    printf("Enter a date (e.g. March 15th, 2023): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    convert_date(input, output);
    display_date(output);
}

// Main function
int main() {
    printf("Natural Language Date Converter\n");
    handle_user_input();
    return 0;
}