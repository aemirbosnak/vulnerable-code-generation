//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the structure of a memory card.
struct card {
    int number;
    bool revealed;
};

// Define the size of the game board.
#define BOARD_SIZE 4

// Create the game board.
struct card board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board.
void init_board() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Generate a random number for each card.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].number = rand() % 8 + 1;
            board[i][j].revealed = false;
        }
    }
}

// Print the game board.
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].number);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Get the coordinates of a card.
bool get_coordinates(int *x, int *y) {
    printf("Enter the coordinates of the card you want to reveal (x, y): ");
    return scanf("%d %d", x, y) == 2;
}

// Reveal a card.
void reveal_card(int x, int y) {
    board[x][y].revealed = true;
}

// Check if two cards match.
bool cards_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1].number == board[x2][y2].number;
}

// Check if the game is over.
bool game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return false;
            }
        }
    }
    return true;
}

// Main game loop.
int main() {
    // Initialize the game board.
    init_board();

    // Print the game board.
    print_board();

    // Get the coordinates of the first card.
    int x1, y1;
    if (!get_coordinates(&x1, &y1)) {
        printf("Invalid coordinates.\n");
        return EXIT_FAILURE;
    }

    // Reveal the first card.
    reveal_card(x1, y1);

    // Print the game board.
    print_board();

    // Get the coordinates of the second card.
    int x2, y2;
    if (!get_coordinates(&x2, &y2)) {
        printf("Invalid coordinates.\n");
        return EXIT_FAILURE;
    }

    // Reveal the second card.
    reveal_card(x2, y2);

    // Print the game board.
    print_board();

    // Check if the cards match.
    if (cards_match(x1, y1, x2, y2)) {
        printf("Match!\n");
    } else {
        printf("No match.\n");
    }

    // Check if the game is over.
    if (game_over()) {
        printf("Game over!\n");
        return EXIT_SUCCESS;
    }

    // Continue the game.
    return EXIT_SUCCESS;
}