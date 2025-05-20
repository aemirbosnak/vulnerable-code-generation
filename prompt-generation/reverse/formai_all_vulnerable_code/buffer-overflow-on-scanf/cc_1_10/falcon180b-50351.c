//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8
#define MATCH_VALUE 100

typedef struct {
    char value;
    char isFaceUp;
} Card;

void printCard(Card card) {
    if (card.isFaceUp) {
        printf("%c", card.value);
    } else {
        printf("X");
    }
}

void printBoard(Card board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printCard(board[i][j]);
        }
        printf("\n");
    }
}

int flipCard(Card board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS &&!board[row][col].isFaceUp) {
        board[row][col].isFaceUp =!board[row][col].isFaceUp;
        return 1;
    }
    return 0;
}

int checkMatch(Card board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col].isFaceUp) {
        return 1;
    }
    return 0;
}

int checkWin(Card board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!checkMatch(board, i, j)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    Card board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j].value = '2' + (char) rand() % 10;
            board[i][j].isFaceUp = 0;
        }
    }

    int moves = 0;
    while (!checkWin(board)) {
        printBoard(board);
        int choice;
        printf("Enter your move (row and column): ");
        scanf("%d %d", &choice, &choice);
        if (flipCard(board, choice - 1, choice - 1)) {
            moves++;
        }
    }

    printBoard(board);
    printf("You won in %d moves!\n", moves);

    return 0;
}