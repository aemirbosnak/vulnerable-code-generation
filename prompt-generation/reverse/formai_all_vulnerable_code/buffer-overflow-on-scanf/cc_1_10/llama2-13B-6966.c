//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COIN_SIDES 2
#define PLAYER_WIN 1
#define COMPUTER_WIN 0

// Global variables
int player_wins = 0;
int computer_wins = 0;
int coin_tosses = 0;

// Function to generate a random coin toss result
int coin_toss() {
    int random_result;
    random_result = rand() % COIN_SIDES;
    return random_result;
}

// Function to play a game of Crazy Coin Flip
void play_game() {
    int player_choice;
    int computer_choice;

    // Display the game menu
    printf("Welcome to Crazy Coin Flip!\n");
    printf("Choose a coin side to flip: (1) Heads or (2) Tails\n");

    // Get the player's choice
    printf("Player, please enter your choice: ");
    scanf("%d", &player_choice);

    // Get the computer's choice
    computer_choice = coin_toss();

    // Flip the coin and determine the winner
    if (player_choice == computer_choice) {
        printf("Tie! Both players chose the same side.\n");
    } else if (player_choice == 1 && computer_choice == 2) {
        printf("Player wins! Player chose Heads, while the computer chose Tails.\n");
        player_wins++;
    } else if (player_choice == 2 && computer_choice == 1) {
        printf("Computer wins! Player chose Tails, while the computer chose Heads.\n");
        computer_wins++;
    }

    // Increment the number of coin tosses
    coin_tosses++;

    // Display the current win count
    printf("Player wins: %d\n", player_wins);
    printf("Computer wins: %d\n", computer_wins);
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    // Play the game until the user quits
    while (1) {
        play_game();
        printf("Do you want to play again? (y/n): ");
        char user_input;
        scanf(" %c", &user_input);

        if (user_input == 'n' || user_input == 'N') {
            break;
        }
    }

    return 0;
}