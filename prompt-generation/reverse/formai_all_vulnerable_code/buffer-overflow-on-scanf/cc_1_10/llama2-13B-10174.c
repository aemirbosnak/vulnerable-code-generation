//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYER1 "Player 1"
#define PLAYER2 "Player 2"
#define ROCK "Rock"
#define PAPER "Paper"
#define SCISSORS "Scissors"

// Function to get player input
int getPlayerInput(const char *prompt) {
    int input;
    printf("%s: ", prompt);
    scanf("%d", &input);
    return input;
}

// Function to determine the winner
int determineWinner(int player1, int player2) {
    if (player1 == ROCK && player2 == SCISSORS) {
        return PLAYER1;
    } else if (player1 == SCISSORS && player2 == ROCK) {
        return PLAYER2;
    } else if (player1 == PAPER && player2 == ROCK) {
        return PLAYER1;
    } else if (player1 == ROCK && player2 == PAPER) {
        return PLAYER2;
    } else {
        return 0; // Tie
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Player 1's turn
    int player1Input = getPlayerInput(PLAYER1 " chooses: ");
    int player2Input = getPlayerInput(PLAYER2 " chooses: ");

    // Determine the winner
    int winner = determineWinner(player1Input, player2Input);

    // Print the result
    if (winner == PLAYER1) {
        printf("%s wins! %d\n", PLAYER1, player1Input);
    } else if (winner == PLAYER2) {
        printf("%s wins! %d\n", PLAYER2, player2Input);
    } else {
        printf("Tie! %d and %d are equal.\n", player1Input, player2Input);
    }

    return 0;
}