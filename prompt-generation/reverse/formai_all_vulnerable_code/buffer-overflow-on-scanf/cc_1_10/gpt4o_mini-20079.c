//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayMenu();
void convertToNaturalLanguage(char *date);
int isValidDate(int day, int month, int year);
void getCurrentDate(char *output);

// Helper macros
#define BUFFER_SIZE 256

int main(void) {
    char inputDate[BUFFER_SIZE];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a date in 'YYYY-MM-DD' format: ");
                fgets(inputDate, BUFFER_SIZE, stdin);
                inputDate[strcspn(inputDate, "\n")] = 0; // Remove newline
                convertToNaturalLanguage(inputDate);
                break;

            case 2: {
                char currentDate[BUFFER_SIZE];
                getCurrentDate(currentDate);
                printf("Current Date is: %s\n", currentDate);
                break;
            }

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n~~~~ Natural Language Date Converter ~~~~\n");
    printf("1. Convert a date to natural language\n");
    printf("2. Show the current date\n");
    printf("3. Exit\n");
}

void convertToNaturalLanguage(char *date) {
    int year, month, day;
    char *monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    // Parse the input date
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3 || !isValidDate(day, month, year)) {
        printf("Invalid date format! Please ensure it's 'YYYY-MM-DD'.\n");
        return;
    }

    // Convert to natural language
    printf("Natural Language Representation: %s %d, %d\n", monthNames[month - 1], day, year);
}

int isValidDate(int day, int month, int year) {
    // Validate the month
    if (month < 1 || month > 12) {
        return 0;
    }

    // Validate the day based on the month
    int daysInMonth;
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if (day < 1 || day > daysInMonth) {
        return 0;
    }

    return 1;
}

void getCurrentDate(char *output) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(output, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}