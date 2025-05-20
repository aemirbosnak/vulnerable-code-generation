//Falcon-180B DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables
int playerScore = 0;
int computerScore = 0;
int choice;
int computerChoice;
int gameWon = 0;

// Function prototypes
void playGame();
int getComputerChoice();
int getPlayerChoice();
int determineWinner(int playerChoice, int computerChoice);

// Main function
int main() {
    srand(time(0)); // Seed the random number generator
    playGame();
    return 0;
}

// Play the game
void playGame() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("\nRound %d:\n", i+1);
        choice = getPlayerChoice();
        computerChoice = getComputerChoice();

        if (determineWinner(choice, computerChoice) == 1) {
            printf("You win this round!\n");
            playerScore++;
        } else if (determineWinner(choice, computerChoice) == -1) {
            printf("You lose this round.\n");
            computerScore++;
        } else {
            printf("It's a tie.\n");
        }

        if (playerScore == 3 || computerScore == 3) {
            gameWon = 1;
            break;
        }
    }

    if (gameWon == 1) {
        if (playerScore == 3) {
            printf("\nYou won the game!\n");
        } else {
            printf("\nComputer won the game.\n");
        }
    } else {
        printf("\nThe game is a draw.\n");
    }
}

// Get the player's choice
int getPlayerChoice() {
    int choice;

    printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
    scanf("%d", &choice);

    while (choice < 0 || choice > 2) {
        printf("Invalid choice. Please enter a number between 0 and 2: ");
        scanf("%d", &choice);
    }

    return choice;
}

// Get the computer's choice
int getComputerChoice() {
    int choice;

    choice = rand() % 3;

    return choice;
}

// Determine the winner of the round
int determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return 0;
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        return 1;
    } else {
        return -1;
    }
}