//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

const char* months[] = {
    "January", "February", "March", "April", 
    "May", "June", "July", "August", 
    "September", "October", "November", "December"
};

int getMonthIndex(const char* month) {
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            return i + 1; // Month is 1-indexed
        }
    }
    return -1; // Invalid month
}

void displayHelp() {
    printf("Usage: ./date_converter \"<Date String>\"\n");
    printf("Supported format: <Day> <Month> <Year> (e.g., 12 January 2023)\n");
    printf("Examples:\n");
    printf("  \"12 January 2023\"\n");
    printf("  \"29 February 2024\" (Leap year)\n");
    printf("Note: Please ensure to use the correct spacing and capitalization.\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

void convertDate(const char* input) {
    int day, month, year;
    
    char monthName[20];
    if (sscanf(input, "%d %s %d", &day, monthName, &year) != 3) {
        printf("Invalid date format. Please try again.\n");
        return;
    }

    month = getMonthIndex(monthName);
    if (month == -1) {
        printf("Invalid month name. Please try again.\n");
        return;
    }

    if (day < 1 || day > getDaysInMonth(month, year)) {
        printf("Invalid day for the given month/year. Please try again.\n");
        return;
    }

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1; // tm_mon is 0-indexed
    date.tm_year = year - 1900; // tm_year is year since 1900

    char formattedDate[50];
    strcpy(formattedDate, asctime(&date));
    formattedDate[strlen(formattedDate) - 1] = '\0'; // Remove newline

    printf("Converted date: %s\n", formattedDate);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        displayHelp();
        return EXIT_FAILURE;
    }

    char* input = argv[1];
    convertDate(input);

    return EXIT_SUCCESS;
}