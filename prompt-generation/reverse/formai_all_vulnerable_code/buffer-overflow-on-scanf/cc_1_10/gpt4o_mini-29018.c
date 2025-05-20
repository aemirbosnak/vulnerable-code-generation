//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], int row, int col, char player);
int checkWinner(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char player1 = 'X', player2 = 'O';
    int row, col;
    int turn = 0; // 0 for player 1, 1 for player 2
    int gameStatus;

    initializeBoard(board);

    while (1) {
        displayBoard(board);
        if (turn % 2 == 0) {
            printf("Player 1 (X), enter your move (row and column): ");
        } else {
            printf("Player 2 (O), enter your move (row and column): ");
        }
        
        scanf("%d %d", &row, &col);

        if (makeMove(board, row, col, turn % 2 == 0 ? player1 : player2)) {
            gameStatus = checkWinner(board);
            if (gameStatus != 0) {
                displayBoard(board);
                if (gameStatus == 1) {
                    printf("Player 1 (X) wins!\n");
                } else if (gameStatus == 2) {
                    printf("Player 2 (O) wins!\n");
                }
                break;
            }
            if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            }
            turn++;
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }
    
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return 1; // Move was successful
    }
    return 0; // Invalid move
}

int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == 'X' ? 1 : 2; // Return player number
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == 'X' ? 1 : 2; // Return player number
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == 'X' ? 1 : 2; // Return player number
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == 'X' ? 1 : 2; // Return player number
    }

    return 0; // No winner
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Found an empty space
            }
        }
    }
    return 1; // No spaces left
}