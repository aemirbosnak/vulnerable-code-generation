//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6 (inclusive)
int rollDice() {
    return rand() % 6 + 1;
}

// Function to print the result of the dice roll
void printResult(int dice1, int dice2) {
    printf("The result of the dice roll is: %d + %d = %d\n", dice1, dice2, dice1 + dice2);
}

// Function to simulate a dice rolling game between two players
void diceGame(char player1[], char player2[], int numRolls) {
    int i, dice1, dice2, player1Score = 0, player2Score = 0;

    // Roll the dice for each player
    for (i = 0; i < numRolls; i++) {
        dice1 = rollDice();
        dice2 = rollDice();

        // Print the result of the dice roll
        printf("Player %s rolled: %d + %d = %d\n", player1, dice1, dice2, dice1 + dice2);
        player1Score += dice1 + dice2;

        dice1 = rollDice();
        dice2 = rollDice();

        // Print the result of the dice roll
        printf("Player %s rolled: %d + %d = %d\n", player2, dice1, dice2, dice1 + dice2);
        player2Score += dice1 + dice2;
    }

    // Print the final scores of the players
    printf("The final score of Player %s is: %d\n", player1, player1Score);
    printf("The final score of Player %s is: %d\n", player2, player2Score);

    // Determine the winner of the game
    if (player1Score > player2Score) {
        printf("Player %s wins the game!\n", player1);
    } else if (player2Score > player1Score) {
        printf("Player %s wins the game!\n", player2);
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    char player1[20], player2[20];
    int numRolls;

    // Get the names of the players from the user
    printf("Enter the name of Player 1: ");
    scanf("%s", player1);

    printf("Enter the name of Player 2: ");
    scanf("%s", player2);

    // Get the number of rolls for the game from the user
    printf("Enter the number of rolls for the game: ");
    scanf("%d", &numRolls);

    // Roll the dice and play the game
    diceGame(player1, player2, numRolls);

    return 0;
}