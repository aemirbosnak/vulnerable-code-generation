//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int health = 100;
    int ammo = 50;
    int oxygen = 100;
    int aliens_killed = 0;
    int fuel = 100;
    int distance_traveled = 0;
    int planet_number = 1;
    int alien_alive = 1;
    int choice;
    printf("\nWelcome to the Space Adventure!\n");

    while (1) {
        printf("===============================\n");
        printf("\nYou are on Planet %d\n", planet_number);
        printf("\nHealth: %d\n", health);
        printf("Ammo: %d\n", ammo);
        printf("Oxygen: %d\n", oxygen);
        printf("Fuel: %d\n", fuel);
        printf("Distance Traveled: %d\n", distance_traveled);
        printf("Aliens Killed: %d\n", aliens_killed);
        printf("===============================\n\n");

        if (alien_alive && rand() % 3 == 0) {
            printf("Uh oh! An alien is attacking you!\n");
            if (rand() % 2 == 0) {
                printf("The alien missed you!\n");
            } else {
                health -= 20;
                printf("The alien hit you! Your health is now %d\n", health);
            }
        }

        if (health <= 0) {
            printf("You have died.\n");
            break;
        }

        if (oxygen <= 0) {
            printf("You have run out of oxygen.\n");
            break;
        }

        if (fuel <= 0) {
            printf("You have run out of fuel.\n");
            break;
        }

        printf("What would you like to do?\n");
        printf("1. Travel to the next planet\n");
        printf("2. Search for ammo\n");
        printf("3. Fight an alien\n");
        printf("4. Refuel\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You embark on your journey to the next planet.\n");
                int chance_of_encounter = rand() % 4;
                if (chance_of_encounter == 0) {
                    printf("You encounter an asteroid field!\n");
                    health -= 10;
                    fuel -= 20;
                    distance_traveled += 20;
                } else if (chance_of_encounter == 1) {
                    printf("You encounter a black hole!\n");
                    health -= 50;
                    fuel = 0;
                    distance_traveled += 40;
                } else {
                    printf("You make it safely to the next planet!\n");
                    fuel -= 20;
                    oxygen -= 10;
                    distance_traveled += 50;
                    planet_number++;
                }
                break;
            case 2:
                printf("You search for ammo...\n");
                if (rand() % 2 == 0) {
                    printf("You found some ammo!\n");
                    ammo += 10;
                } else {
                    printf("You didn't find anything.\n");
                }
                break;
            case 3:
                printf("You fight an alien!\n");
                if (rand() % 2 == 0) {
                    printf("You killed the alien!\n");
                    alien_alive = 0;
                    aliens_killed++;
                } else {
                    printf("The alien killed you...\n");
                    health = 0;
                }
                break;
            case 4:
                printf("You refuel your ship...\n");
                fuel = 100;
                break;
            case 5:
                printf("Thanks for playing Space Adventure!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        if (alien_alive == 0) {
            alien_alive = 1;
        }
    }

    return 0;
}