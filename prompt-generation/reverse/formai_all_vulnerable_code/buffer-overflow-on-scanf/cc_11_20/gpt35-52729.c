//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
/* Procedural Space Adventure Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variables
    char name[20];
    int choice;
    int health = 100;
    int score = 0;
    int aliens_defeated = 0;
    int fuel_cells_collected = 0;
    int ammo = 10;
    int fuel = 100;
    int distance = 0;

    // Introduction
    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nGreetings, %s! You have been chosen to embark on a mission to explore space and defend our planet from any alien threats.\n", name);
    printf("Your spaceship is equipped with advanced weapons and gadgets to make your journey a success.\n");

    // Main Game Loop
    while(health > 0 && fuel > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the area\n");
        printf("2. Fight aliens\n");
        printf("3. Collect fuel cells\n");
        printf("4. Check status\n");
        printf("5. Quit the game\n");

        scanf("%d", &choice);

        // Explore the area
        if(choice == 1) {
            printf("\nYou explore the area and find a planet.\n");
            printf("Would you like to land on the planet?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            scanf("%d", &choice);

            if(choice == 1) {
                printf("\nYou land on the planet and discover a cave full of rare minerals.\n");
                score += 50;
                health -= 10;
            }
            else {
                printf("\nYou continue to explore the area.\n");
                fuel -= 20;
                distance += 50;
            }
        }
        // Fight aliens
        else if(choice == 2) {
            printf("\nYou encounter a group of aliens!\n");
            printf("What would you like to do?\n");
            printf("1. Fight\n");
            printf("2. Retreat\n");

            scanf("%d", &choice);

            if(choice == 1) {
                int alien_health = rand() % 100;

                while(alien_health > 0 && health > 0 && ammo > 0) {
                    int attack = rand() % 20;
                    int alien_attack = rand() % 30;

                    if(attack > 10) {
                        printf("\nYou hit the alien and deal %d damage!\n", attack);
                        alien_health -= attack;
                    }
                    else {
                        printf("\nYou missed the alien!\n");
                    }

                    if(alien_attack > 10) {
                        printf("\nThe alien hits you and deals %d damage!\n", alien_attack);
                        health -= alien_attack;
                    }
                    else {
                        printf("\nThe alien misses you!\n");
                    }

                    ammo--;
                }

                if(alien_health <= 0 && health > 0) {
                    printf("\nYou have defeated the aliens!\n");
                    aliens_defeated++;
                    score += 100;
                }
                else if(health <= 0) {
                    printf("\nYou have been defeated!\n");
                    break;
                }
                else {
                    printf("\nYou are out of ammo and must retreat!\n");
                }
            }
            else {
                printf("\nYou retreat from the aliens.\n");
                fuel -= 10;
                distance += 20;
            }
        }
        // Collect fuel cells
        else if(choice == 3) {
            printf("\nYou find a fuel cell!\n");
            fuel_cells_collected++;
            fuel += 25;
            score += 10;
        }
        // Check status
        else if(choice == 4) {
            printf("\nName: %s\n", name);
            printf("Score: %d\n", score);
            printf("Aliens Defeated: %d\n", aliens_defeated);
            printf("Fuel Cells Collected: %d\n", fuel_cells_collected);
            printf("Ammo: %d\n", ammo);
            printf("Fuel: %d\n", fuel);
            printf("Health: %d\n", health);
            printf("Distance Traveled: %d\n", distance);
        }
        // Quit the game
        else if(choice == 5) {
            printf("\nExiting the game...\n");
            break;
        }
        // Invalid choice
        else {
            printf("\nInvalid choice!\n");
        }
    }

    if(health <= 0) {
        printf("\nGame Over! You died.\n");
    }
    else if(fuel <= 0) {
        printf("\nGame Over! You ran out of fuel.\n");
    }
    else {
        printf("\nCongratulations! You have completed the game.\n");
    }

    return 0;
}