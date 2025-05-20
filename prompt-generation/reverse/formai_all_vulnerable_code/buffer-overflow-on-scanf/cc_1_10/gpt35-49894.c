//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void displayIntro();
int choosePath();
int checkPath(int pathChoice);
void handleEncounter(int pathChoice, int* playerHealth, int* enemyHealth);
void displayResult(int playerHealth, int enemyHealth);

int main() {
    // initialize seed for random number generation
    srand(time(0));

    // initialize player and enemy health
    int playerHealth = 100;
    int enemyHealth = 100;

    // display introduction
    displayIntro();

    // choose path
    int pathChoice = choosePath();

    // check if path choice is valid
    int pathValid = checkPath(pathChoice);
    if (!pathValid) {
        printf("Invalid path choice! Exiting program.\n");
        return 1;
    }

    // handle encounter based on path choice
    handleEncounter(pathChoice, &playerHealth, &enemyHealth);

    // display results
    displayResult(playerHealth, enemyHealth);

    return 0;
}

// display introduction
void displayIntro() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new planets.\n");
    printf("As you travel through space, you come across a wormhole that leads to different paths.\n");
    printf("You must choose a path and face the encounters that await you.\n\n");
}

// choose path
int choosePath() {
    int pathChoice;
    printf("Choose your path:\n");
    printf("1. The Red Planet\n");
    printf("2. The Black Hole\n");
    printf("3. The Asteroid Belt\n");
    scanf("%d", &pathChoice);
    return pathChoice;
}

// check if path choice is valid
int checkPath(int pathChoice) {
    if (pathChoice < 1 || pathChoice > 3) {
        return 0;
    }
    return 1;
}

// handle encounter based on path choice
void handleEncounter(int pathChoice, int* playerHealth, int* enemyHealth) {
    int enemyAttack, playerAttack;
    switch (pathChoice) {
        case 1:
            printf("You arrive on the Red Planet and encounter a hostile alien!\n");
            enemyAttack = rand() % 11 + 10;
            playerAttack = rand() % 11 + 10;
            break;
        case 2:
            printf("You enter the Black Hole and come face to face with a space monster!\n");
            enemyAttack = rand() % 16 + 5;
            playerAttack = rand() % 16 + 5;
            break;
        case 3:
            printf("You navigate through the Asteroid Belt and come under attack by space pirates!\n");
            enemyAttack = rand() % 21 + 1;
            playerAttack = rand() % 21 + 1;
            break;
        default:
            break;
    }

    // simulate battle
    while (*playerHealth > 0 && *enemyHealth > 0) {
        *enemyHealth -= playerAttack;
        *playerHealth -= enemyAttack;
        printf("You attack the enemy and deal %d damage. Enemy health: %d\n", playerAttack, *enemyHealth);
        printf("The enemy attacks you and deals %d damage. Your health: %d\n", enemyAttack, *playerHealth);
    }

    printf("\n");
}

// display results
void displayResult(int playerHealth, int enemyHealth) {
    if (playerHealth <= 0) {
        printf("You have been defeated! Better luck next time.\n");
    } else if (enemyHealth <= 0) {
        printf("Congratulations! You have defeated the enemy and completed your mission.\n");
    }
}