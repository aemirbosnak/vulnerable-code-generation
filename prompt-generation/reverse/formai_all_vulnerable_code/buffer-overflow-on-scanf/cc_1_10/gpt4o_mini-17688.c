//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRAVEL_YEARS 10000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date currentDate;
    int travelHistory[MAX_TRAVEL_YEARS][3]; // Store year, month, day for travel history
    int travelCount;
} TimeMachine;

void initializeTimeMachine(TimeMachine *tm, int year, int month, int day) {
    tm->currentDate.year = year;
    tm->currentDate.month = month;
    tm->currentDate.day = day;
    tm->travelCount = 0;
}

void displayCurrentDate(TimeMachine *tm) {
    printf("Current Date: %04d-%02d-%02d\n", tm->currentDate.year, tm->currentDate.month, tm->currentDate.day);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0;
    }
}

int travelToDate(TimeMachine *tm, int year, int month, int day) {
    if (tm->travelCount >= MAX_TRAVEL_YEARS) {
        printf("Travel history is full!\n");
        return 0;
    }

    // Validate the date
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        printf("Invalid date! Travel aborted.\n");
        return 0;
    }

    // Record travel history
    tm->travelHistory[tm->travelCount][0] = tm->currentDate.year;
    tm->travelHistory[tm->travelCount][1] = tm->currentDate.month;
    tm->travelHistory[tm->travelCount][2] = tm->currentDate.day;
    tm->travelCount++;

    // Update current date
    tm->currentDate.year = year;
    tm->currentDate.month = month;
    tm->currentDate.day = day;

    return 1;
}

void displayTravelHistory(TimeMachine *tm) {
    printf("Travel History:\n");
    for (int i = 0; i < tm->travelCount; i++) {
        printf("%d. %04d-%02d-%02d\n", i + 1, tm->travelHistory[i][0], tm->travelHistory[i][1], tm->travelHistory[i][2]);
    }
}

void menu() {
    printf("=== Time Travel Simulator ===\n");
    printf("1. Display Current Date\n");
    printf("2. Travel to a Specific Date\n");
    printf("3. Display Travel History\n");
    printf("4. Exit\n");
}

int main() {
    TimeMachine timeMachine;
    int choice, year, month, day;
    
    initializeTimeMachine(&timeMachine, 2023, 10, 1); // Initialize to current date

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCurrentDate(&timeMachine);
                break;
            case 2:
                printf("Enter year, month, day (YYYY MM DD): ");
                scanf("%d %d %d", &year, &month, &day);
                if (travelToDate(&timeMachine, year, month, day)) {
                    printf("Travel successful!\n");
                }
                break;
            case 3:
                displayTravelHistory(&timeMachine);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}