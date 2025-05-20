//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8
#define MATCH 1
#define NO_MATCH 0

int board[ROWS][COLS]; // 2D array to hold the card values
int flipped[ROWS][COLS]; // 2D array to hold the flipped state of each card
int matches = 0; // variable to keep track of the number of matches

void initBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % TOTAL_CARDS + 1; // assign random card value to each position on the board
            flipped[i][j] = 0; // set flipped state to false for all cards
        }
    }
}

void drawBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (flipped[i][j] == 0) {
                printf("_ ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int checkMatch(int i, int j) {
    if (flipped[i][j] == 0) {
        flipped[i][j] = 1;
        if (board[i][j] == board[i][j+1]) {
            return MATCH;
        } else {
            flipped[i][j] = 0;
            return NO_MATCH;
        }
    } else {
        return NO_MATCH;
    }
}

int checkWin() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS-1; j++) {
            if (checkMatch(i, j) == MATCH) {
                matches++;
            }
        }
    }
    if (matches == TOTAL_CARDS/2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    int moves = 0;
    while (1) {
        drawBoard();
        int choice;
        printf("\nEnter your move (row col): ");
        scanf("%d %d", &choice, &choice);
        if (choice >= 1 && choice <= ROWS) {
            int col = choice % COLS;
            if (col >= 0 && col < COLS) {
                if (checkMatch(choice-1, col) == MATCH) {
                    moves++;
                    if (checkWin()) {
                        printf("\nCongratulations! You won in %d moves!\n", moves);
                        break;
                    }
                } else {
                    flipped[choice-1][col] = 0;
                }
            }
        } else {
            printf("\nInvalid move. Try again.\n");
        }
        moves++;
        if (moves == TOTAL_CARDS*2) {
            printf("\nGame over. You lose.\n");
            break;
        }
    }
    return 0;
}