//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function to print the board
void print_board(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
}

// Function to shuffle the board
void shuffle_board(int board[][BOARD_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int random_i = rand() % BOARD_SIZE;
            int random_j = rand() % BOARD_SIZE;
            int temp = board[i][j];
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

// Function to get user input
void get_input(int* row1, int* col1, int* row2, int* col2) {
    printf("Enter first card position (row col): ");
    scanf("%d %d", row1, col1);
    printf("Enter second card position (row col): ");
    scanf("%d %d", row2, col2);
}

// Function to check if two cards match
int check_match(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        board[row1][col1] = -1;
        board[row2][col2] = -1;
        return 1;
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int row1, col1, row2, col2;
    int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;

    // Initialize and shuffle board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (i * BOARD_SIZE + j) / 2 + 1;
        }
    }
    shuffle_board(board);

    // Main game loop
    while (num_pairs > 0) {
        print_board(board);
        get_input(&row1, &col1, &row2, &col2);
        if (check_match(board, row1, col1, row2, col2)) {
            printf("Match found!\n");
            num_pairs--;
        } else {
            printf("No match found.\n");
        }
    }

    printf("Congratulations! You won the game.\n");

    return 0;
}