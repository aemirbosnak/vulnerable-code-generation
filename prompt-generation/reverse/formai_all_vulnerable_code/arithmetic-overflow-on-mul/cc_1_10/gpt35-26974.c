//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global variables
int playerBalance = 1000;
int houseBalance = 100000;
int betAmount;

// function to generate random number for dice rolls
int rollDice() {
    srand(time(NULL));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
    printf("You rolled %d + %d = %d\n", dice1, dice2, sum);
    return sum;
}

// function to process player's bet
void placeBet() {
    printf("Your current balance is $%d\n", playerBalance);
    printf("How much would you like to bet?\n");
    scanf("%d", &betAmount);

    while (betAmount > playerBalance) {
        printf("You cannot bet more than your current balance. Please enter a valid bet amount.\n");
        scanf("%d", &betAmount);
    }

    playerBalance -= betAmount;
    printf("You have placed a bet of $%d. Your current balance is $%d\n", betAmount, playerBalance);
}

// function to process the game
void playGame() {
    int point = 0;

    printf("\n\n=== Welcome to the Craps game ===\n");

    // place a bet
    placeBet();

    // roll the dice for the first time
    int sum = rollDice();

    // determine the outcome of the first roll
    if (sum == 7 || sum == 11) {
        printf("Congratulations! You won $%d\n", betAmount * 2);
        playerBalance += betAmount * 2;
        return;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lost $%d\n", betAmount);
        return;
    }

    point = sum;
    printf("Your point is %d\n", point);

    // keep rolling the dice until winning or losing
    while (1) {
        printf("Press any key to roll the dice again\n");
        getchar();

        sum = rollDice();

        if (sum == point) {
            printf("Congratulations! You won $%d\n", betAmount * 2);
            playerBalance += betAmount * 2;
            return;
        } else if (sum == 7) {
            printf("You lost $%d\n", betAmount);
            return;
        }
    }
}

// function to process the bet with the house
void placeHouseBet() {
    int houseBet = (houseBalance / 10);

    printf("\n\n=== Welcome to the House Bet game ===\n");
    printf("The house has placed a bet of $%d\n", houseBet);

    if (houseBalance < 2 * houseBet) {
        printf("The house does not have enough balance to match your bet\n");
        return;
    }

    // place a bet
    placeBet();

    // determine the outcome
    int result = rand() % 2;

    if (result == 0) {
        printf("Congratulations! You won $%d from the house\n", houseBet * 2 + betAmount);
        playerBalance += houseBet * 2 + betAmount;
        houseBalance -= houseBet * 2 + betAmount;
    } else {
        printf("You lost $%d to the house\n", betAmount);
        houseBalance += betAmount;
    }
}

// function to display the main menu
void displayMenu() {
    printf("\n\n");
    printf("=====\n");
    printf("MENU\n");
    printf("=====\n");
    printf("1. Play Craps\n");
    printf("2. Place House Bet\n");
    printf("3. Check Balance\n");
    printf("4. Quit\n");
    printf("Enter your choice (1-4):\n");
}

// main function
int main() {
    int choice;

    printf("\n\n=== Welcome to the Casino ===\n");

    while (1) {
        displayMenu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                placeHouseBet();
                break;
            case 3:
                printf("Your current balance is $%d\n", playerBalance);
                printf("The house balance is $%d\n", houseBalance);
                break;
            case 4:
                printf("Thank you for playing. Goodbye!\n");
                return 0;
            default:
                printf("Invalid input. Please enter a valid choice.\n");
        }
    }

    return 0;
}