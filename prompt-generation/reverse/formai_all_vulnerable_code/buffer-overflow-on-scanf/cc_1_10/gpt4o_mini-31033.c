//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int current_player = 0;
int target_number;
int guesses;

void start_game();
void player_turn(int player_num);
int guess_number(int player_num);
void reset_game();

int main() {
    srand(time(NULL));  // Seed the random number generator
    printf("Welcome to the Multiplayer Guessing Game!\n");
    int choice;

    do {
        start_game();
        printf("\nPlay again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Thank you for playing!\n");
    return 0;
}

void start_game() {
    target_number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    guesses = 0;
    current_player = 0;  // Reset current player
    printf("\nA number between %d and %d has been chosen. Let's start the game!\n", MIN_NUMBER, MAX_NUMBER);
    player_turn(current_player);
}

void player_turn(int player_num) {
    printf("\nPlayer %d's turn.\n", player_num + 1);
    int guess = guess_number(player_num);
    guesses++;  // Increment the number of guesses

    if (guess < target_number) {
        printf("Your guess is too low.\n");
        player_turn((player_num + 1) % MAX_PLAYERS);  // Next player's turn
    } 
    else if (guess > target_number) {
        printf("Your guess is too high.\n");
        player_turn((player_num + 1) % MAX_PLAYERS);  // Next player's turn
    } 
    else {
        printf("Congratulations Player %d! You've guessed the number in %d guesses!\n", player_num + 1, guesses);
    }
}

int guess_number(int player_num) {
    int guess;
    printf("Enter your guess (Player %d): ", player_num + 1);
    scanf("%d", &guess);

    if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
        printf("Invalid guess! Please guess a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
        return guess_number(player_num);  // Ask for guess again
    }

    return guess;  // Return valid guess
}

void reset_game() {
    current_player = 0;  // Reset player
    guesses = 0;  // Reset guess count
    target_number = 0;  // Reset target number
}