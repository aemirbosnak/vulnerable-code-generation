//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 4 // Number of rows
#define COLS 4 // Number of columns

// Function declarations
void initialize_board(int board[ROWS][COLS], int num_elements);
void print_board(int board[ROWS][COLS]);
void play_game(int board[ROWS][COLS]);

// Main function
int main() {
    int board[ROWS][COLS];
    srand(time(NULL)); // Seed random number generator
    initialize_board(board, (ROWS * COLS) / 2);
    print_board(board);
    play_game(board);
    return 0;
}

/* Function to initialize the game board */
void initialize_board(int board[ROWS][COLS], int num_elements) {
    int values[num_elements];
    int num_occurrences[num_elements];
    int num_dups = 0;
    int index = 0;
    // Initialize arrays
    for (int i = 0; i < num_elements; i++) {
        values[i] = i + 1;
        num_occurrences[i] = 0;
    }
    // Randomly add values to the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (num_dups < num_elements) { // Only allow a maximum of half the board to be duplicates
                index = rand() % num_elements;
                if (num_occurrences[index] < 2) { // Only add value if it hasn't already appeared twice
                    board[i][j] = values[index];
                    num_occurrences[index]++;
                    num_dups++;
                }
                else { // Value has already appeared twice, need to choose a different value
                    j--;
                    continue;
                }
            }
            else { // No more duplicates allowed, just add random values
                index = rand() % num_elements;
                board[i][j] = values[index];
            }
        }
    }
}

/* Function to display the game board */
void print_board(int board[ROWS][COLS]) {
    printf("\nThe game board is:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to play the game */
void play_game(int board[ROWS][COLS]) {
    int row1, col1, row2, col2; // Coordinates of selected cells
    int num_matches = 0; // Number of matched pairs found
    int num_turns = 0; // Number of turns taken
    // Main game loop
    while (num_matches < ROWS*COLS/2) {
        // Get first cell
        printf("Enter the row and column coordinates of the first cell (0 - %d): ", ROWS-1);
        scanf("%d %d", &row1, &col1);
        printf("\n");
        // Check that cell coordinates are valid
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS) {
            printf("Invalid coordinates, try again.\n");
            continue;
        }
        // Check that cell is not already matched
        if (board[row1][col1] == 0) {
            printf("That cell is already matched, try again.\n");
            continue;
        }
        // Get second cell
        printf("Enter the row and column coordinates of the second cell (0 - %d): ", ROWS-1);
        scanf("%d %d", &row2, &col2);
        printf("\n");
        // Check that cell coordinates are valid
        if (row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid coordinates, try again.\n");
            continue;
        }
        // Check that cell is not already matched
        if (board[row2][col2] == 0) {
            printf("That cell is already matched, try again.\n");
            continue;
        }
        // Check if cells match
        num_turns++;
        if (board[row1][col1] == board[row2][col2]) {
            printf("MATCH!\n\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            num_matches++;
        }
        else {
            printf("NO MATCH!\n\n");
        }
        print_board(board);
    }
    printf("Congratulations, you won in %d turns!\n", num_turns);
}