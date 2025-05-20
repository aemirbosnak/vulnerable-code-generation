//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("  0   1   2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  ---|---|---\n");
        }
    }
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

int getRandomAvailableMove() {
    int availableMoves[SIZE * SIZE];
    int count = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                availableMoves[count++] = i * SIZE + j;
            }

    if (count == 0) return -1; // No available moves

    int randomIndex = rand() % count;
    return availableMoves[randomIndex];
}

void playAI() {
    int move = getRandomAvailableMove();
    if (move != -1) {
        board[move / SIZE][move % SIZE] = currentPlayer;
    }
}

void playGame() {
    while (1) {
        printBoard();

        if (checkWin('X')) {
            printf("X wins in a most whimsical flourish!\n");
            break;
        }

        if (isBoardFull()) {
            printf("The canvas is filled, a stalemate emerges!\n");
            break;
        }

        printf("Current player: %c\n", currentPlayer);

        if (currentPlayer == 'X') {
            int row, col;
            printf("Choose your coordinates (row and column): ");
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
            } else {
                printf("Oh, the coordinates drift in the void, try again!\n");
                continue; // Ask for input again
            }
        } else {
            printf("The AI conjures a move...\n");
            playAI();
        }

        switchPlayer();
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    playGame();
    printBoard();
    printf("Game over, the echoes of the moves linger...\n");
    return 0;
}