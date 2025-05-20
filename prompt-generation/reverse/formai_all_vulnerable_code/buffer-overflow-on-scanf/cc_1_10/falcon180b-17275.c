//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
// This is a simple game of rock, paper, scissors. // The user plays against the computer.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    ROCK,
    PAPER,
    SCISSORS
};

int main() {
    int user_choice, computer_choice;
    int num_rounds = 10;
    int num_wins = 0;
    int num_losses = 0;
    int num_ties = 0;

    srand(time(NULL));

    // Play num_rounds rounds of the game.
    for (int i = 0; i < num_rounds; i++) {
        // Get the user's choice.
        printf("Round %d:\n", i + 1);
        printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
        scanf("%d", &user_choice);

        // Generate the computer's choice.
        computer_choice = rand() % 3;

        // Determine the winner.
        if (user_choice == computer_choice) {
            printf("It's a tie!\n");
            num_ties++;
        } else if ((user_choice == ROCK && computer_choice == SCISSORS) ||
                   (user_choice == PAPER && computer_choice == ROCK) ||
                   (user_choice == SCISSORS && computer_choice == PAPER)) {
            printf("You win!\n");
            num_wins++;
        } else {
            printf("You lose.\n");
            num_losses++;
        }
    }

    // Print the results.
    printf("\nResults:\n");
    printf("Wins: %d\n", num_wins);
    printf("Losses: %d\n", num_losses);
    printf("Ties: %d\n", num_ties);

    return 0;
}