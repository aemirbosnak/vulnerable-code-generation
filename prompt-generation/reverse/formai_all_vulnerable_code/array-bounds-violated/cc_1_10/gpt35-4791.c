//FormAI DATASET v1.0 Category: Chess engine ; Style: artistic
#include <stdio.h>

// Define chess board
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

// Function to print the board
void printBoard() {
    int i, j;
    printf("\n    A  B  C  D  E  F  G  H\n");
    for (i = 0; i < 8; i++) {
        printf("  ------------------------\n");
        printf("%d ", 8 - i);
        for (j = 0; j < 8; j++) {
            printf("| %c", board[i][j]);
        }
        printf("| %d\n", 8 - i);
    }
    printf("  ------------------------\n");
    printf("    A  B  C  D  E  F  G  H\n\n");
}

// Function to move the piece
void move(char from[], char to[]) {
    int from_row = 8 - (from[1] - '0');
    int from_col = from[0] - 'a';
    int to_row = 8 - (to[1] - '0');
    int to_col = to[0] - 'a';
    char piece = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    board[to_row][to_col] = piece;
}

// Main function
int main() {
    printf("\n********* Welcome to C Chess Engine *********\n\n");
    printBoard();
    char move_from[3], move_to[3];
    while (1) {
        printf("\nEnter move (e.g., e2 e4): ");
        scanf("%s %s", move_from, move_to);
        move(move_from, move_to);
        printBoard();
    }
    return 0;
}