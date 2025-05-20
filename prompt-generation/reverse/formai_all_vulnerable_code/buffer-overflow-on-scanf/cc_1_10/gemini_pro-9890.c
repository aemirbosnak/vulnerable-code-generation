//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NUM_DIGITS 16

typedef struct {
    char name[20];
    char ip_address[20];
    int wins;
    int losses;
} player_t;

typedef struct {
    int num_digits;
    int binary_num;
    int decimal_num;
} game_t;

// Function to generate a random binary number
int generate_random_binary_number(int num_digits) {
    int binary_num = 0;
    for (int i = 0; i < num_digits; i++) {
        binary_num = binary_num << 1;
        binary_num += rand() % 2;
    }
    return binary_num;
}

// Function to convert a binary number to decimal
int binary_to_decimal(int binary_num) {
    int decimal_num = 0;
    int power = 1;
    while (binary_num != 0) {
        decimal_num += (binary_num % 10) * power;
        binary_num /= 10;
        power *= 2;
    }
    return decimal_num;
}

// Function to start a new game
void start_game(player_t players[], int num_players) {
    // Generate a random binary number
    int num_digits = rand() % MAX_NUM_DIGITS + 1;
    int binary_num = generate_random_binary_number(num_digits);
    int decimal_num = binary_to_decimal(binary_num);

    // Send the binary number to all players
    for (int i = 0; i < num_players; i++) {
        printf("Player %s, your binary number is: %d\n", players[i].name, binary_num);
    }

    // Wait for all players to guess the decimal number
    int guesses[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Player %s, guess the decimal number: ", players[i].name);
        scanf("%d", &guesses[i]);
    }

    // Check if any player guessed the correct decimal number
    bool winner_found = false;
    int winning_player_index = -1;
    for (int i = 0; i < num_players; i++) {
        if (guesses[i] == decimal_num) {
            winner_found = true;
            winning_player_index = i;
            break;
        }
    }

    // Announce the winner
    if (winner_found) {
        printf("Player %s wins!\n", players[winning_player_index].name);
        players[winning_player_index].wins++;
    } else {
        printf("No one guessed the correct number!\n");
    }
}

// Function to print the game statistics
void print_stats(player_t players[], int num_players) {
    printf("Game statistics:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %s:\n", players[i].name);
        printf("Wins: %d\n", players[i].wins);
        printf("Losses: %d\n", players[i].losses);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the players
    player_t players[MAX_PLAYERS];
    int num_players = 0;
    while (num_players < MAX_PLAYERS) {
        printf("Enter player %d's name: ", num_players + 1);
        scanf("%s", players[num_players].name);
        printf("Enter player %d's IP address: ", num_players + 1);
        scanf("%s", players[num_players].ip_address);
        players[num_players].wins = 0;
        players[num_players].losses = 0;
        num_players++;
    }

    // Start the game loop
    while (true) {
        start_game(players, num_players);

        // Print the game statistics
        print_stats(players, num_players);

        // Ask the players if they want to play again
        char input[2];
        printf("Do you want to play again? (y/n) ");
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
    }

    return 0;
}