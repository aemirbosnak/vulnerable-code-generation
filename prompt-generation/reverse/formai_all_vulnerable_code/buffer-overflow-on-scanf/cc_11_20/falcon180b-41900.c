//Falcon-180B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_SYMBOLS 2

int main() {
    char board[ROWS][COLS];
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(0));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }

    while (flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Please enter your choice:\n1. X\n2. O\n");
        scanf("%d", &choice);

        if (choice == 1 && player == 1) {
            flag = 1;
            player = 2;
        } else if (choice == 2 && player == 2) {
            flag = 1;
            player = 1;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    int count = 0;
    while (count < 9) {
        int row, col;
        row = rand() % ROWS;
        col = rand() % COLS;

        if (board[row][col] == '-') {
            board[row][col] = (player == 1)? 'X' : 'O';
            count++;
        }
    }

    system("clear");
    printf("Tic Tac Toe\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}