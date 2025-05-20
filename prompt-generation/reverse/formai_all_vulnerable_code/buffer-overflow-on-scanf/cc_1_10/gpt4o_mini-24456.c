//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGreeting() {
    printf("*********************************\n");
    printf("*      Welcome to Dice Roller!  *\n");
    printf("*        Have some fun!         *\n");
    printf("*********************************\n");
    printf("\n");
}

void printGoodbye() {
    printf("*********************************\n");
    printf("*      Thanks for playing!      *\n");
    printf("*    May the odds be in your    *\n");
    printf("*          favor!               *\n");
    printf("*********************************\n");
}

int rollDice() {
    return (rand() % 6) + 1; // Generate a number between 1 and 6
}

void displayResult(int roll) {
    printf("You rolled a %d! 🎲\n", roll);
}

void playGame() {
    int numberOfRolls = 0;
    printf("How many dice would you like to roll? ");
    if (scanf("%d", &numberOfRolls) != 1 || numberOfRolls < 1) {
        printf("Oops! Please enter a positive number. Let's start over!\n");
        return;
    }
    
    printf("Rolling %d dice...\n", numberOfRolls);
    for (int i = 0; i < numberOfRolls; i++) {
        int roll = rollDice();
        displayResult(roll);
        if (roll == 6) {
            printf("Wow! You rolled a six! 🎉\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    printGreeting();

    char choice;
    do {
        playGame();
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Awesome! Let's go again! 🎉\n");
        } else if (choice == 'n' || choice == 'N') {
            printf("Alright! Thanks for playing!\n");
        } else {
            printf("Hmm, I didn't understand that. Let's just say no and move on!\n");
        }
    } while (choice == 'y' || choice == 'Y');

    printGoodbye();
    return 0;
}