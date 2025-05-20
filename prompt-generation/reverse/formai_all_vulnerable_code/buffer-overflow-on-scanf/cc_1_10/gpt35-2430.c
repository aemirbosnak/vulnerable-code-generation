//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>

// Initialize the board with empty spaces
char board[8][8] = {
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '}
};

// Print the current state of the board
void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a move is valid
int isValidMove(int x1, int y1, int x2, int y2) {
    // Make sure the starting position is within the board and contains a checker piece
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || board[x1][y1] != 'o') {
        return 0;
    }
    // Make sure the ending position is within the board and is an empty space
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7 || board[x2][y2] != ' ') {
        return 0;
    }
    // Make sure the move is diagonal
    if (abs(x2 - x1) != abs(y2 - y1)) {
        return 0;
    }
    // Make sure the move is only one diagonal space or two diagonal spaces if taking an opposing piece
    if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1) {
        return 1;
    }
    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 && board[(x1+x2)/2][(y1+y2)/2] == 'x') {
        return 1;
    }
    return 0;
}

// Move a checker piece
void movePiece(int x1, int y1, int x2, int y2) {
    // Move the piece to the new location
    board[x2][y2] = 'o';
    board[x1][y1] = ' ';
    // If taking an opposing piece, remove it from the board
    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2) {
        board[(x1+x2)/2][(y1+y2)/2] = ' ';
    }
}

int main() {
    // Initialize the board with checker pieces
    board[0][1] = 'x';
    board[0][3] = 'x';
    board[0][5] = 'x';
    board[0][7] = 'x';
    board[1][0] = 'x';
    board[1][2] = 'x';
    board[1][4] = 'x';
    board[1][6] = 'x';
    board[2][1] = 'x';
    board[2][3] = 'x';
    board[2][5] = 'x';
    board[2][7] = 'x';
    printBoard();

    int x1, y1, x2, y2;
    while (1) {
        // Get the player's move
        printf("Enter a move (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // Check if the move is valid and perform the move if it is
        if (isValidMove(x1, y1, x2, y2)) {
            movePiece(x1, y1, x2, y2);
        } else {
            printf("Invalid move.\n");
        }
        // Print the updated board
        printBoard();
    }

    return 0;
}