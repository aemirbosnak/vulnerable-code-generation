//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int monsterHealth = 100;
    int runCount = 0;

    srand(time(NULL));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a dark and creepy abandoned house...\n");

    while (playerHealth > 0 && monsterHealth > 0) {
        printf("\n");
        printf("Player health: %d\n", playerHealth);
        printf("Monster health: %d\n", monsterHealth);
        printf("\n");
        printf("What do you want to do?\n");
        printf("1. Attack the monster!\n");
        printf("2. Try to run away.\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            int damage = (rand() % 10) + 1;
            printf("You attack the monster and deal %d damage!\n", damage);
            monsterHealth -= damage;

            if (monsterHealth <= 0) {
                printf("The monster is defeated! You win!\n");
                break;
            }

            damage = (rand() % 10) + 1;
            printf("The monster attacks and deals %d damage!\n", damage);
            playerHealth -= damage;

            if (playerHealth <= 0) {
                printf("You have been defeated! Game over.\n");
                break;
            }

        } else if (option == 2) {
            int runChance = (rand() % 5) + 1;

            if (runChance == 1) {
                printf("You try to run away, but the monster catches you and deals 10 damage!\n");
                playerHealth -= 10;
            } else {
                printf("You successfully run away!\n");
                runCount++;

                if (runCount == 3) {
                    printf("You have escaped the haunted house and won the game!\n");
                    break;
                }
            }
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}