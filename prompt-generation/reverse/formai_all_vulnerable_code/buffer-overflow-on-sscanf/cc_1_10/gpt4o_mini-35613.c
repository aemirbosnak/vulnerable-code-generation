//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MONTHS_IN_YEAR 12

const char *months[MONTHS_IN_YEAR] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0; // Invalid month
    }
}

int parseNaturalLanguageDate(const char *input, Date *date) {
    char month_str[20];
    char day_str[5];
    char year_str[5];
    
    int matched = sscanf(input, "%s %s %s", month_str, day_str, year_str);
    
    if (matched != 3) {
        fprintf(stderr, "Error: Input format is incorrect. Expected format: 'Month Day Year'\n");
        return -1; // Error
    }
    
    // Convert month to integer
    for (int i = 0; i < MONTHS_IN_YEAR; i++) {
        if (strcasecmp(months[i], month_str) == 0) {
            date->month = i + 1; // month should be from 1 to 12
            break;
        }
    }
    
    if (date->month == 0) {
        fprintf(stderr, "Error: Invalid month '%s'\n", month_str);
        return -1; // Error
    }
    
    // Convert day
    date->day = atoi(day_str);
    // Convert year
    date->year = atoi(year_str);

    // Validate the date
    if (date->day < 1 || date->day > getDaysInMonth(date->month, date->year)) {
        fprintf(stderr, "Error: Invalid day '%d' for month '%d' in year '%d'\n", date->day, date->month, date->year);
        return -1; // Error
    }

    return 0; // Success
}

void displayDate(const Date *date) {
    printf("The converted date is: %02d %s %d\n", date->day, months[date->month - 1], date->year);
}

int main() {
    char input[BUFFER_SIZE];
    Date date;

    printf("Enter a date in natural language (e.g., 'January 15 2023'): ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    if (parseNaturalLanguageDate(input, &date) != 0) {
        return EXIT_FAILURE; // Error already printed in the function
    }

    displayDate(&date);
    return EXIT_SUCCESS;
}