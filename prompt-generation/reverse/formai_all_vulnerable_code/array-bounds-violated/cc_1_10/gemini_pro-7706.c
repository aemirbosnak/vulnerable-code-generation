//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimensions of the game board
#define WIDTH 4
#define HEIGHT 4

// Possible card values
#define CARD_BACK ' '
#define CARD_A 'A'
#define CARD_B 'B'
#define CARD_C 'C'
#define CARD_D 'D'

// Game state
typedef enum {
    GUESSING,
    MATCHING,
    GAME_OVER
} GameState;

// Card struct
typedef struct {
    char value;
    int flipped;
} Card;

// Game board
Card board[WIDTH][HEIGHT];

// Current game state
GameState state = GUESSING;

// First card flipped
Card *first_card = NULL;

// Second card flipped
Card *second_card = NULL;

// Number of matches
int matches = 0;

// Initialize the game board
void init_board() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of all the possible card values
    char values[] = {CARD_A, CARD_B, CARD_C, CARD_D};

    // Shuffle the array
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int j = rand() % (WIDTH * HEIGHT);
        char temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Assign the values to the game board
    int index = 0;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j].value = values[index++];
            board[i][j].flipped = 0;
        }
    }
}

// Print the game board
void print_board() {
    printf("  ");
    for (int i = 0; i < WIDTH; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < WIDTH; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < HEIGHT; j++) {
            if (board[i][j].flipped) {
                printf("%c ", board[i][j].value);
            } else {
                printf("%c ", CARD_BACK);
            }
        }
        printf("\n");
    }
}

// Get the player's guess
void get_guess(int *row, int *col) {
    printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
    scanf("%d %d", row, col);

    // Adjust for 0-based indexing
    (*row)--;
    (*col)--;
}

// Flip a card
void flip_card(int row, int col) {
    // Check if the card is already flipped
    if (board[row][col].flipped) {
        printf("That card is already flipped!\n");
        return;
    }

    // Flip the card
    board[row][col].flipped = 1;
}

// Check if two cards match
int cards_match(Card *card1, Card *card2) {
    return card1->value == card2->value;
}

// Check if the game is over
int game_over() {
    return matches == (WIDTH * HEIGHT) / 2;
}

// Play the game
void play_game() {
    while (state != GAME_OVER) {
        // Print the game board
        print_board();

        // Get the player's guess
        int row, col;
        get_guess(&row, &col);

        // Flip the card
        flip_card(row, col);

        // Check if the card matches the first card flipped
        if (state == GUESSING) {
            first_card = &board[row][col];
            state = MATCHING;
        } else if (state == MATCHING) {
            second_card = &board[row][col];

            // Check if the cards match
            if (cards_match(first_card, second_card)) {
                // Increment the number of matches
                matches++;

                // Reset the state
                state = GUESSING;
                first_card = NULL;
                second_card = NULL;
            } else {
                // Flip the cards back over
                first_card->flipped = 0;
                second_card->flipped = 0;

                // Reset the state
                state = GUESSING;
                first_card = NULL;
                second_card = NULL;
            }
        }

        // Check if the game is over
        if (game_over()) {
            state = GAME_OVER;
        }
    }

    // Print the final game board
    print_board();

    // Congratulate the player
    printf("Congratulations! You won the game!\n");
}

// Main function
int main() {
    // Initialize the game board
    init_board();

    // Play the game
    play_game();

    return 0;
}