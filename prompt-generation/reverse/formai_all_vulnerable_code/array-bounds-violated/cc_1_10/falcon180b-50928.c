//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int checkForMatch(int board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                if(i > 0 && board[i-1][j] == 1) {
                    return 1;
                } else if(j > 0 && board[i][j-1] == 1) {
                    return 1;
                } else if(i < ROWS-1 && board[i+1][j] == 1) {
                    return 1;
                } else if(j < COLS-1 && board[i][j+1] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    int player = 1;
    int moves = 0;
    while(1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &i, &j);
        if(board[i-1][j-1] == 0) {
            board[i-1][j-1] = player;
            moves++;
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
        if(checkForMatch(board)) {
            printf("Player %d wins!\n", player);
            break;
        } else if(moves == 8) {
            printf("It's a tie.\n");
            break;
        }
    }
    return 0;
}