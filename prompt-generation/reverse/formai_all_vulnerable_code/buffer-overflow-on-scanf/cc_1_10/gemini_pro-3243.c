//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
// In the desolate wasteland, where code echoes the remnants of a forgotten world...

#include <stdio.h>
#include <stdlib.h>

// Radiated Quantities:
int ammo, food, water;

// Scavenger's Toolkit:
void gather_resources(int* ammo, int* food, int* water) {
    printf("Raiding the ruins for sustenance...\n");
    *ammo += rand() % 5;
    *food += rand() % 10;
    *water += rand() % 3;
}

// Survival Calculator:
void calculate_survival_time(int ammo, int food, int water) {
    int days_ammo = ammo / 3;
    int days_food = food / 5;
    int days_water = water / 2;

    printf("Estimated survival time:\n");
    if (days_ammo <= days_food && days_ammo <= days_water) {
        printf("  Ammo: %d days\n", days_ammo);
    } else if (days_food <= days_ammo && days_food <= days_water) {
        printf("  Food: %d days\n", days_food);
    } else {
        printf("  Water: %d days\n", days_water);
    }
}

// Lone Wanderer's Journey:
int main() {
    // Initializing the wasteland:
    ammo = rand() % 50;
    food = rand() % 100;
    water = rand() % 50;

    printf("\nGreetings, weary traveler.\n");
    printf("In this desolate wasteland, your survival hinges on gathering resources and managing your supplies.\n");

    int choice;
    while (1) {
        printf("\nChoose your perilous path:\n");
        printf("1. Scavenge for resources\n");
        printf("2. Check survival time\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                gather_resources(&ammo, &food, &water);
                printf("Supplies: Ammo: %d, Food: %d, Water: %d\n", ammo, food, water);
                break;
            case 2:
                calculate_survival_time(ammo, food, water);
                break;
            case 3:
                printf("May your wandering lead you towards a glimmer of hope in the darkness.\n");
                return 0;
            default:
                printf("Invalid choice. Choose wisely, survivor.");
        }
    }
}