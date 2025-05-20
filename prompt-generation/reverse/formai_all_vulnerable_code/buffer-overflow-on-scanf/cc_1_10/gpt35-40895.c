//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fuel = 100;
int health = 100;

typedef struct {
    char* name;
    int fuel_efficiency;
} Spaceship;

void travel(Spaceship* ship) {
    int distance = rand() % 1000;
    int fuel_consumed = distance * (100/ship->fuel_efficiency);

    if(fuel_consumed > fuel) {
        printf("Insufficient fuel to travel this distance. You need %d fuel units to travel %d distance.\n", fuel_consumed, distance);
        return;
    }

    fuel -= fuel_consumed;

    // Random event during space travels
    int event = rand() % 4;
    if(event == 0) {
        printf("You encountered an asteroid belt! Your ship took damage.\n");
        health -= 20;
    } else if(event == 1) {
        printf("You found a deposit of rare minerals! You were able to trade them for extra fuel.\n");
        fuel += 20;
    } else if(event == 2) {
        printf("You discovered an abandoned research station. You were able to repair some of your ship's systems.\n");
        health += 20;
    }

    printf("You have traveled %d distance. Fuel remaining: %d, Health remaining: %d\n", distance, fuel, health);
}

int main() {
    Spaceship my_ship = {"Astro Cruiser", 5};
    srand(time(0));

    while(health > 0) {
        int choice;
        printf("1. Travel to new location\n2. Quit game\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            travel(&my_ship);
        } else if(choice == 2) {
            printf("Thanks for playing! Goodbye.\n");
            return 0;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Your ship has been destroyed. Game over.\n");
    return 0;
}