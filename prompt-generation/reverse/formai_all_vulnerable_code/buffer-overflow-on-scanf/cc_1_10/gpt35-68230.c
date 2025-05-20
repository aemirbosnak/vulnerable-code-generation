//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function declarations
void intro();
void startGame();
int attack(int health);
void bossFight(int *health, int *winFlag);
void gameOver();
void winGame();

int main() {
    intro();
    startGame();
    return 0;
}

//intro function
void intro() {
    printf("--------------------------------------\n");
    printf("\t CYBERPUNK TERMINAL GAME\n");
    printf("--------------------------------------\n");
    printf("Welcome to 2048, a city ruled by corrupt corporations and crime syndicates. You are a mercenary hired by the underdogs. Your mission is to take down the boss of the biggest crime syndicate in the city.\n");
    printf("You will face many challenges and enemies on your way. Good luck!\n");
    printf("--------------------------------------\n");
}

//start game function
void startGame() {
    int health = 100;
    int winFlag = 0;
    int choice;
    printf("\nYou are walking down the street when a group of thugs approach you. What do you do?\n");
    printf("1. Fight\n");
    printf("2. Attempt to negotiate\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\nYou choose to fight.\n");
        health = attack(health);
        if(health <= 0) {
            gameOver();
            return;
        }
        printf("\nYou defeated the thugs. You continue on your mission.\n");
    }
    else if(choice == 2) {
        printf("\nYou attempt to negotiate with the thugs. They refuse and attack you.\n");
        health = attack(health);
        if(health <= 0) {
            gameOver();
            return;
        }
        printf("\nYou defeated the thugs. You continue on your mission.\n");
    }
    else {
        printf("\nInvalid choice. Please enter 1 or 2.\n");
        startGame();
        return;
    }
    
    printf("\nYou come across a locked door. What do you do?\n");
    printf("1. Pick the lock\n");
    printf("2. Blow it up\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\nYou attempt to pick the lock. You fail and the alarm goes off.\n");
        health -= 20;
        if(health <= 0) {
            gameOver();
            return;
        }
        printf("\nYou set off the alarm. You need to hurry!\n");
    }
    else if(choice == 2) {
        printf("\nYou blow up the door and enter.\n");
        printf("\nYou have entered the enemy headquarters. You must fight your way to the boss.\n");
    }
    else {
        printf("\nInvalid choice. Please enter 1 or 2.\n");
        startGame();
        return;
    }
    
    bossFight(&health, &winFlag);
    if(winFlag) winGame();
    else gameOver();
}

//attack function
int attack(int health) {
    int enemyHealth = 30;
    srand(time(NULL));
    int enemyPower;
    int choice;
    while(enemyHealth > 0) {
        printf("\nEnemy Health: %d\n", enemyHealth);
        printf("Your Health: %d\n", health);
        printf("What do you do?\n");
        printf("1. Attack\n");
        printf("2. Dodge\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("\nYou attack the enemy.\n");
            enemyPower = rand() % 10 + 1;
            printf("Enemy power: %d\n", enemyPower);
            enemyHealth -= enemyPower;
            printf("Enemy Health: %d\n", enemyHealth);
            if(enemyHealth <= 0) {
                printf("\nYou defeated the enemy.\n");
                return health;
            }
            enemyPower = rand() % 10 + 1;
            printf("Enemy attacks.\n");
            printf("Your power: %d\n", enemyPower);
            health -= enemyPower;
            printf("Your Health: %d\n", health);
            if(health <= 0) return health;
        }
        else if(choice == 2) {
            printf("\nYou dodge the enemy's attack.\n");
            enemyPower = rand() % 10 + 1;
            printf("Enemy attacks.\n");
            printf("Your power: %d\n", enemyPower);
            health -= enemyPower;
            printf("Your Health: %d\n", health);
            if(health <= 0) return health;
        }
        else {
            printf("\nInvalid choice. Please enter 1 or 2.\n");
        }
    }
    return health;
}

//boss fight function
void bossFight(int *health, int *winFlag) {
    int bossHealth = 100;
    srand(time(NULL));
    int bossPower;
    int choice;
    while(bossHealth > 0) {
        printf("\nBoss Health: %d\n", bossHealth);
        printf("Your Health: %d\n", *health);
        printf("What do you do?\n");
        printf("1. Attack\n");
        printf("2. Dodge\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("\nYou attack the boss.\n");
            bossPower = rand() % 10 + 1;
            printf("Boss power: %d\n", bossPower);
            bossHealth -= bossPower;
            printf("Boss Health: %d\n", bossHealth);
            if(bossHealth <= 0) {
                printf("\nYou defeated the boss.\n");
                *winFlag = 1;
                return;
            }
            bossPower = rand() % 10 + 1;
            printf("Boss attacks.\n");
            printf("Your power: %d\n", bossPower);
            *health -= bossPower;
            printf("Your Health: %d\n", *health);
            if(*health <= 0) return;
        }
        else if(choice == 2) {
            printf("\nYou dodge the boss's attack.\n");
            bossPower = rand() % 10 + 1;
            printf("Boss attacks.\n");
            printf("Your power: %d\n", bossPower);
            *health -= bossPower;
            printf("Your Health: %d\n", *health);
            if(*health <= 0) return;
        }
        else {
            printf("\nInvalid choice. Please enter 1 or 2.\n");
        }
    }
}

//game over function
void gameOver() {
    printf("\nGAME OVER! The city remains under the control of the corrupt corporations and crime syndicates.\n");
}

//win game function
void winGame() {
    printf("\nCongratulations! You have taken down the boss of the biggest crime syndicate in the city. The people of the city are grateful for your heroic deeds. You have saved the day!\n");
}