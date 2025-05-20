//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_STRING_LENGTH 100
#define MAX_MONTH_LENGTH 20
#define MAX_DAY_LENGTH 3
#define MAX_YEAR_LENGTH 5

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

const char *MONTHS[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31; // January
        case 2: return isLeapYear(year) ? 29 : 28; // February
        case 3: return 31; // March
        case 4: return 30; // April
        case 5: return 31; // May
        case 6: return 30; // June
        case 7: return 31; // July
        case 8: return 31; // August
        case 9: return 30; // September
        case 10: return 31; // October
        case 11: return 30; // November
        case 12: return 31; // December
        default: return 0; // Invalid month
    }
}

int extractDateComponents(const char *dateString, Date *date) {
    char monthString[MAX_MONTH_LENGTH];
    int day = 0, year = 0;
    int scanned = sscanf(dateString, "%s %d, %d", monthString, &day, &year);

    if (scanned != 3) {
        return -1; // Failed to parse the date
    }

    // Convert month name to month number
    for (int month = 0; month < 12; month++) {
        if (strcasecmp(monthString, MONTHS[month]) == 0) {
            date->month = month + 1; // Month stored as 1-indexed
            break;
        }
    }

    // Validate date components
    if (date->month < 1 || date->month > 12 || day < 1 || year < 1 || day > daysInMonth(date->month, year)) {
        return -1; // Invalid date values
    }

    date->day = day;
    date->year = year;

    return 0; // Successfully parsed
}

void convertAndPrintDate(const char *dateString) {
    Date date;

    if (extractDateComponents(dateString, &date) == 0) {
        printf("Input Date: %s\n", dateString);
        printf("Converted Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
    } else {
        printf("Error: Invalid date format. Please enter date as 'Month Day, Year'.\n");
    }
}

int main() {
    char dateString[MAX_DATE_STRING_LENGTH];

    printf("Enter a date in the format 'Month Day, Year' (e.g., 'January 1, 2023'):\n");
    
    while (fgets(dateString, sizeof(dateString), stdin) != NULL) {
        dateString[strcspn(dateString, "\n")] = '\0'; // Remove newline character
        if (strlen(dateString) == 0) {
            break; // Exit on empty input
        }
        convertAndPrintDate(dateString);
        printf("\nEnter another date (or just press Enter to quit):\n");
    }

    printf("Goodbye!\n");
    return 0;
}