//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 5
#define COLS 10
#define MAX_GUESSES 10

// Define the game board
char board[ROWS][COLS] = {{'.', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'O'},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', ' '},
                         {'.', '.', '.', '.', '.', '.', '.', '.', '.', ' '}};

// Define the game variables
int guesses = 0;
int correct = 0;
int row = 0;
int col = 0;

// Define the game functions
void print_board();
void get_guess();
void check_guess();
void game_over();

int main() {
    // Print the game board
    print_board();

    // Game loop
    while (guesses < MAX_GUESSES) {
        // Get a guess from the player
        get_guess();

        // Check if the guess is correct
        check_guess();

        // Update the game state
        if (correct) {
            // If the guess is correct, mark the space with an 'X'
            board[row][col] = 'X';
            correct = 0;
        } else {
            // If the guess is incorrect, decrease the number of guesses left
            guesses--;
        }

        // Print the updated game board
        print_board();
    }

    // Game over, print the final board
    game_over();

    return 0;
}

// Print the game board
void print_board() {
    printf("   1 | 2 | 3\n");
    printf("  ---------\n");
    printf(" 4 | 5 | 6\n");
    printf("  ---------\n");
    printf(" 7 | 8 | 9\n");
    printf("  ---------\n");
    printf("10 | 11 | 12\n");
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Get a guess from the player
void get_guess() {
    printf("Enter a row (1-5) and a column (1-10): ");
    scanf("%d%d", &row, &col);
}

// Check if the guess is correct
void check_guess() {
    if (board[row][col] == 'X') {
        correct++;
        printf("Correct! You found the X in position %d, %d.\n", row, col);
    } else {
        printf("Incorrect. The X is not in position %d, %d.\n", row, col);
    }
}

// Game over, print the final board and the number of correct guesses
void game_over() {
    printf("Game over! You made %d correct guesses.\n", correct);
    print_board();
}