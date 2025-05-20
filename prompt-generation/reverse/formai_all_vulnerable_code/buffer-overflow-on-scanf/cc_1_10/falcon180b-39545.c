//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct spaceship {
    char name[50];
    int speed;
    int fuel;
    int weapons;
};

void adventure() {
    int choice;
    int random_event;
    int event_result;
    int fuel_consumed;

    struct spaceship my_ship = {"My Ship", 100, 100, 10};

    printf("Welcome to the Space Adventure!\n");
    printf("You are now in control of %s.\n", my_ship.name);
    printf("Your ship has %d speed, %d fuel and %d weapons.\n", my_ship.speed, my_ship.fuel, my_ship.weapons);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Attack enemy\n");
        printf("3. Refuel\n");
        printf("4. Repair\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You move forward at %d speed.\n", my_ship.speed);
                break;
            case 2:
                printf("You attack the enemy with %d weapons.\n", my_ship.weapons);
                break;
            case 3:
                printf("You refuel your ship with %d fuel.\n", my_ship.fuel);
                break;
            case 4:
                printf("You repair your ship.\n");
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        random_event = rand() % 10;

        if (random_event == 0) {
            printf("\nA random event occurs: You find a cache of fuel!\n");
            fuel_consumed = rand() % 50 + 1;
            my_ship.fuel += 100 - fuel_consumed;
            printf("You consume %d fuel.\n", fuel_consumed);
        } else if (random_event == 1) {
            printf("\nA random event occurs: You encounter an enemy!\n");
            event_result = rand() % 2;

            if (event_result == 0) {
                printf("You defeat the enemy.\n");
            } else {
                printf("You are defeated by the enemy.\n");
                exit(0);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    adventure();

    return 0;
}