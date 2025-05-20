//FormAI DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define ROWS 4
#define COLS 4

// Define the number of different cards
#define NUM_OF_CARDS 8

// Define a struct to hold card information
typedef struct {
    int value; // Card value
    int revealed; // True if card has been revealed
} Card;

// Shuffle an integer array using the Fisher-Yates shuffle
void shuffle(int* array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create an array of values for the cards
    int card_values[NUM_OF_CARDS];
    for (int i = 0; i < NUM_OF_CARDS; i++) {
        card_values[i] = i % (NUM_OF_CARDS / 2) + 1;
    }

    // Shuffle the card values
    shuffle(card_values, NUM_OF_CARDS);

    // Create the game board
    Card board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j].value = card_values[i * COLS + j];
            board[i][j].revealed = 0;
        }
    }

    // Initialize game variables
    int moves = 0;
    int pairs_found = 0;

    // Print game instructions
    printf("Welcome to the Memory Game!\n");
    printf("The goal of the game is to find all the matching pairs of cards.\n");
    printf("To reveal a card, enter its row and column number (separated by a space).\n");
    printf("Good luck!\n\n");

    // Main game loop
    while (pairs_found < NUM_OF_CARDS / 2) {

        // Print game board
        printf("Moves: %d\n\n", moves);
        printf("   ");
        for (int j = 0; j < COLS; j++) {
            printf("%d  ", j);
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            printf("%d  ", i);
            for (int j = 0; j < COLS; j++) {
                if (board[i][j].revealed) {
                    printf("%d  ", board[i][j].value);
                } else {
                    printf("*  ");
                }
            }
            printf("\n");
        }

        // Get user input
        int row1, col1, row2, col2;
        printf("\nEnter the row and column of a card to reveal (e.g. '0 1'): ");
        scanf("%d %d", &row1, &col1);

        // Make sure the card isn't already revealed or off the board
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS || board[row1][col1].revealed) {
            printf("Invalid input\n");
            continue;
        }

        // Reveal the card
        board[row1][col1].revealed = 1;
        moves++;

        // Get user input for second card
        printf("\nEnter the row and column of another card to reveal (e.g. '1 2'): ");
        scanf("%d %d", &row2, &col2);

        // Make sure the second card isn't already revealed or off the board
        if (row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS || board[row2][col2].revealed) {
            printf("Invalid input\n");
            board[row1][col1].revealed = 0;
            continue;
        }

        // Reveal the second card
        board[row2][col2].revealed = 1;
        moves++;

        // Check if the two revealed cards match
        if (board[row1][col1].value == board[row2][col2].value) {
            pairs_found++;
            printf("\nYou found a pair!\n");
        } else {
            printf("\nSorry, those cards don't match.\n");
            board[row1][col1].revealed = 0;
            board[row2][col2].revealed = 0;
        }
    }

    // Print the final game board and statistics
    printf("\nCongratulations! You found all the pairs in %d moves.\n", moves);
    printf("   ");
    for (int j = 0; j < COLS; j++) {
        printf("%d  ", j);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%d  ", board[i][j].value);
        }
        printf("\n");
    }

    return 0;
}