//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_MACHINE_MODEL "Quantum Leap 2.0"
#define MAX_YEAR 3000
#define MIN_YEAR 1900

void displayMenu();
void travelToYear(int year);
void initializeTimeMachine();
void addYears(int *currentYear, int add);
void goToPresent(int *currentYear);

int main() {
    int currentYear = 2023;
    int choice, year;

    initializeTimeMachine();

    while (1) {
        displayMenu();
        printf("Current Year: %d\n", currentYear);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter year to travel to (%d - %d): ", MIN_YEAR, MAX_YEAR);
                scanf("%d", &year);
                if (year >= MIN_YEAR && year <= MAX_YEAR) {
                    travelToYear(year);
                    currentYear = year;
                } else {
                    printf("Invalid year!\n");
                }
                break;

            case 2:
                addYears(&currentYear, 10);
                printf("Traveled forward 10 years.\n");
                break;

            case 3:
                addYears(&currentYear, -10);
                printf("Traveled backward 10 years.\n");
                break;

            case 4:
                goToPresent(&currentYear);
                printf("Back to the present year: %d.\n", currentYear);
                break;

            case 5:
                printf("Exiting time travel simulator. Safe travels!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

void initializeTimeMachine() {
    printf("Initializing the %s...\n", TIME_MACHINE_MODEL);
    printf("Time machine ready. Ensure your lifelines are properly set!\n");
}

void displayMenu() {
    printf("=== Time Travel Simulator ===\n");
    printf("1. Travel to a specific year\n");
    printf("2. Travel forward 10 years\n");
    printf("3. Travel backward 10 years\n");
    printf("4. Return to the present\n");
    printf("5. Exit\n");
}

void travelToYear(int year) {
    printf("Setting coordinates to %d...\n", year);
    printf("Warping through time!\n");
    // Simulated delay
    for (int i = 0; i < 3; i++) {
        printf("... Traveling...\n");
        sleep(1);
    }
    printf("Welcome to the year %d.\n", year);
}

void addYears(int *currentYear, int add) {
    *currentYear += add;
    if (*currentYear < MIN_YEAR) {
        *currentYear = MIN_YEAR;
    } else if (*currentYear > MAX_YEAR) {
        *currentYear = MAX_YEAR;
    }
}

void goToPresent(int *currentYear) {
    *currentYear = 2023;
}