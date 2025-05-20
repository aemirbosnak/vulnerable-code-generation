//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE 4 // Size of the grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2 // Total pairs for matching
#define MAX_ATTEMPTS 2 // Allowable attempts to guess

void initialize_board(char board[SIZE][SIZE], char temp[SIZE][SIZE]) {
    char letters[TOTAL_PAIRS * 2]; // Each letter appears twice

    // Fill letters with alphabet characters for pairs
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        letters[i * 2] = 'A' + i; // Intensity of letters from A onwards
        letters[i * 2 + 1] = 'A' + i;
    }

    // Shuffle letters
    for (int i = TOTAL_PAIRS * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp_char = letters[i];
        letters[i] = letters[j];
        letters[j] = temp_char;
    }

    // Populate the board with shuffled letters
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*'; // Start with hidden letters
            temp[i][j] = letters[i * SIZE + j]; // Actual letters
        }
    }
}

void display_board(char board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_position(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int check_match(char temp[SIZE][SIZE], char board[SIZE][SIZE], int first_row, int first_col, int second_row, int second_col) {
    return temp[first_row][first_col] == temp[second_row][second_col];
}

int main() {
    srand(time(0)); // Initialize random number generator

    char board[SIZE][SIZE];       // Player view of the board
    char temp[SIZE][SIZE];        // Actual letters on the board
    int guessed[SIZE][SIZE] = {0}; // Tracker for guessed pairs
    
    initialize_board(board, temp); // Setup initial game state
    int total_attempts = 0;
    int matches_found = 0;

    printf("Welcome to the Memory Game!\n");
    printf("Try to match the letter pairs. Enter coordinates in the format: row column (0-indexed).\n");

    while (matches_found < TOTAL_PAIRS) {
        display_board(board); // Show current state of the board

        int first_row, first_col, second_row, second_col;

        // Get first letter guess
        printf("Enter the coordinates of the first letter (row col): ");
        scanf("%d %d", &first_row, &first_col);
        
        if (!is_valid_position(first_row, first_col) || guessed[first_row][first_col]) {
            printf("Invalid position or already guessed! Try again.\n");
            continue;
        }

        board[first_row][first_col] = temp[first_row][first_col]; // Reveal letter
        display_board(board); // Show board with the first choice
        
        // Get second letter guess
        printf("Enter the coordinates of the second letter (row col): ");
        scanf("%d %d", &second_row, &second_col);
        
        if (!is_valid_position(second_row, second_col) || (first_row == second_row && first_col == second_col) || guessed[second_row][second_col]) {
            printf("Invalid position or already guessed! Try again.\n");
            board[first_row][first_col] = '*'; // Hide again
            continue;
        }

        board[second_row][second_col] = temp[second_row][second_col]; // Reveal letter
        display_board(board); // Show board with the second choice

        // Check if they match
        if (check_match(temp, board, first_row, first_col, second_row, second_col)) {
            printf("Match Found!\n");
            guessed[first_row][first_col] = 1; // Mark as guessed
            guessed[second_row][second_col] = 1;
            matches_found++;
        } else {
            printf("No match! Try again.\n");
            total_attempts++;

            // Provide a limited number of attempts to the player
            if (total_attempts >= MAX_ATTEMPTS) {
                board[first_row][first_col] = '*'; // Hide again
                board[second_row][second_col] = '*'; // Hide again
                total_attempts = 0; // Reset attempts
            }
        }
        
        printf("\nPress Enter to continue...");
        getchar(); // Wait for user input
        getchar();
    }

    printf("Congratulations! You've found all the matches!\n");
    return 0;
}