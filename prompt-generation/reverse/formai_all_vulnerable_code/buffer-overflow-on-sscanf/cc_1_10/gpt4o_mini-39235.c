//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_MONTH_LENGTH 20

const char* months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int getMonthNumber(const char *month) {
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month, months[i]) == 0) {
            return i + 1;
        }
    }
    return -1; // Invalid month
}

int getDayOfMonth(int month, int year) {
    if (month < 1 || month > 12) return -1;

    // Days in each month
    int daysPerMonth[] = { 31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31 };

    // Leap year adjustment for February
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysPerMonth[1] = 29;
    }

    return daysPerMonth[month - 1];
}

void convertDate(const char *inputDate) {
    int day, month, year;
    char monthStr[MAX_MONTH_LENGTH];

    // Check for format: "Day Month Year" (e.g., "22 January 2023")
    if (sscanf(inputDate, "%d %s %d", &day, monthStr, &year) == 3) {
        month = getMonthNumber(monthStr);
        if (month == -1 || day < 1 || day > getDayOfMonth(month, year)) {
            printf("Invalid date format or values: %s\n", inputDate);
            return;
        }
        printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
        return;
    }

    // Check for format: "Month Day, Year" (e.g., "January 22, 2023")
    if (sscanf(inputDate, "%s %d, %d", monthStr, &day, &year) == 3) {
        month = getMonthNumber(monthStr);
        if (month == -1 || day < 1 || day > getDayOfMonth(month, year)) {
            printf("Invalid date format or values: %s\n", inputDate);
            return;
        }
        printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
        return;
    }

    // Check for format: "Year-Month-Day" (e.g., "2023-01-22")
    if (sscanf(inputDate, "%d-%d-%d", &year, &month, &day) == 3) {
        if (month < 1 || month > 12 || day < 1 || day > getDayOfMonth(month, year)) {
            printf("Invalid date format or values: %s\n", inputDate);
            return;
        }
        printf("Converted Date: %04d-%02d-%02d\n", year, month, day);
        return;
    }

    printf("Unsupported date format: %s\n", inputDate);
}

int main() {
    char inputDate[MAX_INPUT_SIZE];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date (examples: \"22 January 2023\", \"January 22, 2023\", \"2023-01-22\"):\n");

    while (1) {
        printf("> ");
        if (fgets(inputDate, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("Error reading input. Exiting...\n");
            break;
        }

        // Remove newline character from input
        size_t len = strlen(inputDate);
        if (len > 0 && inputDate[len - 1] == '\n') {
            inputDate[len - 1] = '\0';
        }

        if (strcasecmp(inputDate, "exit") == 0) {
            printf("Exiting the Date Converter. Goodbye!\n");
            break;
        }

        convertDate(inputDate);
    }

    return 0;
}