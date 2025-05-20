//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { UND = '_', O = 'O', X = 'X' };

void displayBoard(char board[], int size);
int makeMove(char board[], int size, char player);
char checkWinner(char board[], int size);

int main(void) {
    const int SIZE = 3;
    char board[SIZE * SIZE];

    for (int i = 0; i < SIZE * SIZE; i++) board[i] = UND;
    displayBoard(board, SIZE);

    char player1 = O, player2 = X;
    char curplayer = player1;
    while (1) {
        int cell = makeMove(board, SIZE, curplayer);
        if (cell < 0) {
            printf("Terminating...\n");
            return 0;
        }
        board[cell] = curplayer;
        displayBoard(board, SIZE);

        char winner = checkWinner(board, SIZE);
        if (winner != UND) {
            printf("Player %c wins!\n", winner);
            return 0;
        }
        if (curplayer == player1) curplayer = player2;
        else curplayer = player1;
    }
    // unreachable code
}

void displayBoard(char board[], int size) {
    printf("\n");
    for (int i = 0; i < size * size; i++) {
        printf("%c ", board[i]);
        if ((i + 1) % size == 0) printf("\n");
    }
    printf("\n");
}

int makeMove(char board[], int size, char player) {
    srand((unsigned)time(NULL));
    printf("Player %c move: ", player);
    int cell = -1;
    while (1) {
        scanf("%d", &cell);
        if (cell == 0) return -1;
        if (cell < 1 || cell > size * size) {
            printf("Invalid cell. Please choose a cell between 1 and %d: ", size * size);
            continue;
        }
        cell--;
        if (board[cell] != UND) {
            printf("Cell already occupied. Choose another cell: ");
            continue;
        }
        break;
    }
    return cell;
}

char checkWinner(char board[], int size) {
    // Check rows
    for (int i = 0; i < size; i++) {
        int row_start = i * size;
        if (board[row_start] != UND && board[row_start] == board[row_start + 1] && board[row_start] == board[row_start + 2]) {
            return board[row_start];
        }
    }

    // Check columns
    for (int i = 0; i < size; i++) {
        if (board[i] != UND && board[i] == board[i + size] && board[i] == board[i + 2 * size]) {
            return board[i];
        }
    }

    // Check diagonals
    if (board[0] != UND && board[0] == board[4] && board[0] == board[8]) {
        return board[0];
    }
    if (board[2] != UND && board[2] == board[4] && board[2] == board[6]) {
        return board[2];
    }

    // Check for tie
    int is_tie = 1;
    for (int i = 0; i < size * size; i++) {
        if (board[i] == UND) {
            is_tie = 0;
            break;
        }
    }
    if (is_tie) return 'T';

    // No winner yet
    return UND;
}