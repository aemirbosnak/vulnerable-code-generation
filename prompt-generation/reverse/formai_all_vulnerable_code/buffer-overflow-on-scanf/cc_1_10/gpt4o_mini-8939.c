//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 5

void displayRules() {
    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("Choose your move:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("To quit the game, enter 0.\n\n");
}

int getComputerMove() {
    return rand() % 3 + 1; // Returns 1, 2, or 3
}

const char* moveToString(int move) {
    switch (move) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

void playGame() {
    int playerMove, computerMove;
    int playerScore = 0, computerScore = 0;

    for (int round = 1; round <= MAX_ROUNDS; ++round) {
        printf("Round %d:\n", round);
        printf("Your Score: %d | Computer Score: %d\n", playerScore, computerScore);

        printf("Enter your move (1-Rock, 2-Paper, 3-Scissors, 0-Quit): ");
        scanf("%d", &playerMove);

        if (playerMove == 0) {
            printf("You chose to quit the game. Thank you for playing!\n");
            return;
        }

        computerMove = getComputerMove();
        printf("Computer chose: %s\n", moveToString(computerMove));

        if (playerMove == computerMove) {
            printf("It's a tie!\n");
        } else if ((playerMove == 1 && computerMove == 3) || 
                   (playerMove == 2 && computerMove == 1) || 
                   (playerMove == 3 && computerMove == 2)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }
        printf("\n");
    }

    printf("Final Score: You %d - Computer %d\n", playerScore, computerScore);
    if (playerScore > computerScore) {
        printf("Congratulations! You are the overall winner!\n");
    } else if (computerScore > playerScore) {
        printf("Oh no! The computer won the game.\n");
    } else {
        printf("It's an overall tie!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    displayRules();
    playGame();
    
    return 0;
}