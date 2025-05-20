//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Board size
#define SIZE 4

// Number of cards
#define CARDS (SIZE * SIZE)

// Card states
#define COVERED 0
#define OPENED 1
#define MATCHED 2

// Card values
typedef enum {
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT
} card_value;

// Card struct
typedef struct {
    card_value value;
    int state;
} card;

// Game board
card board[SIZE][SIZE];

// Function to initialize the game board
void init_board() {
    // Create a deck of cards
    card deck[CARDS];
    for (int i = 0; i < CARDS; i++) {
        deck[i].value = i % 8;
        deck[i].state = COVERED;
    }

    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < CARDS; i++) {
        int j = rand() % CARDS;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Place the cards on the board
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = deck[index++];
        }
    }
}

// Function to print the game board
void print_board() {
    printf("  1 2 3 4\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j].state) {
                case COVERED:
                    printf(" [X]");
                    break;
                case OPENED:
                    printf(" [%d]", board[i][j].value + 1);
                    break;
                case MATCHED:
                    printf(" [M]");
                    break;
            }
        }
        printf("\n");
    }
}

// Function to get a card from the board
card get_card(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        printf("Invalid card coordinates!\n");
        exit(1);
    }

    return board[row][col];
}

// Function to check if two cards match
int match(card card1, card card2) {
    return card1.value == card2.value;
}

// Function to play the game
void play_game() {
    int moves = 0;
    int matched_pairs = 0;

    while (matched_pairs < CARDS / 2) {
        // Get the first card
        printf("Enter the coordinates of the first card (row, col): ");
        int row1, col1;
        scanf("%d %d", &row1, &col1);

        // Get the second card
        printf("Enter the coordinates of the second card (row, col): ");
        int row2, col2;
        scanf("%d %d", &row2, &col2);

        // Open the first card
        card card1 = get_card(row1 - 1, col1 - 1);
        card1.state = OPENED;

        // Open the second card
        card card2 = get_card(row2 - 1, col2 - 1);
        card2.state = OPENED;

        // Check if the cards match
        if (match(card1, card2)) {
            printf("Match!\n");
            matched_pairs++;
            card1.state = MATCHED;
            card2.state = MATCHED;
        } else {
            printf("No match!\n");
            card1.state = COVERED;
            card2.state = COVERED;
        }

        // Print the game board
        print_board();

        moves++;
    }

    printf("You win! You took %d moves.\n", moves);
}

// Main function
int main() {
    init_board();
    play_game();

    return 0;
}