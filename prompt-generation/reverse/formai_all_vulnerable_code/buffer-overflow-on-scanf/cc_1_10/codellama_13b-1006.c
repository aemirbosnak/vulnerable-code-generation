//Code Llama-13B DATASET v1.0 Category: Game ; Style: rigorous
// A simple C game that simulates a game of rock-paper-scissors

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for rock, paper, and scissors
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

// Function to get the user's choice
int getUserChoice() {
    int choice;
    printf("Enter 1 for rock, 2 for paper, or 3 for scissors: ");
    scanf("%d", &choice);
    return choice;
}

// Function to generate a random computer choice
int getComputerChoice() {
    srand(time(NULL));
    return (rand() % 3) + 1;
}

// Function to determine the winner
int determineWinner(int user, int computer) {
    if (user == computer) {
        return 0;
    } else if (user == ROCK) {
        return computer == SCISSORS ? 1 : -1;
    } else if (user == PAPER) {
        return computer == ROCK ? 1 : -1;
    } else if (user == SCISSORS) {
        return computer == PAPER ? 1 : -1;
    }
}

// Main function
int main() {
    int user, computer, winner;

    // Get the user's choice
    user = getUserChoice();

    // Generate a random computer choice
    computer = getComputerChoice();

    // Determine the winner
    winner = determineWinner(user, computer);

    // Print the results
    if (winner == 1) {
        printf("You win!\n");
    } else if (winner == -1) {
        printf("You lose!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}