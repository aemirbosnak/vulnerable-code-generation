//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    char name[100];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, welcome to the Procedural Space Adventure!\n", name);

    int spaceship_health = 100;
    int spaceship_oxygen = 100;
    int spaceship_fuel = 100;
    int spaceship_weapon_power = 100;

    srand(time(NULL));

    while (spaceship_health > 0 && spaceship_oxygen > 0 && spaceship_fuel > 0 && spaceship_weapon_power > 0) {
        int x = rand() % 100;
        int y = rand() % 100;

        if (x > 50 && y > 50) {
            if (spaceship_health > 0) {
                printf("You have encountered a black hole!\n");
                spaceship_health -= 20;
                printf("Your health is now %d.\n", spaceship_health);
                printf("What do you want to do?\n");
                printf("1. Fire weapons\n");
                printf("2. Try to escape\n");
                printf("3. Do nothing\n");

                int choice = 0;
                while (choice!= 1 && choice!= 2 && choice!= 3) {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        spaceship_weapon_power -= 10;
                        printf("Your weapon power is now %d.\n", spaceship_weapon_power);
                    } else if (choice == 2) {
                        spaceship_fuel -= 10;
                        printf("Your fuel is now %d.\n", spaceship_fuel);
                    } else if (choice == 3) {
                        printf("You do nothing.\n");
                    } else {
                        printf("Invalid choice. Please try again.\n");
                    }
                }
            } else {
                printf("You are out of health. Game over.\n");
                break;
            }
        } else {
            if (spaceship_fuel > 0) {
                spaceship_fuel -= 10;
                printf("Your fuel is now %d.\n", spaceship_fuel);
            } else {
                printf("You are out of fuel. Game over.\n");
                break;
            }
        }

        printf("Your health is %d, oxygen is %d, fuel is %d, weapon power is %d.\n", spaceship_health, spaceship_oxygen, spaceship_fuel, spaceship_weapon_power);
    }

    if (spaceship_health <= 0 || spaceship_oxygen <= 0 || spaceship_fuel <= 0 || spaceship_weapon_power <= 0) {
        printf("Game over.\n");
    } else {
        printf("Congratulations! You have survived the Procedural Space Adventure!\n");
    }

    return 0;
}