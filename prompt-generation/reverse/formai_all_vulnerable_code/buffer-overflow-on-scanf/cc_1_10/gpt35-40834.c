//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerHealth = 100;
int alienHealth = 50;
int accuracy = 80;
int alienAccuracy = 50;

void attack(int chance) {
    if(rand() % 101 <= chance) {
        if(alienHealth >= 10) {
            alienHealth-=10;
            printf("You hit the alien! Alien health: %d\n", alienHealth);
        } else {
            printf("You defeated the alien! Congratulations!\n");
            exit(0);
        }
    } else {
        printf("You missed!\n");
    }
}

void alienAttack() {
    if(rand() % 101 <= alienAccuracy) {
        if(playerHealth >= 20) {
            playerHealth-=20;
            printf("The alien hit you! Your health: %d\n", playerHealth);
        } else {
            printf("You were defeated by the alien. Game over.\n");
            exit(0);
        }
    } else {
        printf("The alien missed!\n");
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to defeat the alien and save the galaxy.\n");
    while(playerHealth > 0 && alienHealth > 0) {
        printf("\nChoose an action:\n1. Attack\n2. Defend\n3. Run\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                attack(accuracy);
                alienAttack();
                break;
            case 2:
                printf("You chose to defend.\n");
                int defendChance = rand() % 101;
                if(defendChance <= 40) {
                    printf("You successfully defended the alien's attack!\n");
                } else if(defendChance <= 80) {
                    printf("You took some damage but defended most of the attack. Your health: %d\n", playerHealth-10);
                } else {
                    printf("You failed to defend and took full damage. Your health: %d\n", playerHealth-20);
                }
                alienAttack();
                break;
            case 3:
                printf("You chose to run away. Coward.\n");
                int runChance = rand() % 101;
                if(runChance <= 20) {
                    printf("The alien caught up to you and attacked you! Your health: %d\n", playerHealth-20);
                } else {
                    printf("You successfully escaped! Game over.\n");
                    exit(0);
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    if(playerHealth <= 0) {
        printf("You were defeated by the alien. Game over.\n");
    } else {
        printf("You defeated the alien! Congratulations!\n");
    }
    return 0;
}