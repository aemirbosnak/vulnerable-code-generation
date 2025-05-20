//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_YEARS 10000

struct TimeMachine {
    int currentYear;
    char destination[50];
};

void initTimeMachine(struct TimeMachine *tm);
void displayInstructions();
void travelInTime(struct TimeMachine *tm);
void showCurrentStatus(struct TimeMachine *tm);
void setDestination(struct TimeMachine *tm);
const char* getYearEvent(int year);

int main() {
    struct TimeMachine myTimeMachine;
    initTimeMachine(&myTimeMachine);
    
    int choice;

    while (1) {
        displayInstructions();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showCurrentStatus(&myTimeMachine);
                break;
            case 2:
                setDestination(&myTimeMachine);
                break;
            case 3:
                travelInTime(&myTimeMachine);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void initTimeMachine(struct TimeMachine *tm) {
    tm->currentYear = 2023; // Starting year
    strcpy(tm->destination, "Present");
}

void displayInstructions() {
    printf("\n*** Time Travel Simulator ***\n");
    printf("1. Show current year and status\n");
    printf("2. Set time travel destination\n");
    printf("3. Travel through time\n");
    printf("4. Exit\n");
}

void showCurrentStatus(struct TimeMachine *tm) {
    printf("Current year: %d\n", tm->currentYear);
    printf("Current destination: %s\n", tm->destination);
}

void setDestination(struct TimeMachine *tm) {
    int year;  
    printf("Enter the year you want to travel to (0 to 9999): ");
    scanf("%d", &year);
    
    if (year < 0 || year > MAX_YEARS) {
        printf("Invalid year. Choose a year between 0 and %d.\n", MAX_YEARS);
    } else {
        tm->currentYear = year;
        sprintf(tm->destination, "%d", year);
        printf("Destination set to %s.\n", tm->destination);
    }
}

void travelInTime(struct TimeMachine *tm) {
    printf("Traveling to the year %d...\n", tm->currentYear);
    printf("You have arrived at %d!\n", tm->currentYear);
    printf("Event: %s\n", getYearEvent(tm->currentYear));
}

const char* getYearEvent(int year) {
    if (year % 100 == 0 && year % 400 == 0) {
        return "It's a leap year!";
    } else if (year % 4 == 0) {
        return "It's a leap year!";
    } else {
        return "Nothing particular happened.";
    }
}