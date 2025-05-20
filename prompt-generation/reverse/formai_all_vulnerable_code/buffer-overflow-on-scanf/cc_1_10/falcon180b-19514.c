//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int roll_dice() {
    return rand() % 6 + 1;
}

// Function to simulate a game of dice
void play_game() {
    int player_score = 0, computer_score = 0;
    char play_again;

    // Roll for the first player
    printf("Rolling for Player 1...\n");
    player_score += roll_dice();
    printf("Player 1 scores %d.\n", player_score);

    // Roll for the second player
    printf("Rolling for Player 2 (Computer)...\n");
    computer_score += roll_dice();
    printf("Computer scores %d.\n", computer_score);

    // Determine the winner
    if (player_score > computer_score) {
        printf("Player 1 wins!\n");
    } else if (computer_score > player_score) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    // Ask the player if they want to play again
    printf("Do you want to play again? (y/n): ");
    scanf("%c", &play_again);

    // If the player wants to play again, start a new game
    if (play_again == 'y' || play_again == 'Y') {
        play_game();
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the game of dice!\n");
    play_game();

    return 0;
}