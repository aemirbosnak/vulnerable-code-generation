//FormAI DATASET v1.0 Category: Chess AI ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define global variables
#define ROWS 8
#define COLUMNS 8

// Create the chess board
char board[ROWS][COLUMNS] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Print the board on the screen
void print_board() {
    printf("\n   A  B  C  D  E  F  G  H\n");
    printf(" +-----------------------+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------------+\n\n");
}

// Start the game
int main() {
    print_board(); // Print the initial board
    
    // Prompt to enter a move
    char move[5];
    printf("Enter a move (e.g. E2E4): ");
    scanf("%s", move);

    // Update the board with the move
    int start_row = move[1] - '0' - 1;
    int start_col = move[0] - 'A';
    int end_row = move[3] - '0' - 1;
    int end_col = move[2] - 'A';
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    
    print_board(); // Print the updated board
    
    return 0;
}