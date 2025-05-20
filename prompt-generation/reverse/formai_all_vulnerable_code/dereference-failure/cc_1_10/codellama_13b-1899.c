//Code Llama-13B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 6
#define NUM_CARDS 36

// Function prototypes
void print_board(int board[NUM_ROWS][NUM_COLS]);
void fill_board(int board[NUM_ROWS][NUM_COLS]);
void shuffle_board(int board[NUM_ROWS][NUM_COLS]);
void check_matches(int board[NUM_ROWS][NUM_COLS], int row, int col);

// Global variables
int board[NUM_ROWS][NUM_COLS];
int num_matches = 0;

int main() {
    // Initialize the board
    fill_board(board);

    // Shuffle the board
    shuffle_board(board);

    // Print the board
    print_board(board);

    // Check for matches
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            check_matches(board, row, col);
        }
    }

    // Print the number of matches
    printf("Number of matches: %d\n", num_matches);

    return 0;
}

// Function definitions
void print_board(int board[NUM_ROWS][NUM_COLS]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

void fill_board(int board[NUM_ROWS][NUM_COLS]) {
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            board[row][col] = (row * NUM_COLS) + col + 1;
        }
    }
}

void shuffle_board(int board[NUM_ROWS][NUM_COLS]) {
    srand(time(NULL));
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            int random_row = rand() % NUM_ROWS;
            int random_col = rand() % NUM_COLS;
            int temp = board[row][col];
            board[row][col] = board[random_row][random_col];
            board[random_row][random_col] = temp;
        }
    }
}

void check_matches(int board[NUM_ROWS][NUM_COLS], int row, int col) {
    if (board[row][col] == board[row][col + 1] || board[row][col] == board[row][col - 1] ||
        board[row][col] == board[row + 1][col] || board[row][col] == board[row - 1][col]) {
            num_matches++;
    }
}