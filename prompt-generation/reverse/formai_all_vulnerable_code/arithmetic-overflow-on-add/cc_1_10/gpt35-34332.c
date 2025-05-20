//FormAI DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Function to initialize the board
void init_board(char board[SIZE][SIZE]) {
    int i, j;

    // Initialize all cells to '-'
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Set red pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < SIZE; j++) {
            if ((i+j)%2 == 0)
                board[i][j] = 'R';   
        }
    }

    // Set white pieces
    for (i = SIZE-1; i >= SIZE-3; i--) {
        for (j = 0; j < SIZE; j++) {
            if ((i+j)%2 == 0)
                board[i][j] = 'W';   
        }
    }
}

// Function to display the board
void display_board(char board[SIZE][SIZE]) {
    int i, j;

    // Display column numbers
    printf(" ");
    for (i = 0; i < SIZE; i++) {
        printf("  %d", i);
    }
    printf("\n");

    // Display horizontal line
    printf("  ");
    for (i = 0; i < SIZE; i++) {
        printf("+--");
    }
    printf("+\n");

    // Display cells
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < SIZE; j++) {
            printf("| %c", board[i][j]);
        }
        printf("|\n");

        // Display horizontal line
        printf("  ");
        for (j = 0; j < SIZE; j++) {
            printf("+--");
        }
        printf("+\n");
    }
}

// Function to make a move
void make_move(char board[SIZE][SIZE], int cur_row, int cur_col, int dest_row, int dest_col) {
    // Check if move is legal
    if (dest_row < 0 || dest_col < 0 || dest_row >= SIZE || dest_col >= SIZE) {
        printf("Error: Move is outside the board.\n");
        return;
    }
    if (board[dest_row][dest_col] != '-') {
        printf("Error: Destination cell is not empty.\n");
        return;
    }

    // Move piece
    board[dest_row][dest_col] = board[cur_row][cur_col];
    board[cur_row][cur_col] = '-';

    // Check for capture
    int row_diff = dest_row - cur_row;
    int col_diff = dest_col - cur_col;
    int capture_row = cur_row + (row_diff / 2);
    int capture_col = cur_col + (col_diff / 2);
    if (abs(row_diff) == 2 && abs(col_diff) == 2 && board[capture_row][capture_col] != '-') {
        board[capture_row][capture_col] = '-';
    }
}

int main() {
    char board[SIZE][SIZE];
    int cur_row, cur_col, dest_row, dest_col;

    init_board(board);
    display_board(board);

    // Game loop
    while (1) {
        // Get user input
        printf("Enter current row: ");
        scanf("%d", &cur_row);
        printf("Enter current column: ");
        scanf("%d", &cur_col);
        printf("Enter destination row: ");
        scanf("%d", &dest_row);
        printf("Enter destination column: ");
        scanf("%d", &dest_col);

        // Make move
        make_move(board, cur_row, cur_col, dest_row, dest_col);
        display_board(board);
    }

    return 0;
}