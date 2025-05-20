//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declaration of variables
    int player_score = 0, computer_score = 0, game_round = 1;
    char player_choice, computer_choice;

    // Seed for random number
    srand(time(0));

    // Welcome message
    printf("+==============================+\n");
    printf("|        ROCK PAPER SCISSORS   |\n");
    printf("|            GAME              |\n");
    printf("+==============================+\n\n");

    // Game loop for 10 rounds
    while (game_round <= 10) {
        printf("Round %d\n", game_round);

        // User choice
        printf("Enter 'R' for Rock, 'P' for Paper and 'S' for Scissors: ");
        scanf(" %c", &player_choice);

        // Random computer choice
        switch (rand() % 3) {
            case 0:
                computer_choice = 'R';
                printf("Computer chose Rock\n");
                break;
            case 1:
                computer_choice = 'P';
                printf("Computer chose Paper\n");
                break;
            case 2:
                computer_choice = 'S';
                printf("Computer chose Scissors\n");
                break;
        }

        // Compare choices and update scores
        if (player_choice == computer_choice) {
            printf("It's a Tie!\n");
        } else if (player_choice == 'R' && computer_choice == 'S') {
            printf("You Win!\n");
            player_score++;
        } else if (player_choice == 'P' && computer_choice == 'R') {
            printf("You Win!\n");
            player_score++;
        } else if (player_choice == 'S' && computer_choice == 'P') {
            printf("You Win!\n");
            player_score++;
        } else {
            printf("Computer Wins!\n");
            computer_score++;
        }

        // Display scores
        printf("Player: %d\n", player_score);
        printf("Computer: %d\n", computer_score);

        // Increment game round
        game_round++;

        // Clear screen for next round
        system("clear");
    }

    // Display Final scores and winner
    printf("+==============================+\n");
    printf("|          GAME OVER           |\n");
    printf("+==============================+\n");
    printf("FINAL SCORES:\n");
    printf("Player: %d\n", player_score);
    printf("Computer: %d\n", computer_score);
    if (player_score > computer_score) {
        printf("You Win the Game!\n");
    } else if (player_score < computer_score) {
        printf("Computer Wins the Game!\n");
    } else {
        printf("It's a Draw Game!\n");
    }

    return 0;
}