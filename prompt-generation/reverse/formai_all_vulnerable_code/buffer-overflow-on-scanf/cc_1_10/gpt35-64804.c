//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>

// Function to print the tic tac toe board
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won or not
int checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to check if the game has ended in a draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the move from the human player
void humanMove(char board[3][3], char player) {
    int row, col;
    printf("Enter row number (1-3): ");
    scanf("%d", &row);
    printf("Enter column number (1-3): ");
    scanf("%d", &col);
    row--;
    col--;
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        printf("Invalid move!\n");
        humanMove(board, player);
    } else {
        board[row][col] = player;
    }
}

// Function to get the move from the AI player
void aiMove(char board[3][3], char aiPlayer, char humanPlayer) {
    // Check if AI can win in the next move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = aiPlayer;
                if (checkWin(board, aiPlayer)) {
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    // Check if human can win in the next move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = humanPlayer;
                if (checkWin(board, humanPlayer)) {
                    board[i][j] = aiPlayer;
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    // AI makes a random move
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != '-');
    board[row][col] = aiPlayer;
}

// Main function for the game
int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    char humanPlayer, aiPlayer;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose X or O: ");
    scanf(" %c", &humanPlayer);
    while (humanPlayer != 'X' && humanPlayer != 'O') {
        printf("Invalid choice! Choose X or O: ");
        scanf(" %c", &humanPlayer);
    }
    if (humanPlayer == 'X') {
        aiPlayer = 'O';
    } else {
        aiPlayer = 'X';
    }
    // Game loop
    while (!checkWin(board, humanPlayer) && !checkWin(board, aiPlayer) && !checkDraw(board)) {
        printBoard(board);
        humanMove(board, humanPlayer);
        if (checkWin(board, humanPlayer) || checkDraw(board)) {
            break;
        }
        aiMove(board, aiPlayer, humanPlayer);
    }
    printBoard(board);
    if (checkWin(board, humanPlayer)) {
        printf("You win!\n");
    } else if (checkWin(board, aiPlayer)) {
        printf("AI wins!\n");
    } else {
        printf("Game ends in a draw!\n");
    }
    return 0;
}