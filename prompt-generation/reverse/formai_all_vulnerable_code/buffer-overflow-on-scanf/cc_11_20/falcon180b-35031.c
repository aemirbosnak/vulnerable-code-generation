//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int playerHealth = 100;
    int enemyHealth = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior on a quest to defeat the evil dragon.\n");
    printf("Choose your path wisely.\n");

    int randomEnemy = rand() % 3 + 1;

    switch(randomEnemy) {
        case 1:
            printf("You encounter a fierce orc.\n");
            break;
        case 2:
            printf("You stumble upon a pack of hungry wolves.\n");
            break;
        case 3:
            printf("You face off against a giant spider.\n");
            break;
    }

    while(playerHealth > 0 && enemyHealth > 0) {
        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);

        printf("What will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run away\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You attack the enemy with all your might.\n");
                enemyHealth -= 10;
                if(enemyHealth <= 0) {
                    printf("You have defeated the enemy!\n");
                    break;
                }
                else {
                    printf("The enemy retaliates and deals 5 damage to you.\n");
                    playerHealth -= 5;
                }
                break;
            case 2:
                printf("You defend yourself against the enemy's attack.\n");
                if(enemyHealth <= 5) {
                    printf("The enemy is too weak to continue fighting and flees.\n");
                    break;
                }
                else {
                    printf("The enemy deals 5 damage to you.\n");
                    playerHealth -= 5;
                }
                break;
            case 3:
                printf("You run away from the enemy.\n");
                if(playerHealth <= 20) {
                    printf("You are too weak to run and collapse.\n");
                    break;
                }
                else {
                    printf("You manage to escape unscathed.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    if(playerHealth <= 0) {
        printf("You have been defeated by the enemy.\n");
    }
    else {
        printf("You have emerged victorious!\n");
    }

    return 0;
}