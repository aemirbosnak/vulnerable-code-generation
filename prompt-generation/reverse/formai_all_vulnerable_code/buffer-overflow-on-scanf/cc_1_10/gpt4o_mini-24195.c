//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Choose a destination:\n");
    printf("1. The Year 2025\n");
    printf("2. The Year 2050\n");
    printf("3. The Year 3000\n");
    printf("4. The Year 10000\n");
    printf("5. Exit\n");
}

void travelToYear(int year) {
    switch (year) {
        case 2025:
            printf("You travel to the year 2025.\n");
            printf("Flying cars and AI companions are now part of daily life!\n");
            break;
        case 2050:
            printf("You travel to the year 2050.\n");
            printf("Humans have established colonies on Mars and climate change has reversed.\n");
            break;
        case 3000:
            printf("You travel to the year 3000.\n");
            printf("Intergalactic travel is routine, and you're greeted by aliens!\n");
            break;
        case 10000:
            printf("You travel to the year 10000.\n");
            printf("Humanity has transcended physical forms; minds are connected in a shared consciousness.\n");
            break;
        default:
            printf("That's not a valid year!\n");
    }
}

void timeTravelSimulator() {
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            travelToYear(2025 + (choice - 1) * 25 * (choice != 4) + (choice == 4) * 7000);
        } else if (choice == 5) {
            printf("Exiting the Time Travel Simulator. Safe travels!\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        // Add a delay for dramatic effect
        printf("Preparing to travel...\n");
        for(int i = 0; i < 3; i++) {
            printf(". ");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
    }
}

int main() {
    timeTravelSimulator();
    return 0;
}