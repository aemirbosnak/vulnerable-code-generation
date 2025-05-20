//Falcon-180B DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define BOARD_ROWS 3

/* Function prototypes */
void initBoard(int board[BOARD_ROWS][BOARD_SIZE]);
void printBoard(int board[BOARD_ROWS][BOARD_SIZE]);
int checkWin(int board[BOARD_ROWS][BOARD_SIZE]);
void swap(int *a, int *b);
int randInt(int min, int max);
void playGame();

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}

void initBoard(int board[BOARD_ROWS][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = randInt(1, 9);
        }
    }
}

void printBoard(int board[BOARD_ROWS][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[BOARD_ROWS][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void playGame() {
    int board[BOARD_ROWS][BOARD_SIZE];
    initBoard(board);

    int player = randInt(1, 2);
    int moves = 0;

    while (!checkWin(board)) {
        printBoard(board);
        printf("Player %d's turn\n", player);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid move\n");
            continue;
        }

        if (board[row][col]!= 0) {
            printf("Cell already filled\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    if (moves == 9) {
        printf("Tie game\n");
    }
}