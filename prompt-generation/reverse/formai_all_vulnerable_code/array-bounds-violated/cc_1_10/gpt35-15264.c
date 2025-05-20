//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[6][6]){
    printf("  1 2 3 4 5 6\n");
    for(int i=0; i<6; i++){
        printf("%d ",i+1);
        for(int j=0; j<6; j++){
            if(board[i][j] == 0){
                printf("□ ");
            }else{
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("----------------\n");
}

int checkWin(int board[6][6], int player){
    int count=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(board[i][j] == player){
                count++;
            }
        }
    }
    if(count > 18){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int board[6][6] = {0};
    srand(time(0));
    int playerNum = rand()%2 + 1;
    printf("Player %d goes first\n", playerNum);
    printBoard(board);
    
    while(1){
        printf("Player %d, enter coordinates to place piece (row column): ", playerNum);
        int row, col, valid=0;
        while(valid == 0){
            scanf("%d %d", &row, &col);
            if(board[row-1][col-1] == 0){
                valid = 1;
            }else{
                printf("There is already a piece there, please choose another location: ");
            }
        }
        board[row-1][col-1] = playerNum;
        printBoard(board);
        if(checkWin(board, playerNum)){
            printf("Player %d wins!", playerNum);
            break;
        }
        if(playerNum == 1){
            playerNum = 2;
        }else{
            playerNum = 1;
        }
    }
    return 0;
}