//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // display welcome message
    printf("Welcome to the C Table Game!\n");
    printf("*****************************\n\n");

    // initialize variables
    int player_score = 0;
    int computer_score = 0;

    // loop through the game until someone wins
    while (1) {
        // display scores
        printf("Player: %d     Computer: %d\n\n", player_score, computer_score);

        // prompt player for their move
        printf("Enter your move:\n");
        printf("(1) Roll\n");
        printf("(2) Hold\n");

        int move;
        scanf("%d", &move);

        int roll = 0;

        // if player chooses to roll
        if (move == 1) {
            // generate random number between 1 and 6
            roll = rand() % 6 + 1;

            printf("\nYou rolled a %d!\n", roll);

            // if player rolls a 1, their turn is over and they score 0
            if (roll == 1) {
                player_score = 0;
                printf("\nYou rolled a 1! Your turn is over.\n\n");
                printf("*****************************\n");
                printf("    COMPUTER'S TURN\n");
                printf("*****************************\n\n");
                break;
            }
        }
        // if player chooses to hold, add their current score to their total score
        else if (move == 2) {
            player_score += roll;
            printf("\nYou're holding with a score of %d.\n\n", player_score);
            printf("*****************************\n");
            printf("    COMPUTER'S TURN\n");
            printf("*****************************\n\n");
            break;
        }
        // if invalid input is entered by player
        else {
            printf("\nInvalid input. Please try again.");
            continue;
        }

        // computer's turn
        printf("\nComputer's turn:\n\n");

        // computer keeps rolling until their score for the turn is at least 20
        int computer_turn_score = 0;
        while (computer_turn_score < 20) {
            int computer_roll = rand() % 6 + 1;

            printf("The computer rolled a %d!\n", computer_roll);

            // if computer rolls a 1, their turn is over and they score 0
            if (computer_roll == 1) {
                computer_turn_score = 0;
                printf("\nThe computer rolled a 1! Their turn is over.\n");
                printf("*****************************\n\n");
                break;
            }

            // add computer's roll to their turn score and total score
            computer_turn_score += computer_roll;
            computer_score += computer_roll;

            printf("Computer's turn score: %d     Total score: %d\n\n", computer_turn_score, computer_score);

            // if computer's total score is at least 100, display victory message and exit game
            if (computer_score >= 100) {
                printf("\n\n*****************************\n");
                printf("Sorry, computer wins!\n\n");
                printf("Final score:\n");
                printf("Player: %d     Computer: %d\n", player_score, computer_score);
                printf("*****************************\n");
                return 0;
            }
        }

        // add computer's turn score to total score and display message
        computer_score += computer_turn_score;
        printf("Computer is holding with a score of %d.\n\n", computer_turn_score);
        printf("*****************************\n");
        printf("    YOUR TURN\n");
        printf("*****************************\n\n");

        // if player's total score is at least 100, display victory message and exit game
        if (player_score >= 100) {
            printf("\n\n*****************************\n");
            printf("Congratulations, you win!\n\n");
            printf("Final score:\n");
            printf("Player: %d     Computer: %d\n", player_score, computer_score);
            printf("*****************************\n");
            return 0;
        }
    }
    return 0;
}