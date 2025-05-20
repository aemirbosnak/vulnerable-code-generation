//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_DATE_LENGTH 20

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int get_month_number(const char *month) {
    if (strcmp(month, "january") == 0) return 1;
    if (strcmp(month, "february") == 0) return 2;
    if (strcmp(month, "march") == 0) return 3;
    if (strcmp(month, "april") == 0) return 4;
    if (strcmp(month, "may") == 0) return 5;
    if (strcmp(month, "june") == 0) return 6;
    if (strcmp(month, "july") == 0) return 7;
    if (strcmp(month, "august") == 0) return 8;
    if (strcmp(month, "september") == 0) return 9;
    if (strcmp(month, "october") == 0) return 10;
    if (strcmp(month, "november") == 0) return 11;
    if (strcmp(month, "december") == 0) return 12;
    return -1;
}

int parse_date(const char *natural_date, struct tm *date) {
    char month[MAX_DATE_LENGTH];
    int day, year;

    // Parse the natural language date
    int matched = sscanf(natural_date, "%d %s %d", &day, month, &year);
    if (matched != 3) {
        return 0; // Invalid format
    }

    // Convert month to number
    to_lower_case(month);
    int month_number = get_month_number(month);
    if (month_number == -1) {
        return 0; // Invalid month
    }

    // Fill the tm structure with parsed values
    date->tm_mday = day;
    date->tm_mon = month_number - 1; // tm_mon is zero-based
    date->tm_year = year - 1900; // tm_year is years since 1900
    
    // Validation
    if (day < 1 || day > 31 || month_number < 1 || month_number > 12 || year < 1900) {
        return 0; // Invalid date components
    }

    // Normalize the tm structure to ensure a valid date
    if (mktime(date) == -1) {
        return 0; // Failed to create a valid date
    }

    return 1; // Successfully parsed date
}

void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("Converted Date: %s\n", buffer);
}

int main() {
    char natural_date[MAX_LINE_LENGTH];
    struct tm date = {0}; // Initialize to zero

    printf("Enter a date in the format 'DD Month YYYY': \n");

    // Get the user's input
    if (fgets(natural_date, sizeof(natural_date), stdin) == NULL) {
        fprintf(stderr, "Error reading input!\n");
        return EXIT_FAILURE;
    }

    // Remove newline character from the input
    natural_date[strcspn(natural_date, "\n")] = 0;

    // Try to parse the date
    if (parse_date(natural_date, &date)) {
        print_date(&date);
    } else {
        fprintf(stderr, "Invalid date format. Please use 'DD Month YYYY'.\n");
    }

    return 0;
}