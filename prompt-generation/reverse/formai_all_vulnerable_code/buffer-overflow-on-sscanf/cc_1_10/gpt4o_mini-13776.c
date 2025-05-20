//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Post-Apocalyptic Date Converter
// A program to interpret dates in a world where the calendar is forgotten.

#define BUFFER_SIZE 50
#define MAX_MONTHS 12
#define MAX_DAYS 31

const char *months[MAX_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 0: return 31; // January
        case 1: return isLeapYear(year) ? 29 : 28; // February
        case 2: return 31; // March
        case 3: return 30; // April
        case 4: return 31; // May
        case 5: return 30; // June
        case 6: return 31; // July
        case 7: return 31; // August
        case 8: return 30; // September
        case 9: return 31; // October
        case 10: return 30; // November
        case 11: return 31; // December
        default: return 0;
    }
}

// Translate the desolate survivor's date format into Gregorian calendar
void convertPostApocalypticDate(char *inputDate) {
    int day, month, year;
    sscanf(inputDate, "%d-%d-%d", &day, &month, &year); // Expect input in "day-month-year"

    if (month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month - 1, year)) {
        printf("Error: Invalid date %s in the wasteland.\n", inputDate);
        return;
    }

    // Convert to proper format
    printf("You have found a date reference: %s\n", inputDate);
    printf("Translated Date: %s %d, %d\n", months[month - 1], day, year);
}

int main() {
    char input[BUFFER_SIZE];
    printf("=== Wasteland Date Converter ===\n");
    printf("Enter the date in the format 'day-month-year' (e.g., '5-11-2032'):\n");
    
    while (1) {
        printf("Input: ");
        fgets(input, BUFFER_SIZE, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (input[0] == '\0') {
            printf("Exiting the date converter.\n");
            break; // Exit on empty input
        }

        convertPostApocalypticDate(input);
        printf("\n");
    }

    return 0;
}