//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;
int money = 100;
int trapSet = 0;

void attack() {
    int attackDamage = rand() % 20 + 10;
    health -= attackDamage;
    printf("You attack the enemy and deal %d damage.\n", attackDamage);
}

void run() {
    printf("You try to run away.\n");
    int success = rand() % 2;
    if(success) {
        printf("You managed to escape from the enemy.\n");
    } else {
        int damage = rand() % 10 + 1;
        health -= damage;
        printf("You failed to escape and take %d damage.\n", damage);
    }
}

void setTrap() {
    if(trapSet) {
        printf("You have already set a trap.\n");
    } else {
        money -= 50;
        trapSet = 1;
        printf("You set a trap for the enemy.\n");
    }
}

void checkStatus() {
    printf("Health: %d\nMoney: %d\n", health, money);
    if(trapSet) {
        printf("Trap is set.\n");
    }
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself lost in a forest and encounter an enemy.\n");
    while(health > 0) {
        printf("What do you want to do?\n");
        printf("1) Attack\n2) Run\n3) Set Trap\n4) Check Status\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                attack();
                break;
            case 2:
                run();
                break;
            case 3:
                setTrap();
                break;
            case 4:
                checkStatus();
                break;
            default:
                printf("Invalid choice.\n");
        }
        if(trapSet) {
            int trapSuccess = rand() % 2;
            if(trapSuccess) {
                printf("You successfully caught the enemy in your trap! You gain 50 money.\n");
                money += 50;
                trapSet = 0;
            }
        } else {
            int enemyAttack = rand() % 10 + 5;
            printf("The enemy attacks you and deals %d damage.\n", enemyAttack);
            health -= enemyAttack;
        }
    }
    printf("Game over.\n");
    if(health <= 0) {
        printf("You died.\n");
    } else {
        printf("You won! Congratulations!\n");
    }
    return 0;
}