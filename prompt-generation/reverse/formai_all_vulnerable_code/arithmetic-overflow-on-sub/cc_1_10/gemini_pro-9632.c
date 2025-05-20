//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Card struct
typedef struct {
    int value;
    int is_revealed;
} Card;

// Board struct
typedef struct {
    Card cards[BOARD_SIZE][BOARD_SIZE];
} Board;

// Function to initialize the board
void init_board(Board *board) {
    // Generate random values for the cards
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cards[i][j].value = rand() % 8 + 1;
            board->cards[i][j].is_revealed = 0;
        }
    }

    // Shuffle the cards
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            Card temp = board->cards[i][j];
            board->cards[i][j] = board->cards[x][y];
            board->cards[x][y] = temp;
        }
    }
}

// Function to print the board
void print_board(Board *board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->cards[i][j].is_revealed) {
                printf("%d ", board->cards[i][j].value);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

// Function to get the user's input
void get_input(int *row, int *col) {
    printf("Enter the row and column of the card you want to reveal: ");
    scanf("%d %d", row, col);
}

// Function to check if the two cards match
int check_match(Card *card1, Card *card2) {
    return card1->value == card2->value;
}

// Function to play the game
void play_game(Board *board) {
    int row1, col1, row2, col2;
    int matches = 0;

    while (matches < 8) {
        // Get the user's input
        get_input(&row1, &col1);

        // Reveal the first card
        board->cards[row1 - 1][col1 - 1].is_revealed = 1;

        // Print the board
        print_board(board);

        // Get the user's input
        get_input(&row2, &col2);

        // Reveal the second card
        board->cards[row2 - 1][col2 - 1].is_revealed = 1;

        // Print the board
        print_board(board);

        // Check if the two cards match
        if (check_match(&board->cards[row1 - 1][col1 - 1], &board->cards[row2 - 1][col2 - 1])) {
            printf("Match!\n");
            matches++;
        } else {
            printf("No match.\n");

            // Hide the two cards
            board->cards[row1 - 1][col1 - 1].is_revealed = 0;
            board->cards[row2 - 1][col2 - 1].is_revealed = 0;
        }
    }

    // Game over
    printf("Congratulations! You won the game!\n");
}

// Main function
int main() {
    // Create a new board
    Board board;

    // Initialize the board
    init_board(&board);

    // Play the game
    play_game(&board);

    return 0;
}