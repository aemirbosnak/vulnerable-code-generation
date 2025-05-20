//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void printIntroduction();
void printResults(int player, int computer);

int main() {

    // Variables for player and computer scores
    int playerScore = 0;
    int computerScore = 0;

    // Seed the random function
    srand(time(NULL));

    // Print the introduction message
    printIntroduction();

    // Play the game for 10 rounds
    for (int i = 1; i <= 10; i++) {
        
        // Generate the computer's choice (0 = rock, 1 = paper, 2 = scissors)
        int computerChoice = rand() % 3;

        // Get the player's choice (0 = rock, 1 = paper, 2 = scissors)
        int playerChoice;
        printf("\nRound %d: ", i);
        printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
        scanf("%d", &playerChoice);

        // Determine the winner and update the scores
        if ((playerChoice == 0 && computerChoice == 2) || (playerChoice == 1 && computerChoice == 0) || (playerChoice == 2 && computerChoice == 1)) {
            printf("You win this round!\n");
            playerScore++;
        } else if (playerChoice == computerChoice) {
            printf("This round is a tie.\n");
        } else {
            printf("The computer wins this round.\n");
            computerScore++;
        }
    }

    // Print the final results
    printResults(playerScore, computerScore);

    return 0;
}

// Function to print the introduction message
void printIntroduction() {
    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("You will play against the computer for 10 rounds.\n");
    printf("Enter 0 for rock, 1 for paper, or 2 for scissors.\n");
    printf("Let's begin!\n");
}

// Function to print the final results
void printResults(int player, int computer) {
    printf("\nFinal results:\n");
    printf("Player: %d\n", player);
    printf("Computer: %d\n", computer);

    if (player > computer) {
        printf("Congratulations, you win the game!\n");
    } else if (player == computer) {
        printf("The game is a tie.\n");
    } else {
        printf("Sorry, the computer wins the game.\n");
    }
}