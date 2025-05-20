//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides on the dice
#define DICE_SIDES 6

// Function to roll the dice
int roll_dice() {
    return rand() % DICE_SIDES + 1;
}

// Function to play a round of the game
void play_round(int player_score, int opponent_score) {
    int player_roll, opponent_roll;
    char play_again;

    // Roll the dice for the player and opponent
    player_roll = roll_dice();
    opponent_roll = roll_dice();

    // Determine the winner of the round
    if (player_roll > opponent_roll) {
        printf("You win the round with a roll of %d!\n", player_roll);
        player_score++;
    } else if (opponent_roll > player_roll) {
        printf("You lose the round with a roll of %d.\n", player_roll);
        opponent_score++;
    } else {
        printf("It's a tie with a roll of %d.\n", player_roll);
    }

    // Ask the player if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again);

    // If the player wants to play again, continue the game
    if (play_again == 'y' || play_again == 'Y') {
        play_round(player_score, opponent_score);
    } else {
        // Otherwise, end the game
        printf("Game over. Your final score is %d.\n", player_score);
    }
}

int main() {
    int player_score = 0, opponent_score = 0;
    char play_again;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_round(player_score, opponent_score);

    return 0;
}