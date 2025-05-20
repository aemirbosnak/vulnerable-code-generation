//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void setTime(int *year, int *month, int *day);
void timeTravel(int year, int month, int day);
void displayCurrentDate();

// Global variables to store the current date
int currentYear, currentMonth, currentDay;

// Function to display the menu options
void displayMenu() {
    printf("\n----- Time Travel Simulator -----\n");
    printf("1. Set Current Time\n");
    printf("2. Time Travel\n");
    printf("3. Display Current Date\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to set the current time
void setTime(int *year, int *month, int *day) {
    printf("Enter year (e.g., 2023): ");
    scanf("%d", year);
    printf("Enter month (1-12): ");
    scanf("%d", month);
    printf("Enter day (1-31): ");
    scanf("%d", day);
}

// Function to perform time travel
void timeTravel(int year, int month, int day) {
    if ((year < 0 || month < 1 || month > 12 || day < 1 || day > 31) || 
        (month == 2 && day > 29) || 
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        printf("Invalid date entered. Time travel failed.\n");
        return;
    }

    printf("Initiating time travel to %04d-%02d-%02d...\n", year, month, day);
    
    // Simulating time travel with a delay
    for (int i = 3; i > 0; i--) {
        printf("Time traveling in %d...\n", i);
        sleep(1);
    }

    printf("Arrived in the future: %04d-%02d-%02d\n", year, month, day);
}

// Function to display the current date
void displayCurrentDate() {
    printf("Current Date: %04d-%02d-%02d\n", currentYear, currentMonth, currentDay);
}

int main() {
    int option;
    currentYear = 2023; // Default year
    currentMonth = 10;   // Default month
    currentDay = 1;      // Default day

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                setTime(&currentYear, &currentMonth, &currentDay);
                break;
            case 2:
                timeTravel(currentYear, currentMonth, currentDay);
                break;
            case 3:
                displayCurrentDate();
                break;
            case 4:
                printf("Exiting Time Travel Simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}