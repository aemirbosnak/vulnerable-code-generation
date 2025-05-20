//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("* ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        if(board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            return 1;
        }
    }
    for(j=0; j<COLS; j++) {
        if(board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 1) {
            return 1;
        }
    }
    if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    if(board[0][4] == 1 && board[1][3] == 1 && board[2][2] == 1) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS] = {{0}};
    int player = 1;
    int choice;
    int win = 0;

    while(win == 0) {
        print_board(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice (1-%d): ", ROWS*COLS-1);
        scanf("%d", &choice);
        if(choice >= 1 && choice <= ROWS*COLS-1 && board[choice/COLS][choice%COLS] == 0) {
            board[choice/COLS][choice%COLS] = player;
            win = check_win(board);
            if(win == 0) {
                player =!player;
            }
        } else {
            printf("Invalid choice\n");
        }
    }

    if(player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}