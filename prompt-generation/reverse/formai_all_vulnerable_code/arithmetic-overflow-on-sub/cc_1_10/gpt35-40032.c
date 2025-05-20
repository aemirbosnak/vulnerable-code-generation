//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Spaceship {
    char name[20];
    int fuel;
    int health;
};

void travel(struct Spaceship* ship, int lightyears) {
    int fuel_needed = lightyears * 10;

    if (ship->fuel < fuel_needed) {
        printf("Not enough fuel to travel %d lightyears!\n", lightyears);
    }
    else {
        ship->fuel -= fuel_needed;
        printf("Traveling %d lightyears...\n", lightyears);
        printf("Arrived at destination!\n");
    }

    ship->health -= (lightyears * 2);
    if (ship->health <= 0) {
        printf("Spaceship has been destroyed!\n");
        exit(0);
    }
}

int main() {
    printf("Welcome to the Procedural Space Adventure!\n\n");

    struct Spaceship my_ship;
    strcpy(my_ship.name, "The Maverick");
    my_ship.fuel = 100;
    my_ship.health = 100;

    printf("Your spaceship, %s, has %d fuel and %d health.\n\n", my_ship.name, my_ship.fuel, my_ship.health);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Travel to a planet\n");
        printf("2. Refuel the spaceship\n");
        printf("3. Exit the game\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many lightyears do you want to travel?\n");
                int lightyears;
                scanf("%d", &lightyears);
                travel(&my_ship, lightyears);
                break;

            case 2:
                my_ship.fuel = 100;
                printf("Spaceship has been refueled!\n");
                break;

            case 3:
                printf("Exiting the game...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\nYour spaceship, %s, has %d fuel and %d health.\n\n", my_ship.name, my_ship.fuel, my_ship.health);
    }
}