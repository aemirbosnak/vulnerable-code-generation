//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("cls");
}

void delay(int seconds) {
    int milliSeconds = 1000 * seconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}

int main() {
    char playerName[20];
    int playerHealth = 100;
    int enemyHealth = 50;
    int playerAttack, enemyAttack;
    int round = 1;
    srand(time(NULL));

    printf("------------------------\n");
    printf("Welcome to Space Adventure\n");
    printf("------------------------\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s! You are now in a spaceship travelling through space.\n", playerName);
    printf("You encounter an alien ship. Prepare for battle!\n");
    delay(2);

    while(playerHealth > 0 && enemyHealth > 0) {
        clearScreen();
        printf("----------------\n");
        printf("Round %d\n", round);
        printf("----------------\n");
        printf("%s's Health: %d\n", playerName, playerHealth);
        printf("Alien's Health: %d\n", enemyHealth);

        // Player attack
        printf("----------------\n");
        printf("%s's turn\n", playerName);
        printf("Enter your attack power (between 1 and 10): ");
        scanf("%d", &playerAttack);
        enemyHealth -= playerAttack;
        printf("%s attacks! Alien loses %d health points.\n", playerName, playerAttack);
        if(enemyHealth <= 0) {
            printf("Congratulations %s! You have defeated the alien!\n", playerName);
            return 0;
        }

        // Alien attack
        printf("----------------\n");
        printf("Alien's turn\n");
        enemyAttack = rand() % 10 + 1;
        playerHealth -= enemyAttack;
        printf("Alien attacks! %s loses %d health points.\n", playerName, enemyAttack);
        if(playerHealth <= 0) {
            printf("Game over! %s was defeated by the alien.\n", playerName);
            return 0;
        }

        round++;
        delay(2);
    }

    return 0;
}