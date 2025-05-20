//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to get the month number from a month name
int get_month_number(const char *month_name) {
    const char *months[] = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_name, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0; // Invalid month
}

// Function to parse the natural date string
int parse_date(const char *input, int *day, int *month, int *year) {
    char month_name[20];
    if (sscanf(input, "%d %s %d", day, month_name, year) != 3) {
        return -1; // Parsing failed
    }
    to_lowercase(month_name);
    *month = get_month_number(month_name);
    if (*month == 0) {
        return -1; // Invalid month
    }
    return 0; // Parsing succeeded
}

// Function to check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to validate the day of the month
int validate_day(int day, int month, int year) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        if (is_leap_year(year)) {
            days_in_month[2] = 29; // Adjust February for leap year
        }
    }
    return (day > 0 && day <= days_in_month[month]);
}

// Function to convert natural date input to structured date
int convert_date(const char *input) {
    int day, month, year;
    if (parse_date(input, &day, &month, &year) != 0) {
        printf("Error: Invalid date format. Please use '<day> <month> <year>'.\n");
        return -1;
    }
  
    if (!validate_day(day, month, year)) {
        printf("Error: Invalid day %d for month %d in year %d.\n", day, month, year);
        return -1;
    }
  
    // Create a tm structure for date conversion
    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1; // tm_mon is 0-based
    date.tm_year = year - 1900; // tm_year is years since 1900

    // Convert struct tm to time_t
    time_t rawtime = mktime(&date);
    if (rawtime == -1) {
        printf("Error: Unable to convert date to timestamp.\n");
        return -1;
    }
  
    // Display the date in a different format
    char buffer[80];
    strftime(buffer, sizeof(buffer), "The parsed date is: %A, %B %d, %Y.", &date);
    printf("%s\n", buffer);

    return 0; // Success
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a date in the format 'day month year' (e.g., '15 March 2023'):\n");
    fgets(input, sizeof(input), stdin);
  
    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
  
    convert_date(input);
    
    return 0;
}