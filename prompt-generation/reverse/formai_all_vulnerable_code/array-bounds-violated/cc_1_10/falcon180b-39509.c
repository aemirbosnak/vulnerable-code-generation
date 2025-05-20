//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 3

char board[SIZE][SIZE]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard(){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(){
    int i;
    for(i=0;i<SIZE;i++){
        //rows
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return 1;
        }
        //columns
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return 1;
        }
    }
    //diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return 1;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    int player=1;
    int choice;
    while(1){
        system("clear");
        drawBoard();
        printf("\nPlayer %d's turn\n",player);
        printf("Enter your move: ");
        scanf("%d",&choice);
        if(choice<1 || choice>9){
            printf("Invalid move, try again.\n");
            continue;
        }
        int row=choice/3;
        int col=choice%3;
        if(board[row][col]!='X' && board[row][col]!='O'){
            board[row][col]='X';
            player++;
            if(player>2){
                player=1;
            }
        }
        else{
            printf("Invalid move, try again.\n");
        }
        if(checkWin()){
            printf("\nPlayer %d wins!\n",player);
            break;
        }
        if(player==2){
            int move=rand()%9+1;
            row=move/3;
            col=move%3;
            while(board[row][col]!='X' && board[row][col]!='O'){
                move=rand()%9+1;
                row=move/3;
                col=move%3;
            }
            board[row][col]='O';
            player++;
            if(player>2){
                player=1;
            }
        }
    }
    return 0;
}