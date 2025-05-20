//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int player = 1;
int choice;
int flag = 0;

void drawBoard() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    int i, j;
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(0));
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = rand() % 2;
        }
    }
    drawBoard();
    while(1) {
        system("clear");
        drawBoard();
        printf("\nPlayer %d's Turn\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        if(board[choice/3][choice%3]!= 0) {
            printf("Sorry, that spot is already taken. Try again.\n");
            continue;
        }
        board[choice/3][choice%3] = player;
        drawBoard();
        if(checkWin()) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}