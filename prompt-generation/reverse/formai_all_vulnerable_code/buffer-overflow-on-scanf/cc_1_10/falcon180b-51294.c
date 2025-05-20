//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkMatch(char board[ROWS][COLS], int choice1, int choice2) {
    if (board[choice1][0] == board[choice2][0] && board[choice1][0]!= '*') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int playerScore = 0;
    int cpuScore = 0;

    while (1) {
        printBoard(board);
        int choice;
        scanf("%d", &choice);
        if (choice < 0 || choice > 15) {
            printf("Invalid choice.\n");
            continue;
        }

        char symbol;
        if (playerScore % 2 == 0) {
            symbol = 'X';
            playerScore++;
        } else {
            symbol = 'O';
            cpuScore++;
        }

        board[choice / COLS][choice % COLS] = symbol;

        if (checkMatch(board, choice, (choice + 1) % 16)) {
            printf("Match found!\n");
            continue;
        } else if (checkMatch(board, choice, (choice - 1 + 16) % 16)) {
            printf("Match found!\n");
            continue;
        }

        if (playerScore == 16 || cpuScore == 16) {
            printf("Game over!\n");
            break;
        }

        int cpuChoice = rand() % 16;
        while (board[cpuChoice / COLS][cpuChoice % COLS]!= '*') {
            cpuChoice = rand() % 16;
        }
        board[cpuChoice / COLS][cpuChoice % COLS] = 'O';
    }

    return 0;
}