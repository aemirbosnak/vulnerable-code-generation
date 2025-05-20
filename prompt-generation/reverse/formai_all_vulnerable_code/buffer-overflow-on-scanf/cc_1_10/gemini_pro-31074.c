//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of players
#define NUM_PLAYERS 4

// Define the maximum number of turns
#define MAX_TURNS 75

// Define the bingo card data structure
typedef struct {
    int numbers[CARD_SIZE][CARD_SIZE];
    int marked[CARD_SIZE][CARD_SIZE];
} bingo_card;

// Define the player data structure
typedef struct {
    char name[20];
    bingo_card card;
    int score;
} player;

// Function to create a new bingo card
bingo_card create_card() {
    bingo_card card;

    // Generate random numbers for the card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card.numbers[i][j] = rand() % 75 + 1;
        }
    }

    // Mark all numbers as unmarked
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card.marked[i][j] = 0;
        }
    }

    return card;
}

// Function to print a bingo card
void print_card(bingo_card card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%d ", card.numbers[i][j]);
        }
        printf("\n");
    }
}

// Function to mark a number on a bingo card
void mark_number(bingo_card *card, int number) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Function to check if a bingo card has won
int check_for_win(bingo_card card) {
    // Check rows
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            count += card.marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            count += card.marked[j][i];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        count1 += card.marked[i][i];
        count2 += card.marked[i][CARD_SIZE - 1 - i];
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Function to play a bingo game
void play_bingo() {
    // Create the players
    player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].card = create_card();
        players[i].score = 0;
    }

    // Print the players' cards
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %s's card:\n", players[i].name);
        print_card(players[i].card);
    }

    // Play the game
    int numbers_drawn[MAX_TURNS];
    int turn = 0;
    while (turn < MAX_TURNS) {
        // Generate a random number
        int number = rand() % 75 + 1;
        numbers_drawn[turn] = number;

        // Mark the number on each player's card
        for (int i = 0; i < NUM_PLAYERS; i++) {
            mark_number(&players[i].card, number);
        }

        // Check if any players have won
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (check_for_win(players[i].card)) {
                players[i].score++;
                printf("%s has won!\n", players[i].name);
            }
        }

        // Print the numbers drawn
        printf("Numbers drawn: ");
        for (int i = 0; i <= turn; i++) {
            printf("%d ", numbers_drawn[i]);
        }
        printf("\n");

        turn++;
    }

    // Print the final scores
    printf("Final scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_bingo();

    return 0;
}