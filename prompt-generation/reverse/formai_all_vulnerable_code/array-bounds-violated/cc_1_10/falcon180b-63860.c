//Falcon-180B DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 7

void printBoard(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initBoard(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = '-';
        }
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    int choice;
    while(1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &choice, &choice);
        if(player == 1) {
            board[choice][0] = 'X';
            player = 2;
        }
        else {
            board[0][choice] = 'O';
            player = 1;
        }
        int flag = 0;
        for(int i=0; i<ROWS; i++) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= '-') {
                flag = 1;
                break;
            }
        }
        for(int i=0; i<COLS; i++) {
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= '-') {
                flag = 1;
                break;
            }
        }
        if(flag) {
            printf("\nGame Over! Player %d wins!\n", player);
            break;
        }
        if(player == 2 && choice == 4) {
            printf("\nGame Over! Player %d wins!\n", player);
            break;
        }
        if(player == 1 && choice == 6) {
            printf("\nGame Over! Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}