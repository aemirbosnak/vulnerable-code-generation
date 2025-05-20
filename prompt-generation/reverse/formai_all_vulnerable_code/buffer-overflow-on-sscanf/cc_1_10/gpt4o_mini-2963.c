//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_MONTHS 12
#define MAX_DAYS_IN_MONTH 31

const char *months[MAX_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const int daysInMonths[MAX_MONTHS] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

// Function prototypes
int isLeapYear(int year);
void printFormattedDate(const char *dateString);
void convertDateInput(const char *inputDate);

int main() {
    char inputDate[BUFFER_SIZE];

    printf("=== Donald Knuth's Natural Language Date Converter ===\n");
    printf("Please enter a date (e.g., 'August 5, 2023'): ");
    fgets(inputDate, BUFFER_SIZE, stdin);
    
    // Remove newline character if present
    inputDate[strcspn(inputDate, "\n")] = '\0';

    convertDateInput(inputDate);
    
    return 0;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void convertDateInput(const char *inputDate) {
    char month[BUFFER_SIZE];
    int day, year;
    
    if (sscanf(inputDate, "%s %d, %d", month, &day, &year) != 3) {
        printf("Error: Input format is incorrect. Please use 'Month Day, Year'.\n");
        return;
    }

    int monthIndex = -1;
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (strcasecmp(months[i], month) == 0) {
            monthIndex = i;
            break;
        }
    }

    if (monthIndex == -1) {
        printf("Error: Month '%s' is not valid.\n", month);
        return;
    }

    // Adjust for leap years
    int maxDays = daysInMonths[monthIndex];
    if (monthIndex == 1 && isLeapYear(year)) {
        maxDays = 29; // February in a leap year
    }
    
    if (day < 1 || day > maxDays) {
        printf("Error: Day '%d' is not valid for month '%s'.\n", day, months[monthIndex]);
        return;
    }

    printf("You entered a valid date: %02d-%02d-%d\n", day, monthIndex + 1, year);
    printf("Formatted Date: %s %d, %d\n", months[monthIndex], day, year);
}