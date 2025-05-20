//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function declarations
void showMenu();
void startGame();
void continueGame();

//Global variables
char playerName[50];
int playerHealth = 100;
int playerAttack = 10;
int playerDefense = 5;
int gameScore = 0;

//Main function
int main() {
    int option;
    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s! Let's get started...\n", playerName);
    showMenu();
    scanf("%d", &option);
    switch(option) {
        case 1:
            startGame();
            break;
        case 2:
            continueGame();
            break;
        case 3:
            printf("Goodbye %s! Hope to see you again.\n", playerName);
            exit(0);
        default:
            printf("Invalid option! Please try again.\n");
            main();
    }
    return 0;
}

//Function to show game menu
void showMenu() {
    printf("Please select an option:\n");
    printf("1. Start a new game\n");
    printf("2. Continue game\n");
    printf("3. Quit\n");
}

//Function to start a new game
void startGame() {
    printf("Starting a new game...\n");
    printf("You are in a dark forest. You hear a strange noise...\n");
    printf("What do you do?\n");
    printf("1. Investigate the noise\n");
    printf("2. Ignore the noise\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1) {
        printf("You investigate the noise and find a group of bandits.\n");
        printf("They attack you...\n");
        int enemyHealth = 50;
        int enemyAttack = 5;
        int enemyDefense = 2;
        while(playerHealth > 0 && enemyHealth > 0) {
            printf("Your health: %d\n", playerHealth);
            printf("Enemy health: %d\n", enemyHealth);
            printf("What do you do?\n");
            printf("1. Attack\n");
            printf("2. Defend\n");
            int choice;
            scanf("%d", &choice);
            if(choice == 1) {
                int damage = playerAttack - enemyDefense;
                if(damage < 0) damage = 0;
                enemyHealth -= damage;
                printf("You attacked the enemy and did %d damage.\n", damage);
            }
            else {
                int damage = enemyAttack - playerDefense;
                if(damage < 0) damage = 0;
                playerHealth -= damage;
                printf("You defended and took %d damage.\n", damage);
            }
        }
        if(playerHealth > 0) {
            printf("Congratulations! You defeated the bandits and found a treasure chest.\n");
            gameScore += 100;
        }
        else {
            printf("Game Over! You were defeated by the bandits.\n");
            printf("Your score: %d\n", gameScore);
        }
    }
    else if(choice == 2) {
        printf("You ignore the noise and continue walking...\n");
        printf("You find a village and see a wanted poster with your face on it!\n");
        printf("The villagers are scared and call the guards...\n");
        printf("Game Over! You were captured by the guards.\n");
        printf("Your score: %d\n", gameScore);
    }
    else {
        printf("Invalid choice! Please try again.\n");
        startGame();
    }
}

//Function to continue game
void continueGame() {
    if(gameScore > 0) {
        printf("Continuing game...\n");
        printf("Your score: %d\n", gameScore);
    }
    else {
        printf("No saved game found! Please start a new game.\n");
        main();
    }
}