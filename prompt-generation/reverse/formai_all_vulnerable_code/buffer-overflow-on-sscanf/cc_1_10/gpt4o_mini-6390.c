//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUF 100
#define MAX_MONTHS 12
#define MAX_DAYS 31

const char *months[MAX_MONTHS + 1] = {
    "",  // 0 index unused for simplicity
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

// Struct to hold date components
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month
int getMonthDays(int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

// Function to convert a natural language date to a Date struct
int parseDate(const char *input, Date *date) {
    char monthStr[MAX_BUF];
    int day, year;
    if (sscanf(input, "%s %d, %d", monthStr, &day, &year) != 3) {
        return 0; // Parsing failed
    }
    
    // Convert month string to month number
    for (int i = 1; i <= MAX_MONTHS; i++) {
        if (strcasecmp(months[i], monthStr) == 0) {
            date->month = i;
            break;
        }
    }
    
    if (date->month == 0 || day < 1 || day > getMonthDays(date->month, year)) {
        return 0; // Invalid month or day
    }
    
    date->day = day;
    date->year = year;
    
    return 1; // Parsing succeeded
}

// Function to display date in a formatted manner
void displayDate(const Date *date) {
    printf("Date is: %02d %s, %d\n", date->day, months[date->month], date->year);
}

int main() {
    char input[MAX_BUF];
    Date date;

    printf("Enter a date in natural language (e.g., 'February 21, 2023'): ");
    fgets(input, MAX_BUF, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    if (parseDate(input, &date)) {
        displayDate(&date);
    } else {
        printf("Invalid date format. Please use 'Month Day, Year' format.\n");
    }

    return 0;
}