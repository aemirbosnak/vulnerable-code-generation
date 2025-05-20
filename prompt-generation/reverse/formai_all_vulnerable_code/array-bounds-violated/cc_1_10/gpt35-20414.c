//FormAI DATASET v1.0 Category: Chess AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the board as a 2D array */
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

/* Define a function to display the board */
void display_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* Define a function to make a move */
void make_move(int start_col, int start_row, int end_col, int end_row) {
    char piece = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    board[end_row][end_col] = piece;
}

/* Define a function to check if a move is valid */
bool is_valid_move(int start_col, int start_row, int end_col, int end_row) {
    char piece = board[start_row][start_col];
    if (piece == ' ') {
        return false;
    }
    if (end_row >= 8 || end_row < 0 || end_col >= 8 || end_col < 0) {
        return false;
    }
    if (board[end_row][end_col] != ' ') {
        return false;
    }
    return true;
}

int main() {
    printf("Welcome to the Chess AI Program!\n");
    printf("Here is the starting board:\n");
    display_board();
    int start_col, start_row, end_col, end_row;
    printf("Enter the starting column (0-7): ");
    scanf("%d", &start_col);
    printf("Enter the starting row (0-7): ");
    scanf("%d", &start_row);
    printf("Enter the ending column (0-7): ");
    scanf("%d", &end_col);
    printf("Enter the ending row (0-7): ");
    scanf("%d", &end_row);
    if (is_valid_move(start_col, start_row, end_col, end_row)) {
        make_move(start_col, start_row, end_col, end_row);
        printf("Here is the new board:\n");
        display_board();
    } else {
        printf("Invalid move, try again!\n");
    }
    return 0;
}