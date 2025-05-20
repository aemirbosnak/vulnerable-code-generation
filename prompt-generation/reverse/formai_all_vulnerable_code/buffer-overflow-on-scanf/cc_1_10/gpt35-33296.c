//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void rollDice(int *dice1, int *dice2);
int calculateScore(int dice1, int dice2);
void printTable(int playerScore, int dealerScore, int playerWins, int dealerWins);

int main() {
    int playerScore = 0, dealerScore = 0;
    int playerWins = 0, dealerWins = 0;
    char userInput = ' ';

    // Set seed for random number generator
    srand(time(0));

    // Display table
    printTable(playerScore, dealerScore, playerWins, dealerWins);

    // Keep playing until user chooses to quit
    while (userInput != 'q') {
        // Roll dice for player and dealer
        int playerDice1, playerDice2;
        rollDice(&playerDice1, &playerDice2);

        int dealerDice1, dealerDice2;
        rollDice(&dealerDice1, &dealerDice2);

        // Calculate scores and display them
        playerScore += calculateScore(playerDice1, playerDice2);
        dealerScore += calculateScore(dealerDice1, dealerDice2);

        printf("\nPlayer rolls: %d, %d\n", playerDice1, playerDice2);
        printf("Dealer rolls: %d, %d\n", dealerDice1, dealerDice2);
        printf("Player score: %d\n", playerScore);
        printf("Dealer score: %d\n", dealerScore);

        // Determine winner and update wins
        if (playerScore > dealerScore) {
            printf("\nPlayer wins!\n");
            playerWins++;
        }
        else if (dealerScore > playerScore) {
            printf("\nDealer wins!\n");
            dealerWins++;
        }
        else {
            printf("\nIt's a tie!\n");
        }

        // Ask user if they want to continue
        printf("\nPress 'q' to quit, any other key to continue: ");
        scanf(" %c", &userInput);
        printf("\n");

        // Display table
        printTable(playerScore, dealerScore, playerWins, dealerWins);
    }

    printf("Thanks for playing!\n");

    return 0;
}

// Roll two dice and store values in variables pointed to by pointers
void rollDice(int *dice1, int *dice2) {
    *dice1 = rand() % 6 + 1;
    *dice2 = rand() % 6 + 1;
}

// Calculate score based on sum of two dice
int calculateScore(int dice1, int dice2) {
    int sum = dice1 + dice2;

    switch (sum) {
        case 2:
            return 0;
        case 3:
        case 4:
        case 9:
        case 10:
        case 11:
            return sum;
        default:
            return 1;
    }
}

// Print out table with scores and wins
void printTable(int playerScore, int dealerScore, int playerWins, int dealerWins) {
    printf("+------------------------+\n");
    printf("|       C Table Game     |\n");
    printf("+------------------------+\n");
    printf("| Player | Dealer | Wins |\n");
    printf("+--------+--------+------+\n");
    printf("|   %2d   |   %2d   |  %2d  |\n", playerScore, dealerScore, playerWins);
    printf("+--------+--------+------+\n");
    printf("|        |        |  %2d  |\n", dealerWins);
    printf("+--------+--------+------+\n");
}