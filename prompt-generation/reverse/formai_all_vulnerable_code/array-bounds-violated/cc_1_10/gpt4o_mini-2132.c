//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 256
#define MAX_DATE_SIZE 30

const char *months[] = {
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
        default: return 0;
    }
}

void printDate(Date date) {
    printf("%s %d, %d\n", months[date.month - 1], date.day, date.year);
}

int parseDate(const char *input, Date *date) {
    char monthStr[MAX_INPUT_SIZE];
    int day, year;
    int numScanned = sscanf(input, "%s %d, %d", monthStr, &day, &year);
    
    if (numScanned != 3) {
        return -1; // Invalid format
    }

    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            date->month = i + 1;
            date->day = day;
            date->year = year;
            return 0;
        }
    }
    return -2; // Month not found
}

int validateDate(Date date) {
    if (date.year < 1) return -1; // Invalid year
    if (date.month < 1 || date.month > 12) return -2; // Invalid month
    if (date.day < 1 || date.day > getDaysInMonth(date.month, date.year)) return -3; // Invalid day
    return 0; // Valid date
}

void getCurrentDate(Date *currentDate) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    currentDate->year = timeinfo->tm_year + 1900;
    currentDate->month = timeinfo->tm_mon + 1;
    currentDate->day = timeinfo->tm_mday;
}

int main() {
    char input[MAX_INPUT_SIZE];
    Date date;
    Date currentDate;
    
    getCurrentDate(&currentDate);

    printf("Current Date: ");
    printDate(currentDate);

    while (1) {
        printf("Enter a date (e.g., January 12, 2023) or 'quit' to exit: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';
        
        if (strcasecmp(input, "quit") == 0) {
            break;
        }

        int parseResult = parseDate(input, &date);
        if (parseResult != 0) {
            if (parseResult == -1) {
                printf("Error: Invalid date format. Please try again.\n");
            } else if (parseResult == -2) {
                printf("Error: Month not recognized. Please enter a valid month name.\n");
            }
            continue;
        }

        int validateResult = validateDate(date);
        if (validateResult != 0) {
            switch (validateResult) {
                case -1:
                    printf("Error: Invalid year. Please enter a positive year.\n");
                    break;
                case -2:
                    printf("Error: Invalid month. Month must be between 1 and 12.\n");
                    break;
                case -3:
                    printf("Error: Invalid day. The day does not exist in the given month.\n");
                    break;
            }
            continue;
        }
        
        printf("You entered a valid date: ");
        printDate(date);
    }
    
    printf("Exiting the program. Goodbye!\n");
    return 0;
}