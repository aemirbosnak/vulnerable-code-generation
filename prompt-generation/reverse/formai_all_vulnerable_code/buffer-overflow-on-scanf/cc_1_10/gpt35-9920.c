//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wait(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    char name[20], choice[10];
    int golemHealth = 100, playerHealth = 100;
    int damageMin = 10, damageMax = 20;
    int playerDamage = 0, golemDamage = 0;

    printf("Greetings adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Welcome, %s! You find yourself in a dark cavern. In the distance you see a golem. What would you like to do?\n", name);

    while (golemHealth > 0 && playerHealth > 0) {
        printf("Options: Attack or Flee\n");
        scanf("%s", choice);

        if (strcmp(choice, "attack") == 0) {
            playerDamage = rand() % (damageMax - damageMin + 1) + damageMin;
            golemHealth -= playerDamage;

            if (golemHealth <= 0) {
                printf("You defeated the golem and emerged victorious!\n");
                break;
            }

            golemDamage = rand() % (damageMax - damageMin + 1) + damageMin;
            playerHealth -= golemDamage;

            printf("Player health: %d\n", playerHealth);
            printf("Golem health: %d\n", golemHealth);        
        }

        else if (strcmp(choice, "flee") == 0) {
            printf("You attempt to flee, but the golem catches up to you and attacks!\n");
            golemDamage = rand() % (damageMax - damageMin + 1) + damageMin;
            playerHealth -= golemDamage;

            printf("Player health: %d\n", playerHealth);
            printf("Golem health: %d\n", golemHealth);        
        }

        else {
            printf("I'm sorry, I didn't understand your choice.\n");
        }

        if (playerHealth <= 0) {
            printf("You have been defeated by the golem. Better luck next time, %s!\n", name);
            break;
        }

        wait();
    }

    return 0;
}