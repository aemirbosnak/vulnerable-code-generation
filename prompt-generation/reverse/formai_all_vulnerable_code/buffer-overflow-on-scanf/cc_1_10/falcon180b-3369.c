//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generateBoard(int board[][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            board[i][j] = rand()%(MAX_VALUE-MIN_VALUE+1) + MIN_VALUE;
        }
    }
}

int checkWin(int board[][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            return 1;
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
            return 1;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        return 1;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        return 1;
    }
    return 0;
}

void printBoard(int board[][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE];
    generateBoard(board);
    printBoard(board);
    int player=1;
    while(1) {
        int choice;
        printf("Player %d's turn\n",player);
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice<1 || choice>SIZE*SIZE) {
            printf("Invalid choice\n");
            continue;
        }
        if(board[choice/SIZE][choice%SIZE]!=0) {
            printf("This position is already occupied\n");
            continue;
        }
        board[choice/SIZE][choice%SIZE] = player;
        if(checkWin(board)) {
            printf("Player %d wins!\n",player);
            break;
        }
        player++;
        if(player>2) {
            player=1;
        }
    }
    return 0;
}