//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 4

// A tile represents a single cell on the game board.
typedef struct tile {
    int value;         // The value of the tile (0 for blank).
    int revealed;      // Whether the tile has been revealed.
} tile;

// The game board is represented as a 2D array of tiles.
tile board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board.
void init_board() {
    // Initialize the board with random values.
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 8 + 1;
            board[i][j].revealed = 0;
        }
    }

    // Place a blank tile in the center of the board.
    board[BOARD_SIZE / 2][BOARD_SIZE / 2].value = 0;
}

// Function to print the game board.
void print_board() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].value);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to get a valid move from the user.
void get_move(int *x, int *y) {
    while (1) {
        printf("Enter the coordinates of the tile you want to reveal (x, y): ");
        scanf("%d %d", x, y);

        if (*x < 1 || *x > BOARD_SIZE || *y < 1 || *y > BOARD_SIZE) {
            printf("Invalid coordinates. Please try again.\n");
        } else if (board[*x - 1][*y - 1].revealed) {
            printf("Tile already revealed. Please try again.\n");
        } else {
            break;
        }
    }
}

// Function to check if the game is over.
int is_game_over() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

// Main game loop.
int main() {
    // Initialize the game board.
    init_board();

    // Print the initial game board.
    print_board();

    // Main game loop.
    while (!is_game_over()) {
        // Get a valid move from the user.
        int x, y;
        get_move(&x, &y);

        // Reveal the tile at the specified coordinates.
        board[x - 1][y - 1].revealed = 1;

        // Print the updated game board.
        print_board();

        // Check if the game is over.
        if (is_game_over()) {
            printf("Congratulations! You won the game.\n");
        }
    }

    return 0;
}