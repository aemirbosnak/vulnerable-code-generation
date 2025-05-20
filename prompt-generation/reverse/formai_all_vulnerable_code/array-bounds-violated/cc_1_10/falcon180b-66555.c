//Falcon-180B DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;

    do {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        int validMove = 0;
        while(!validMove) {
            printf("Enter your move (row and column): ");
            scanf("%d %d", &choice, &choice);
            if(choice >= 1 && choice <= 9 && board[choice-1][board[choice-1][0] == 0? 1 : 0] == 0) {
                board[choice-1][board[choice-1][0] == 0? 1 : 0] = player;
                validMove = 1;
            } else {
                printf("Invalid move, try again.\n");
            }
        }

        if(checkWin(board, player)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        } else {
            player =!player;
        }

    } while(1);

    return 0;
}

int checkWin(int board[ROWS][COLS], int player) {
    int i, j;

    // Check rows
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for(j = 0; j < COLS; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}