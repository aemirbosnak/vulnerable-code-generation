//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark forest with an enemy nearby.\n");
    printf("Your health: %d\n", playerHealth);
    printf("Enemy health: %d\n", enemyHealth);

    char choice;

    while(1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Attack\n2. Defend\n3. Heal\n4. Run away\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(playerHealth <= 0) {
                    printf("You are too weak to attack.\n");
                } else if(enemyHealth <= 0) {
                    printf("The enemy is already defeated.\n");
                } else {
                    int damage = rand() % 10 + 1;
                    enemyHealth -= damage;
                    playerHealth -= 5;
                    printf("You attacked the enemy and dealt %d damage.\n", damage);
                    printf("Your health: %d\n", playerHealth);
                    printf("Enemy health: %d\n", enemyHealth);

                    if(enemyHealth <= 0) {
                        printf("You have defeated the enemy!\n");
                        break;
                    }
                }
                break;
            case '2':
                if(playerHealth <= 0) {
                    printf("You are too weak to defend.\n");
                } else {
                    int defense = rand() % 10 + 1;
                    playerHealth -= 5;
                    printf("You defended yourself and gained %d health.\n", defense);
                    printf("Your health: %d\n", playerHealth);
                }
                break;
            case '3':
                if(playerHealth >= 100) {
                    printf("You are already at full health.\n");
                } else {
                    int heal = rand() % 10 + 1;
                    playerHealth += heal;
                    printf("You healed yourself and gained %d health.\n", heal);
                    printf("Your health: %d\n", playerHealth);
                }
                break;
            case '4':
                printf("You ran away from the enemy.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}