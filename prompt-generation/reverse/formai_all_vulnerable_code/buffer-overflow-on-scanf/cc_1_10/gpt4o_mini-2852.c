//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>

#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    // check rows and columns for victory
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0] == PLAYER ? 1 : -1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i] == PLAYER ? 1 : -1;
    }
    // check diagonals for victory
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0] == PLAYER ? 1 : -1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2] == PLAYER ? 1 : -1;

    return 0; // no winner yet
}

int evaluateMove(char board[3][3], int *bestRow, int *bestCol) {
    int bestScore = -2; // initialize to a low score
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI; // assume AI is making this move
                int score = -checkWinner(board);
                board[i][j] = EMPTY; // undo the move
                if (score > bestScore) {
                    bestScore = score;
                    *bestRow = i;
                    *bestCol = j;
                }
            }
        }
    }
    return bestScore;
}

void aiMove(char board[3][3]) {
    int row, col;
    evaluateMove(board, &row, &col);
    board[row][col] = AI; // place AI's move
}

void playerMove(char board[3][3]) {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d %d", &row, &col);
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
        printf("Invalid move! Try again.\n");
        playerMove(board); // Prompt again for valid move
    } else {
        board[row][col] = PLAYER; // place player's move
    }
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return 0; // there's still empty space
    return 1; // no empty spaces left
}

int main() {
    char board[3][3] = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    };

    printBoard(board);
    while (1) {
        playerMove(board);
        printBoard(board);
        if (checkWinner(board) == 1) {
            printf("You win!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        aiMove(board);
        printBoard(board);
        if (checkWinner(board) == -1) {
            printf("AI wins!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}