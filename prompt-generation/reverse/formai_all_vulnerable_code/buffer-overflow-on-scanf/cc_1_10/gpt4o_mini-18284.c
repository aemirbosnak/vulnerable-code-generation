//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define WINNING_SCORE 100

void clear_buffer() {
    while (getchar() != '\n');
}

int roll_dice() {
    return (rand() % 6) + 1;
}

void print_instructions() {
    printf("Welcome to the Dice Rolling Table Game!\n");
    printf("You can have up to %d players.\n", MAX_PLAYERS);
    printf("On each turn, a player can roll the dice.\n");
    printf("Rolling a 1 means you lose all points accumulated in this turn.\n");
    printf("You can choose to hold your points after rolling.\n");
    printf("The first player to reach a score of %d wins!\n", WINNING_SCORE);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int players[MAX_PLAYERS] = {0}; // Array to hold players' scores
    int turn_score = 0; // Points accumulated in the current turn
    int num_players; // Number of players
    int current_player = 0; // Index of the current player
    char choice; // For player to hold or roll again

    print_instructions();

    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    while (1) {
        scanf("%d", &num_players);
        clear_buffer(); // Clear input buffer

        if (num_players < 2 || num_players > MAX_PLAYERS) {
            printf("Invalid number of players. Please enter a number between 2 and %d: ", MAX_PLAYERS);
        } else {
            break;
        }
    }

    while (1) {
        printf("\nPlayer %d's turn. Current score: %d\n", current_player + 1, players[current_player]);
        turn_score = 0; // Reset turn score 
        choice = 'y'; // Initial choice to roll

        while (choice == 'y' || choice == 'Y') {
            int roll = roll_dice();
            printf("You rolled a %d!\n", roll);

            if (roll == 1) {
                printf("You rolled a 1! You lose points from this turn.\n");
                turn_score = 0; // Reset turn score
                break;
            }

            turn_score += roll;
            printf("Current turn score: %d\n", turn_score);
            printf("Do you want to roll again? (y/n): ");
            choice = getchar();
            clear_buffer(); // Clear input buffer for next input

            if (choice != 'y' && choice != 'Y') {
                players[current_player] += turn_score; // Add turn score to player's total score
                printf("You have chosen to hold. Your total score is now: %d\n", players[current_player]);
            }
        }

        if (players[current_player] >= WINNING_SCORE) {
            printf("Congratulations! Player %d wins with a score of %d!\n", current_player + 1, players[current_player]);
            break;
        }

        // Move to the next player
        current_player = (current_player + 1) % num_players;
    }

    return 0;
}