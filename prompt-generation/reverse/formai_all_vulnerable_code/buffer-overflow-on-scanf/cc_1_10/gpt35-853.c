//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>

// Constants
#define BOARD_SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY ' '

// Function prototypes
void initializeBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
int canMove(char player, char board[][BOARD_SIZE], int row, int col, int rowDir, int colDir);
int move(char player, char board[][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol);
void playGame(char board[][BOARD_SIZE]);

// Main function
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    playGame(board);
    return 0;
}

// Initialize the checkers board
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0 && row < 3) {
                board[row][col] = BLACK;
            } else if ((row + col) % 2 == 0 && row > 4) {
                board[row][col] = WHITE;
            } else {
                board[row][col] = EMPTY;
            }
        }
    }
}

// Print the checkers board
void printBoard(char board[][BOARD_SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("%d\n", row);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

// Check if a player can move from a specific location with a given direction
int canMove(char player, char board[][BOARD_SIZE], int row, int col, int rowDir, int colDir) {
    int newRow = row + rowDir;
    int newCol = col + colDir;
    if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE && board[newRow][newCol] == EMPTY) {
        return 1;
    }
    return 0;
}

// Move a checker piece on the board
int move(char player, char board[][BOARD_SIZE], int startRow, int startCol, int endRow, int endCol) {
    int rowDir, colDir;
    if (player == BLACK) {
        rowDir = 1;
    } else {
        rowDir = -1;
    }
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }
    if (board[endRow][endCol] != EMPTY) {
        return 0;
    }
    if (startRow == endRow && startCol == endCol) {
        return 0;
    }

    // Check if the move is a jump
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2 && board[(startRow + endRow) / 2][(startCol + endCol) / 2] != player && board[(startRow + endRow) / 2][(startCol + endCol) / 2] != EMPTY) {
        board[startRow][startCol] = EMPTY;
        board[endRow][endCol] = player;
        board[(startRow + endRow) / 2][(startCol + endCol) / 2] = EMPTY;
        return 1;
    }

    // Check if the move is a single step
    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1) {
        board[startRow][startCol] = EMPTY;
        board[endRow][endCol] = player;
        return 1;
    }

    return 0;
}

// Play a game of checkers
void playGame(char board[][BOARD_SIZE]) {
    int turn = 1;
    char player = BLACK;
    int startRow, startCol, endRow, endCol;
    int validMove, validInput;
    while (turn <= 50) {
        printf("\n\n");
        printBoard(board);
        validInput = 0;
        while (!validInput) {
            printf("%c's turn:\n", player);
            printf("Enter starting row: ");
            scanf("%d", &startRow);
            printf("Enter starting column: ");
            scanf("%d", &startCol);
            printf("Enter ending row: ");
            scanf("%d", &endRow);
            printf("Enter ending column: ");
            scanf("%d", &endCol);
            if (startRow >= 0 && startRow < BOARD_SIZE && startCol >= 0 && startCol < BOARD_SIZE && endRow >= 0 && endRow < BOARD_SIZE && endCol >= 0 && endCol < BOARD_SIZE) {
                validInput = 1;
            } else {
                printf("Invalid input, please try again.\n");
            }
        }
        validMove = move(player, board, startRow, startCol, endRow, endCol);
        if (validMove) {
            turn++;
            if (player == BLACK) {
                player = WHITE;
            } else {
                player = BLACK;
            }
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}