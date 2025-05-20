//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

const char* months[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

void convertToDate(char *input) {
    int day = 0, month = 0, year = 0;
    char *token;
    
    // Start by parsing the input for day, month, year
    token = strtok(input, " ");
    day = atoi(token); // Day

    token = strtok(NULL, ", "); 
    for (month = 0; month < 12; month++) {
        if (strcasecmp(token, months[month]) == 0) {
            break;
        }
    }
    month++; // Months are 0-indexed, but we want 1-indexed

    token = strtok(NULL, " ");
    year = atoi(token); // Year

    if (day > 0 && day <= 31 && month > 0 && month <= 12) {
        printf("Converted Date: %02d/%02d/%04d\n", day, month, year);
    } else {
        printf("Invalid Date\n");
    }
}

void printCurrentDate() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("Current Date: %02d/%02d/%04d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
}

void displayMenu() {
    printf("\n--- Natural Language Date Converter ---\n");
    printf("1. Convert a natural date format (e.g., 25 December, 2023)\n");
    printf("2. Display current date\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char input[MAX_INPUT_SIZE];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (e.g., 25 December, 2023): ");
                scanf(" %[^\n]", input);
                convertToDate(input);
                break;
            case 2:
                printCurrentDate();
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}