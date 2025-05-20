//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void print_board(char board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[MAX_ROWS][MAX_COLS];
    int num_rows, num_cols, matches = 0, attempts = 0;
    char symbol;

    // Initialize the board with symbols
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = (rand() % 2)? 'X' : 'O';
        }
    }

    // Print the initial board
    printf("Initial board:\n");
    print_board(board);

    // Get number of rows and columns from user
    printf("Enter the number of rows (1-10): ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns (1-10): ");
    scanf("%d", &num_cols);

    // Play the game
    while (matches < num_rows * num_cols) {
        attempts++;

        // Get the row and column from user
        printf("Attempt %d:\n", attempts);
        printf("Enter the row (1-%d): ", num_rows);
        scanf("%d", &symbol);
        printf("Enter the column (1-%d): ", num_cols);
        scanf("%d", &symbol);

        // Check if the symbols match
        if (board[symbol - 1][symbol - 1] == 'X') {
            printf("Match found!\n");
            matches++;
        } else {
            printf("No match found.\n");
        }

        // Flip the symbols back
        board[symbol - 1][symbol - 1] = (board[symbol - 1][symbol - 1] == 'X')? 'O' : 'X';
    }

    // Print the final board
    printf("Final board:\n");
    print_board(board);

    return 0;
}