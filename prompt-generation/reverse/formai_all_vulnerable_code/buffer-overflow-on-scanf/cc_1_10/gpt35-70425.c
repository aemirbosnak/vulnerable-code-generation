//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;
    int roomNumber = 1;
    int luckyNumber = rand() % 10 + 1;
    int playerAttack, enemyAttack;
    char action;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a creepy old mansion. You must make it through all the rooms to escape.\n");
    printf("You start with 100 health.\n\n");

    while (roomNumber <= 10) {
        printf("You are in room %d.\n", roomNumber);
        printf("There is a %d%% chance of encountering an enemy.\n", luckyNumber * 10);

        if (rand() % 10 + 1 <= luckyNumber) {
            printf("An enemy has appeared!\n");
            enemyHealth = 50 + roomNumber * 10;
            printf("Enemy health: %d\n", enemyHealth);

            while (playerHealth > 0 && enemyHealth > 0) {
                printf("Your health: %d | Enemy health: %d\n\n", playerHealth, enemyHealth);
                printf("Enter 'a' to attack or 'r' to run: ");
                scanf(" %c", &action);

                if (action == 'a') {
                    playerAttack = rand() % 20 + 1 + roomNumber * 5;
                    enemyHealth -= playerAttack;
                    printf("You attack and deal %d damage.\n", playerAttack);

                    if (enemyHealth <= 0) {
                        printf("You defeated the enemy!\n");
                        break;
                    }

                    enemyAttack = rand() % 10 + 1 + roomNumber * 2;
                    playerHealth -= enemyAttack;
                    printf("The enemy attacks and deals %d damage.\n", enemyAttack);

                    if (playerHealth <= 0) {
                        printf("You have been defeated!\n");
                        return 0;
                    }
                }
                else if (action == 'r') {
                    printf("You run away and go back to the previous room.\n");
                    roomNumber--;
                    break;
                }
                else {
                    printf("Invalid input. Try again.\n");
                }
            }
        }
        else {
            printf("No enemies in this room.\n\n");
        }

        if (roomNumber == 10) {
            printf("Congratulations! You made it out of the haunted house alive!\n");
            return 0;
        }

        playerHealth += 10;
        printf("You found a first aid kit and gained 10 health.\n");
        roomNumber++;
        printf("Proceeding to next room...\n\n");
        luckyNumber = rand() % 10 + 1;
     }

    return 0;
}