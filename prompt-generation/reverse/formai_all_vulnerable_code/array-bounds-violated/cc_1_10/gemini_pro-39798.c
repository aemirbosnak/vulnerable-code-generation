//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 12
#define NUM_PAIRS 6

typedef struct {
    int value;
    int is_flipped;
} card_t;

int main() {
    // Initialize the deck of cards
    card_t deck[NUM_CARDS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        deck[2*i].value = i;
        deck[2*i+1].value = i;
    }

    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Print the deck of cards
    printf("The deck of cards is:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");

    // Initialize the game board
    int game_board[4][3] = {0};

    // Print the game board
    printf("The game board is:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", game_board[i][j]);
        }
        printf("\n");
    }

    // Get the player's input
    int row1, col1, row2, col2;
    printf("Enter the coordinates of the first card: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of the second card: ");
    scanf("%d %d", &row2, &col2);

    // Flip the cards
    deck[game_board[row1][col1]].is_flipped = 1;
    deck[game_board[row2][col2]].is_flipped = 1;

    // Print the game board
    printf("The game board is:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", game_board[i][j]);
        }
        printf("\n");
    }

    // Check if the cards match
    if (deck[game_board[row1][col1]].value == deck[game_board[row2][col2]].value) {
        printf("You matched a pair!\n");
    } else {
        printf("Sorry, you didn't match a pair.\n");
    }

    return 0;
}