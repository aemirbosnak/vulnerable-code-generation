//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>

// Function to check if the board is full
int isBoardFull(char board[]) {
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ')
            return 0;
    }
    return 1;
}

// Function to check if the given player has won
int checkWin(char board[], char ch) {
    if ((board[1] == ch && board[2] == ch && board[3] == ch) ||
        (board[4] == ch && board[5] == ch && board[6] == ch) ||
        (board[7] == ch && board[8] == ch && board[9] == ch) ||
        (board[1] == ch && board[4] == ch && board[7] == ch) ||
        (board[2] == ch && board[5] == ch && board[8] == ch) ||
        (board[3] == ch && board[6] == ch && board[9] == ch) ||
        (board[1] == ch && board[5] == ch && board[9] == ch) ||
        (board[3] == ch && board[5] == ch && board[7] == ch))
        return 1;
    else
        return 0;
}

// Function to print the board
void printBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[1], board[2], board[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[4], board[5], board[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[7], board[8], board[9]);
    printf("\n");
}

// Function to update a board position with a given character
void updateBoard(char board[], int pos, char ch) {
    board[pos] = ch;
}

// Function to get the best move for the AI
int getBestMove(char board[], char aiCh, char playerCh, int depth) {
    // Check if AI can win in this move
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ') {
            board[i] = aiCh;
            if (checkWin(board, aiCh)) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }

    // Check if Player can win in next move and block it
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ') {
            board[i] = playerCh;
            if (checkWin(board, playerCh)) {
                board[i] = aiCh;
                return i;
            }
            board[i] = ' ';
        }
    }

    // Check for corners
    if (board[1] == ' ') {
        return 1;
    } else if (board[3] == ' ') {
        return 3;
    } else if (board[7] == ' ') {
        return 7;
    } else if (board[9] == ' ') {
        return 9;
    }

    // Check for center
    if (board[5] == ' ') {
        return 5;
    }

    // Check for sides
    if (board[2] == ' ') {
        return 2;
    } else if (board[4] == ' ') {
        return 4;
    } else if (board[6] == ' ') {
        return 6;
    } else if (board[8] == ' ') {
        return 8;
    }

    // If there is no best move, return -1
    return -1;
}

// Function to play the game
void playGame() {
    char board[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("You will be playing against the machine.\n");
    printf("Are you ready? Let's start!\n");
    printf("You are X, and the machine is O.\n");
    printf("\n");
    printBoard(board);

    char playerCh = 'X';
    char aiCh = 'O';

    int turn = 0;

    while (!isBoardFull(board)) {
        if (turn == 0) {
            // Player Turn
            int playerMove;
            printf("Your turn! Enter a number [1-9]: ");
            scanf("%d", &playerMove);
            if (playerMove < 1 || playerMove > 9 || board[playerMove] != ' ') {
                printf("Invalid move! Try again.\n");
                continue;
            }
            updateBoard(board, playerMove, playerCh);
            printBoard(board);
            if (checkWin(board, playerCh)) {
                printf("Congratulations! You Win!\n");
                return;
            }
            turn = 1;
        } else {
            // AI Turn
            printf("It's the machine's turn.\n");
            int aiMove = getBestMove(board, aiCh, playerCh, 0);
            updateBoard(board, aiMove, aiCh);
            printBoard(board);
            if (checkWin(board, aiCh)) {
                printf("The machine wins! Try again.\n");
                return;
            }
            turn = 0;
        }
    }

    printf("The game is a tie.\n");
}

// Main Function
int main() {
    playGame();
    return 0;
}