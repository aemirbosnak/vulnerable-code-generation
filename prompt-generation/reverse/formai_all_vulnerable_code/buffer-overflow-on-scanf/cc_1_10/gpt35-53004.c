//FormAI DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void rollDice(int *dice1, int *dice2);
int sumOfDice(int dice1, int dice2);
void playRound(int *playerScore, int *computerScore);
void printGameRules();
int playAgain();

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int play;

    do {
        printf("\n************** WELCOME TO C TABLE GAME **************\n");
        printGameRules();

        // Play round
        playRound(&playerScore, &computerScore);

        // Display final scores
        printf("\nFinal Scores:\nPlayer: %d\nComputer: %d\n", playerScore, computerScore);

        // Ask user if they want to play again
        play = playAgain();

    } while (play);

    printf("\nThank you for playing C Table Game!");

    return 0;
}

// Function to simulate dice roll
void rollDice(int *dice1, int *dice2) {
    srand(time(NULL));
    *dice1 = rand() % 6 + 1; // Generates a random number between 1 and 6
    *dice2 = rand() % 6 + 1;
}

// Function to calculate sum of the dice
int sumOfDice(int dice1, int dice2) {
    return dice1 + dice2;
}

// Function to play a round
void playRound(int *playerScore, int *computerScore) {
    int playerSum, computerSum;
    int roundOver = 0;

    do {
        // Player's turn
        printf("\nPlayer's Turn:\n");
        rollDice(&playerSum, &computerSum);
        printf("Player rolled a %d and a %d\n", playerSum, computerSum);

        if (playerSum == 7) {
            printf("Player wins the round!\n");
            (*playerScore)++;
            roundOver = 1;
        } else if (playerSum == 2 || playerSum == 3 || playerSum == 12) {
            printf("Player loses the round!\n");
            (*computerScore)++;
            roundOver = 1;
        } else {
            // Computer's turn
            printf("\nComputer's Turn:\n");
            rollDice(&playerSum, &computerSum);
            printf("Computer rolled a %d and a %d\n", playerSum, computerSum);

            if (computerSum == 7) {
                printf("Computer wins the round!\n");
                (*computerScore)++;
                roundOver = 1;
            } else if (computerSum == 2 || computerSum == 3 || computerSum == 12) {
                printf("Computer loses the round!\n");
                (*playerScore)++;
                roundOver = 1;
            }
        }

    } while (!roundOver);
}

// Function to print game rules
void printGameRules() {
    printf("\nGame Rules:\n\n"
           "1. Two dice are rolled in each round.\n"
           "2. If the sum of the dice is 2, 3, or 12, the player loses the round.\n"
           "3. If the sum of the dice is 7, the player wins the round.\n"
           "4. If the sum of the dice is any other value, the game continues with the computer's turn.\n"
           "5. The computer follows the same rules as the player.\n\n");
}

// Function to ask if user wants to play again
int playAgain() {
    char answer;

    do {
        printf("\nDo you want to play again? (y/n) ");
        scanf(" %c", &answer);
        answer = tolower(answer); // Convert answer to lowercase
    } while (answer != 'y' && answer != 'n');

    return (answer == 'y');
}