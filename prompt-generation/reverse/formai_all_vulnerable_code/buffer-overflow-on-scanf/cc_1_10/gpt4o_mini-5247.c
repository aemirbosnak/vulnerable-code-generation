//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[SIZE][SIZE];

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 1 && i < 3) {
                board[i][j] = PLAYER1;
            } else if ((i + j) % 2 == 1 && i > 4) {
                board[i][j] = PLAYER2;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the move is valid
int isValidMove(int sx, int sy, int dx, int dy, char player) {
    if (dx < 0 || dx >= SIZE || dy < 0 || dy >= SIZE) return 0;
    if (board[dx][dy] != EMPTY) return 0;

    int direction = (player == PLAYER1) ? 1 : -1;
    if ((dx == sx + direction && abs(dy - sy) == 1) || (dx == sx + 2 * direction && abs(dy - sy) == 2)) {
        if (abs(dy - sy) == 2) {
            int midX = (sx + dx) / 2;
            int midY = (sy + dy) / 2;
            if (board[midX][midY] != EMPTY && board[midX][midY] != player) return 1; // captures opponent's piece
            return 0;
        }
        return 1; // simple move
    }
    return 0;
}

// Function to make a move
void makeMove(int sx, int sy, int dx, int dy, char player) {
    board[dx][dy] = player;
    board[sx][sy] = EMPTY;

    // Capture move
    if (abs(dx - sx) == 2) {
        int midX = (sx + dx) / 2;
        int midY = (sy + dy) / 2;
        board[midX][midY] = EMPTY; // remove opponent's piece
    }
}

// Function to convert input to board indices
int convertInput(char col, int row, int *x, int *y) {
    if (col < 'A' || col > 'H' || row < 1 || row > SIZE) return 0;
    *x = row - 1;
    *y = col - 'A';
    return 1;
}

// Function to play the game
void playGame() {
    char player = PLAYER1;
    int sx, sy, dx, dy;
    while (1) {
        displayBoard();
        printf("Player %c, enter your move (e.g., B2 C3): ", player);
        char startCol, destCol;
        int startRow, destRow;
        int valid;

        valid = scanf(" %c%d %c%d", &startCol, &startRow, &destCol, &destRow);
        if (valid != 4) {
            printf("Invalid input format. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (!convertInput(startCol, startRow, &sx, &sy) || !convertInput(destCol, destRow, &dx, &dy)) {
            printf("Invalid move coordinates. Please try again.\n");
            continue;
        }

        if (isValidMove(sx, sy, dx, dy, player)) {
            makeMove(sx, sy, dx, dy, player);
            player = (player == PLAYER1) ? PLAYER2 : PLAYER1; // Switch players
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}