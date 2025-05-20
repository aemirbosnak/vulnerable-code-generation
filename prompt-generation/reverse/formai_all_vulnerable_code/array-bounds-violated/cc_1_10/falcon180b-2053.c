//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(int board[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == 1) {
                printf("X ");
            } else if(board[i][j] == 2) {
                printf("O ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int checkWin(int board[3][3]) {
    int i;
    // Check rows
    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for(i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    int board[3][3];
    int player = 1;
    int choice;
    int win = 0;

    srand(time(0));

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X, Player 2: O\n");

    while(win == 0) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid choice, try again.\n");
            continue;
        }
        if(board[choice/3][choice%3]!= 0) {
            printf("Spot already taken, try again.\n");
            continue;
        }
        board[choice/3][choice%3] = player;
        win = checkWin(board);
        if(win == 1) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }

    return 0;
}