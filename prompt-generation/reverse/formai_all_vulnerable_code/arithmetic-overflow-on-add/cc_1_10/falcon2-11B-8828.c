//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define MATRIX_SIZE ROWS * COLS

// Declare global variables
int matrix[MATRIX_SIZE];
int matches[MATRIX_SIZE];
int turns = 0;

// Function to initialize the game
void initialize_game() {
    // Shuffle the matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        int random_index = rand() % (i + 1);
        int temp = matrix[i];
        matrix[i] = matrix[random_index];
        matrix[random_index] = temp;
    }

    // Set all matches to 0
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matches[i] = 0;
    }
}

// Function to display the game board
void display_game_board() {
    printf("Game Board: \n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i * COLS + j]);
        }
        printf("\n");
    }
}

// Function to check if a match is found
void check_match(int row, int col) {
    int i = row * COLS + col;
    for (int j = 0; j < MATRIX_SIZE; j++) {
        if (i!= j && matrix[i] == matrix[j]) {
            matches[i] = 1;
        }
    }
}

// Function to play the game
void play_game() {
    initialize_game();
    while (turns < MATRIX_SIZE) {
        printf("Turn: %d\n", turns + 1);
        display_game_board();
        printf("Enter row and column to flip (row, col): ");
        int row, col;
        scanf("%d %d", &row, &col);
        check_match(row, col);
        printf("Match found: %s\n", matches[row * COLS + col]? "Yes" : "No");
        turns++;
    }
    printf("Game Over!\n");
}

int main() {
    play_game();
    return 0;
}