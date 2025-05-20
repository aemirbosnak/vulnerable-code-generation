//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

void initBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
int matchCards(char card1, char card2);
void playGame(char board[ROWS][COLS]);

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    playGame(board);

    return 0;
}

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int matchCards(char card1, char card2) {
    if (card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

void playGame(char board[ROWS][COLS]) {
    int i, j, k, numMatches = 0, numAttempts = 0;
    char card1, card2;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '*') {
                board[i][j] = (char) (rand() % 26 + 'A');
            }
        }
    }

    do {
        printf("Your turn. Enter two cards to flip over:\n");
        scanf("%c %c", &card1, &card2);

        i = (int) card1 - 65;
        j = (int) card2 - 65;

        if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
            if (board[i][j]!= '*') {
                if (matchCards(board[i][j], card1)) {
                    board[i][j] = '*';
                    numMatches++;
                } else {
                    board[i][j] = board[i][j];
                    numAttempts++;
                }
            }
        } else {
            printf("Invalid input.\n");
        }
    } while (numMatches < NUM_CARDS);

    printf("Congratulations! You won the game with %d attempts.\n", numAttempts);
}