//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
char player = 'X';
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
    int i, j;
    srand(time(0));
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = rand()%2;
        }
    }
    drawBoard();
    while(1) {
        system("clear");
        drawBoard();
        printf("\nPlayer %c's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid choice. Computer's turn.\n");
            flag = 1;
            break;
        }
        if(board[choice/3][choice%3]!= 0) {
            printf("Invalid choice. Computer's turn.\n");
            flag = 1;
            break;
        }
        board[choice/3][choice%3] = player;
        if(checkWin()) {
            printf("\n%c wins!\n", player);
            break;
        }
        if(flag) {
            int k;
            do {
                k = rand()%9;
            } while(board[k/3][k%3]!= 0);
            board[k/3][k%3] = (player == 'X')? 'O' : 'X';
            flag = 0;
        }
        player = (player == 'X')? 'O' : 'X';
    }
    return 0;
}