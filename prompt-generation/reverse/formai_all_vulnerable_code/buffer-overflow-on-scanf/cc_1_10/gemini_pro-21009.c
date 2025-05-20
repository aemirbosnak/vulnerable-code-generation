//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of players
#define NUM_PLAYERS 4

// Define the maximum number of numbers to be drawn
#define MAX_NUMBERS 75

// Define the bingo card data structure
typedef struct bingo_card {
    int numbers[CARD_SIZE][CARD_SIZE];
    int marked[CARD_SIZE][CARD_SIZE];
} bingo_card;

// Define the player data structure
typedef struct player {
    char name[20];
    bingo_card card;
    int score;
} player;

// Create a new bingo card
bingo_card create_card() {
    bingo_card card;

    // Initialize the card with all zeros
    memset(card.numbers, 0, sizeof(card.numbers));
    memset(card.marked, 0, sizeof(card.marked));

    // Generate random numbers for the card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            int number;
            do {
                number = rand() % MAX_NUMBERS + 1;
            } while (card.numbers[i][j] == number);
            card.numbers[i][j] = number;
        }
    }

    return card;
}

// Mark a number on a bingo card
void mark_number(bingo_card *card, int number) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Check if a bingo card has won
int check_win(bingo_card *card) {
    // Check rows
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            count += card->marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < CARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < CARD_SIZE; i++) {
            count += card->marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        count1 += card->marked[i][i];
        count2 += card->marked[i][CARD_SIZE - 1 - i];
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Play a round of bingo
void play_round(player *players, int num_players, int *drawn_numbers) {
    // Draw a random number
    int number;
    do {
        number = rand() % MAX_NUMBERS + 1;
    } while (drawn_numbers[number - 1]);
    drawn_numbers[number - 1] = 1;

    // Mark the number on each player's card
    for (int i = 0; i < num_players; i++) {
        mark_number(&players[i].card, number);
    }

    // Check if any players have won
    for (int i = 0; i < num_players; i++) {
        if (check_win(&players[i].card)) {
            players[i].score++;
        }
    }
}

// Play a game of bingo
void play_game(player *players, int num_players) {
    // Initialize the array of drawn numbers
    int drawn_numbers[MAX_NUMBERS];
    memset(drawn_numbers, 0, sizeof(drawn_numbers));

    // Play rounds until a player has won 5 times
    while (1) {
        play_round(players, num_players, drawn_numbers);

        // Check if any players have won 5 times
        int winner = -1;
        for (int i = 0; i < num_players; i++) {
            if (players[i].score == 5) {
                winner = i;
                break;
            }
        }

        // If a player has won, print the winner's name and exit the game
        if (winner != -1) {
            printf("The winner is %s!\n", players[winner].name);
            return;
        }
    }
}

// Get a player's name
void get_player_name(char *name) {
    printf("Enter your name: ");
    scanf("%s", name);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of players
    int num_players;
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);

    // Create the players
    player players[NUM_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        get_player_name(players[i].name);
        players[i].card = create_card();
        players[i].score = 0;
    }

    // Play the game
    play_game(players, num_players);

    return 0;
}