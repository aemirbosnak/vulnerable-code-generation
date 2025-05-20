//FormAI DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1-6
int randInt() {
    return (rand() % 6) + 1;
}

// Function to play one round of the game
int play(int* p1Score, int* p2Score) {
    int roll = randInt(); // Roll the dice

    if (roll == 1) { // If roll is 1, player scores 0 and turn ends
        *p1Score += 0;
        return 0;
    }
    else { // Otherwise, add roll to player's score
        *p1Score += roll;
    }

    roll = randInt(); // Roll dice for second player

    if (roll == 1) { // Same as above for second player
        *p2Score += 0;
        return 0;
    }
    else {
        *p2Score += roll;
    }

    return 1; // Return 1 to indicate turn is not over
}

// Function to determine winner
int determineWinner(int p1Score, int p2Score) {
    if (p1Score >= 50 && p1Score > p2Score) { // Player 1 wins
        return 1;
    }
    else if (p2Score >= 50 && p2Score > p1Score) { // Player 2 wins
        return 2;
    }
    else if (p1Score >= 50 && p2Score >= 50 && p1Score == p2Score) { // Tie
        return -1;
    }
    else { // Game is not over
        return 0;
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    int p1Score = 0; // Player 1 score
    int p2Score = 0; // Player 2 score
    int turnOver = 0; // Flag to indicate if turn is over
    int winner = 0; // Flag to indicate if a winner has been determined

    // Loop until winner is determined
    while (!winner) {
        // Player 1's turn
        turnOver = play(&p1Score, &p2Score);
        printf("Player 1: %d\n", p1Score); // Print player 1's score
        if (turnOver) { // If turn is not over, ask if player wants to roll again
            char input;
            printf("Roll again? (y/n)\n");
            scanf(" %c", &input); // Get user input
            if (input == 'n') { // If user does not want to roll again, turn is over
                turnOver = 1;
            }
        }
        if (p1Score >= 50 || p2Score >= 50) { // Check if game is over
            winner = determineWinner(p1Score, p2Score);
        }
        if (turnOver) { // If turn is over, reset player's score
            p1Score = 0;
        }

        // Player 2's turn (same as above)
        turnOver = play(&p2Score, &p1Score);
        printf("Player 2: %d\n", p2Score);
        if (turnOver) {
            char input;
            printf("Roll again? (y/n)\n");
            scanf(" %c", &input);
            if (input == 'n') {
                turnOver = 1;
            }
        }
        if (p1Score >= 50 || p2Score >= 50) {
            winner = determineWinner(p1Score, p2Score);
        }
        if (turnOver) {
            p2Score = 0;
        }
    }

    // Print winner
    if (winner == 1) {
        printf("Player 1 wins!\n");
    }
    else if (winner == 2) {
        printf("Player 2 wins!\n");
    }
    else { // Tie
        printf("Tie game!\n");
    }

    return 0;
}