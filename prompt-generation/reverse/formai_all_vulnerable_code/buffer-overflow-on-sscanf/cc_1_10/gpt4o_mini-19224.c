//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATE_LEN 100
#define MAX_MONTHS 12

const char *months[MAX_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

typedef struct {
    int day;
    int month; // 1-12
    int year;
} Date;

void printGreeting() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("You can input a date in natural language format.\n");
    printf("Example formats: 'January 1, 2023', '1st of February, 2022'\n");
}

int monthToInt(const char *month) {
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // Months are 1-indexed
        }
    }
    return -1; // Invalid month
}

int isValidDate(Date date) {
    if (date.year < 1) {
        return 0;
    }
    if (date.month < 1 || date.month > 12) {
        return 0;
    }
    if (date.day < 1 || date.day > 31) {
        return 0;
    }
    // Check for month-specific days
    if (date.month == 2) {
        int leapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
        return date.day <= (leapYear ? 29 : 28);
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        return date.day <= 30;
    }
    return 1; // Valid date
}

Date parseDate(const char *input) {
    Date date;
    char monthStr[MAX_DATE_LEN];
    int day, year;

    // Example formats we'll try to extract:
    // - '1st of January, 2023'
    // - 'January 1, 2023'
    
    if (sscanf(input, "%d of %99[^,], %d", &day, monthStr, &year) == 3) {
        date.day = day;
        date.month = monthToInt(monthStr);
        date.year = year;
    } else if (sscanf(input, "%99[^,] %d", monthStr, &year) == 2) {
        // Handle cases like 'January 2023'
        date.month = monthToInt(monthStr);
        date.day = 1; // Default day 1
        date.year = year;
    } else if (sscanf(input, "%d %99[^,], %d", &day, monthStr, &year) == 3) {
        date.day = day;
        date.month = monthToInt(monthStr);
        date.year = year;
    } else {
        date.day = -1; // Indicating an error
        date.month = -1;
        date.year = -1;
    }
    return date;
}

void displayDate(const Date date) {
    if (isValidDate(date)) {
        printf("Converted Date: %d %s %d\n", date.day, months[date.month - 1], date.year);
    } else {
        printf("Error: Invalid date provided.\n");
    }
}

int main() {
    char input[MAX_DATE_LEN];

    printGreeting();
    
    printf("Please enter a date: ");
    fgets(input, MAX_DATE_LEN, stdin);
    
    // Trim newline character from fgets
    input[strcspn(input, "\n")] = 0;

    Date date = parseDate(input);
    
    displayDate(date);

    printf("Thank you for using the Natural Language Date Converter!\n");
    
    return 0;
}