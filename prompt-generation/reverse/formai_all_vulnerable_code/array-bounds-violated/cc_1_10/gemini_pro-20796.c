//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Data structures and function prototypes.
typedef struct {
    int value;
    int flipped;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];

void print_board();
void flip_tile(int row, int col);
int check_win();

int main() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Initialize the game board.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10;
            board[i][j].flipped = 0;
        }
    }

    // Print the initial game board.
    print_board();

    // Main game loop.
    while (1) {
        // Get the user's input.
        int row, col;
        printf("Enter the row and column of the tile you want to flip (0-based): ");
        scanf("%d %d", &row, &col);

        // Flip the tile.
        flip_tile(row, col);

        // Print the updated game board.
        print_board();

        // Check if the player has won.
        if (check_win()) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}

void print_board() {
    // Print the top border of the board.
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("+---+");
    }
    printf("\n");

    // Print each row of the board.
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].flipped) {
                printf(" %d |", board[i][j].value);
            } else {
                printf(" X |");
            }
        }
        printf("\n");

        // Print the bottom border of the board.
        printf("   ");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("+---+");
        }
        printf("\n");
    }
}

void flip_tile(int row, int col) {
    // Flip the tile.
    board[row][col].flipped = 1;
}

int check_win() {
    // Check if all tiles are flipped.
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].flipped) {
                return 0;
            }
        }
    }

    return 1;
}