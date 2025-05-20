//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
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

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int matches = 0;
    while (matches < 8) {
        int x, y;
        do {
            x = rand() % ROWS;
            y = rand() % COLS;
        } while (board[x][y]!= '-');
        board[x][y] = rand() % 3 + 1;
        printBoard(board);
        int choice;
        printf("Enter your choice (row [0-3] and column [0-3]): ");
        scanf("%d %d", &choice, &choice);
        if (choice >= 0 && choice < ROWS && choice >= 0 && choice < COLS) {
            if (board[choice][choice] == 1 || board[choice][choice] == 2) {
                matches++;
                printf("Match!\n");
            } else {
                printf("Miss.\n");
            }
            board[choice][choice] = '-';
        } else {
            printf("Invalid choice.\n");
        }
    }
    printf("Congratulations! You have completed the game with %d matches.\n", matches);
    return 0;
}