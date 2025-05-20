//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

// Function to initialize the board
void initialize_board(char board[][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = '-';
            } else {
                if (i < 3) board[i][j] = 'o';
                else if (i > 4) board[i][j] = 'x';
                else board[i][j] = '-';
            }
        }
    }
}

// Function to print the board
void print_board(char board[][8])
{
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
        printf("  -----------------\n");
    }
}

// Function to validate move
bool is_legal_move(char board[][8], int from_row, int from_col, int to_row, int to_col, char player)
{
    // Check if the target coordinates are within the board
    if (to_row < 0 || to_row > 7 || to_col < 0 || to_col > 7) return false;
    
    // Check if the target location is empty
    if (board[to_row][to_col] != '-') return false;
    
    // Check if the move is diagonal
    if (from_row == to_row || from_col == to_col) return false;
    
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    
    // Check if the move is exactly two squares away
    if (row_diff == 2 || col_diff == 2 || row_diff == -2 || col_diff == -2) {
        
        // Player 1 can only move upwards, player 2 can only move downwards
        if (player == 'o' && row_diff > 0) return false;
        if (player == 'x' && row_diff < 0) return false;
        
        // Check if the opponent's piece is in between the move
        if (board[from_row + row_diff/2][from_col + col_diff/2] == '-') return false;
        
        return true;
    }
    
    return false;
}

// Function to make a move
void make_move(char board[][8], int from_row, int from_col, int to_row, int to_col)
{
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = '-';
    
    // Check if a piece was captured
    if (to_row - from_row == 2 || from_row - to_row == 2) {
        board[from_row + (to_row - from_row)/2][from_col + (to_col - from_col)/2] = '-';
    }
}

int main()
{
    char board[8][8];
    char player = 'o';
    int from_row, from_col, to_row, to_col;
    
    initialize_board(board);
    
    printf("Welcome to the game of checkers!\n");
    printf("Player 1: 'o', Player 2: 'x'\n\n");
    
    while (true) {
        print_board(board);
        printf("\nPlayer %c's turn\n", player);
        printf("Enter move (ex. '0 1 1 2'): ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        
        if (is_legal_move(board, from_row, from_col, to_row, to_col, player)) {
            make_move(board, from_row, from_col, to_row, to_col);
            if (player == 'o') player = 'x';
            else player = 'o';
        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }
    
    return 0;
}