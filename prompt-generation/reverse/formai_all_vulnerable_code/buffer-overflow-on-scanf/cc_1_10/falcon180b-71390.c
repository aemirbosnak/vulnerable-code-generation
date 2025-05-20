//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define BOARD_SIZE (ROWS * COLS)

int board[BOARD_SIZE];
int player = 1;
int choice;
int flag = 0;

void drawBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i * COLS + j] == 1)
                printf("X ");
            else if (board[i * COLS + j] == 2)
                printf("O ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int checkWin() {
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == 0)
            return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = 0;
    }
    while (flag == 0) {
        drawBoard();
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > BOARD_SIZE) {
            printf("Invalid choice\n");
            continue;
        }
        if (board[choice - 1]!= 0) {
            printf("Cell already occupied\n");
            continue;
        }
        board[choice - 1] = player;
        if (checkWin()) {
            printf("\nPlayer %d wins!\n", player);
            flag = 1;
        } else if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    return 0;
}