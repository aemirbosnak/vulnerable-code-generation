//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int playerHealth = 100;
    int enemyHealth = 50;
    int playerAttack = 10;
    int enemyAttack = 5;
    int choice;
    int damage;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil alien.\n");
    printf("You have %d health points and your attack power is %d.\n", playerHealth, playerAttack);
    printf("The enemy has %d health points and its attack power is %d.\n", enemyHealth, enemyAttack);

    while(playerHealth > 0 && enemyHealth > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                damage = playerAttack - enemyDefense();
                if(damage > 0) {
                    printf("You attacked the enemy and dealt %d damage!\n", damage);
                    enemyHealth -= damage;
                } else {
                    printf("Your attack was not effective.\n");
                }
                break;
            case 2:
                damage = enemyAttack - playerDefense();
                if(damage > 0) {
                    printf("The enemy attacked you and dealt %d damage!\n", damage);
                    playerHealth -= damage;
                } else {
                    printf("You successfully defended against the enemy's attack.\n");
                }
                break;
            case 3:
                printf("You healed yourself and regained %d health points!\n", heal());
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Your health: %d\n", playerHealth);
        printf("Enemy health: %d\n", enemyHealth);
    }

    if(playerHealth <= 0) {
        printf("You have been defeated by the enemy.\n");
    } else {
        printf("You have successfully defeated the enemy!\n");
    }

    return 0;
}

int enemyDefense() {
    return rand() % 6 + 1;
}

int playerDefense() {
    return rand() % 6 + 1;
}

int heal() {
    return rand() % 6 + 1;
}