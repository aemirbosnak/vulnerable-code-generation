//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

int board[ROWS][COLS];
int flipped[ROWS][COLS];
int choice1[2], choice2[2];
int remainingPairs = ROWS * COLS / 2;

void initBoard() {
    int values[ROWS * COLS / 2];
    for (int i = 0; i < ROWS * COLS / 2; i++) {
        values[2*i] = i;
        values[2*i + 1] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % (ROWS * COLS - 2*j - 2*i) + 2*j + 2*i;
            int index = r % (ROWS * COLS - 2*j - 2*i);
            board[i][j] = values[index];
            values[index] = values[ROWS * COLS - 2*j - 2*i - 1];
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flipped[i][j] = 0;
        }
    }
}

void printBoard() {
    printf("    ");
    for (int j = 0; j < COLS; j++) {
        printf("%d   ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (flipped[i][j]) {
                printf("%c%02d%c", board[i][j] / 10 + '0', board[i][j] % 10, ' ');
            } else {
                printf("??? ");
            }
        }
        printf("|\n");
    }
}

int playTurn() {
    printf("Choose two cards to flip (e.g., 1 2 3 4): ");
    if (scanf("%d %d %d %d", &choice1[0], &choice1[1], &choice2[0], &choice2[1]) != 4) {
        return -1;
    }

    choice1[0]--;
    choice1[1]--;
    choice2[0]--;
    choice2[1]--;

    if (choice1[0] < 0 || choice1[0] >= ROWS || choice1[1] < 0 || choice1[1] >= COLS ||
        choice2[0] < 0 || choice2[0] >= ROWS || choice2[1] < 0 || choice2[1] >= COLS) {
        printf("Invalid coordinates.\n");
        return 0;
    }

    if (flipped[choice1[0]][choice1[1]] || flipped[choice2[0]][choice2[1]]) {
        printf("One or more of those cards have already been flipped.\n");
        return 0;
    }

    flipped[choice1[0]][choice1[1]] = 1;
    flipped[choice2[0]][choice2[1]] = 1;

    if (board[choice1[0]][choice1[1]] == board[choice2[0]][choice2[1]]) {
        printf("You found a pair! Romeo and Juliet can finally be together.\n");
        remainingPairs--;
    } else {
        printf("Sorry, there are no Romeo and Juliet lovers in those two cards.\n");
        flipped[choice1[0]][choice1[1]] = 0;
        flipped[choice2[0]][choice2[1]] = 0;
    }

    return 0;
}

int main() {
    printf("Welcome to the Romeo and Juliet Memory Game!\n");
    initBoard();

    while (remainingPairs) {
        printBoard();
        playTurn();
    }

    printf("Congratulations! You have found all the pairs and Romeo and Juliet are finally united!\n");
    return 0;
}