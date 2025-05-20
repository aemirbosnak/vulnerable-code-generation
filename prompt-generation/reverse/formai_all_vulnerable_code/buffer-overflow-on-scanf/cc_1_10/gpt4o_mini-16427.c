//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void displayMenu();
void timeTravel(int year);
void createTimeMachine();
void viewTimeMachineStatus();
void travelToYear(int year);

typedef struct {
    int travelYear;
    int fuel;
    int isActivated;
} TimeMachine;

TimeMachine tm;

int main() {
    tm.isActivated = 0; // Time machine is initially deactivated
    tm.fuel = 100;      // Full fuel tank
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createTimeMachine();
                break;
            case 2:
                viewTimeMachineStatus();
                break;
            case 3:
                if (tm.isActivated) {
                    printf("Where would you like to travel? (Year): ");
                    int year;
                    scanf("%d", &year);
                    timeTravel(year);
                } else {
                    printf("The time machine is not activated!\n");
                }
                break;
            case 4:
                printf("Exiting Time Travel Simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Create/Activate Time Machine\n");
    printf("2. View Time Machine Status\n");
    printf("3. Time Travel\n");
    printf("4. Exit\n");
}

void createTimeMachine() {
    if (tm.isActivated) {
        printf("Time machine is already activated!\n");
    } else {
        printf("Creating Time Machine...\n");
        tm.isActivated = 1;
        printf("Time Machine activated with full fuel!\n");
    }
}

void viewTimeMachineStatus() {
    printf("Time Machine Status:\n");
    printf("Activated: %s\n", tm.isActivated ? "Yes" : "No");
    printf("Fuel Level: %d%%\n", tm.fuel);
    printf("Current Year: %d\n", tm.travelYear);
}

void timeTravel(int year) {
    if (tm.fuel <= 0) {
        printf("Not enough fuel to travel!\n");
        return;
    }
    if (year < 1900 || year > 2100) {
        printf("Year out of range! Please choose a year between 1900 and 2100.\n");
        return;
    }
    
    printf("Ready to travel to the year %d...\n", year);
    // Simulating the time travel effect
    for (int i = 0; i < 5; i++) {
        printf("Engaging time warp... %d...\n", 5 - i);
        sleep(1);
    }
    
    tm.travelYear = year;
    tm.fuel -= 20; // Each travel costs 20% of fuel
    printf("Time travel successful! Welcome to the year %d!\n", tm.travelYear);
    
    // Provide an experience based on the year
    travelToYear(year);
}

void travelToYear(int year) {
    switch (year) {
        case 1900:
            printf("You've arrived in the dawn of the 20th century!\n");
            printf("You see horse-drawn carriages and hear the newsboys shouting headlines.\n");
            break;
        case 1950:
            printf("Welcome to the post-war era!\n");
            printf("You can smell fresh donuts from the diner nearby and hear jazz on the radio.\n");
            break;
        case 2000:
            printf("You are in the turn of the millennium!\n");
            printf("People are celebrating Y2K, fireworks fill the sky!\n");
            break;
        case 2020:
            printf("You've reached the year of global pandemic.\n");
            printf("Everyone is wearing masks and social distancing.\n");
            break;
        case 2100:
            printf("Welcome to the future!\n");
            printf("You see flying cars and artificial intelligence walking alongside humans!\n");
            break;
        default:
            printf("This year is rather quiet. Only crickets can be heard...\n");
            break;
    }
}