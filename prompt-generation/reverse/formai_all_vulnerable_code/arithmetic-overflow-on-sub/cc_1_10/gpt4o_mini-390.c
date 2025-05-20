//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// Function Declarations
void getDate(char *dateString);
void parseDate(char *dateString, struct tm *tm);
void printFormattedDate(struct tm *tm);
void convertCurrentDateToNatural();

int main() {
    int choice;

    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert a specific date\n");
    printf("2. Convert the current date\n");
    printf("3. Exit\n");
    printf("Your choice: ");
    
    while (1) {
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1: {
                char dateInput[MAX_INPUT_LENGTH];
                getDate(dateInput);
                struct tm tmDate;
                parseDate(dateInput, &tmDate);
                printFormattedDate(&tmDate);
                break;
            }
            case 2:
                convertCurrentDateToNatural();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
        printf("\nChoose an option:\n");
        printf("1. Convert a specific date\n");
        printf("2. Convert the current date\n");
        printf("3. Exit\n");
        printf("Your choice: ");
    }
    return 0;
}

void getDate(char *dateString) {
    printf("Enter a date (e.g., '15th of March, 2022' or 'March 15, 2022'): ");
    fgets(dateString, MAX_INPUT_LENGTH, stdin);
    // Remove trailing newline
    dateString[strcspn(dateString, "\n")] = 0;
}

void parseDate(char *dateString, struct tm *tm) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    char monthName[20];
    int day, year;

    // Example: "15th of March, 2022"
    if (sscanf(dateString, "%d of %[^,], %d", &day, monthName, &year) == 3) {
        // Check for month string
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(monthName, months[i]) == 0) {
                tm->tm_mon = i;
                break;
            }
        }
    } 
    // Example: "March 15, 2022"
    else if (sscanf(dateString, "%[^ ] %d, %d", monthName, &day, &year) == 3) {
        for (int i = 0; i < 12; i++) {
            if (strcasecmp(monthName, months[i]) == 0) {
                tm->tm_mon = i;
                break;
            }
        }
    } else {
        printf("Date format not recognized. Please try again.\n");
        exit(1);
    }

    tm->tm_mday = day;
    tm->tm_year = year - 1900; // tm_year is years since 1900
    tm->tm_hour = 0;
    tm->tm_min = 0;
    tm->tm_sec = 0;
    tm->tm_isdst = -1; // Not considering Daylight Saving Time
}

void printFormattedDate(struct tm *tm) {
    char formattedDate[50];
    strftime(formattedDate, sizeof(formattedDate), "%A, %B %d, %Y", tm);
    printf("Formatted Date: %s\n", formattedDate);
}

void convertCurrentDateToNatural() {
    time_t rawtime;
    struct tm *tm;

    time(&rawtime);
    tm = localtime(&rawtime);
    
    printFormattedDate(tm);
}