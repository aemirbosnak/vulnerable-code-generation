//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// The board of the surrealist game lays floating in the dreamscape
char board[SIZE][SIZE];

// The echoing whispers of X's and O's guiding the moves
char currentPlayer = 'X'; 

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  %c | %c | %c  \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf(" ---+---+--- \n");
        }
    }
    printf("\n");
}

int checkWin() {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer) return 1;
    }
    for (int col = 0; col < SIZE; col++) {
        if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void aiMove() {
    int bestScore = -1000;
    int moveRow = -1, moveCol = -1;
    
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer; // Make the move
                int score = evaluateMoves();
                board[row][col] = ' '; // Undo the move
                
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = row;
                    moveCol = col;
                }
            }
        }
    }
    
    board[moveRow][moveCol] = currentPlayer;
    printf("AI places an %c at (%d, %d).\n", currentPlayer, moveRow + 1, moveCol + 1);
}

int evaluateMoves() {
    if (checkWin()) return 10; // Winning position
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    if (checkWin()) return -10; // Losing position
    currentPlayer = (currentPlayer == 'X') ? 'X' : 'O'; // Switch back
    return 0; // Neutral move
}

void playerMove() {
    int row, col;
    do {
        printf("Enter your move (row and column [1-3]): ");
        scanf("%d %d", &row, &col);
        row--; col--; // Adjust for 0-indexed array
    } while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ');

    board[row][col] = currentPlayer;
}

int main() {
    // The surreal hours of anticipation unfurling before us
    srand(time(NULL));
    initializeBoard();
    printf("Welcome to Surrealist Tic Tac Toe!\n");
    
    while (1) {
        printBoard();
        playerMove();
        if (checkWin()) {
            printBoard();
            printf("Player %c wins in this dream realm.\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("The sand drips through, a draw in this tapestry of time.\n");
            break;
        }

        switchPlayer();
        aiMove();
        if (checkWin()) {
            printBoard();
            printf("Alas, the AI conjures victory!\n");
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("All is still; time collapses in a draw.\n");
            break;
        }
        switchPlayer();
    }
    return 0;
}