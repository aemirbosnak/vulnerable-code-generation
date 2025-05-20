//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void displayBoard(int board[][3]);
int checkWin(int board[][3]);

int main(){
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int player = 1;
    int winner = 0;
    int row, col;
    
    while(winner == 0){
        displayBoard(board);
        
        printf("Player %d, enter a row (0-2): ", player);
        scanf("%d", &row);
        printf("Player %d, enter a column (0-2): ", player);
        scanf("%d", &col);
        
        if(board[row][col] != 0){
            printf("Invalid move. That spot is already taken.\n");
        }
        else{
            board[row][col] = player;
            
            winner = checkWin(board);
            if(winner == 0){
                if(player == 1){
                    player = 2;
                }
                else{
                    player = 1;
                }
            }
        }
    }
    
    displayBoard(board);
    printf("Player %d wins!\n", winner);
    
    return 0;
}

void displayBoard(int board[][3]){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[][3]){
    int i, j;
    int rowSum, colSum, diagSum1, diagSum2;
    
    // check rows
    for(i=0;i<3;i++){
        rowSum = 0;
        for(j=0;j<3;j++){
            rowSum += board[i][j];
        }
        if(rowSum == 3){
            return 1;
        }
        else if(rowSum == 6){
            return 2;
        }
    }
    
    //check columns
    for(j=0;j<3;j++){
        colSum = 0;
        for(i=0;i<3;i++){
            colSum += board[i][j];
        }
        if(colSum == 3){
            return 1;
        }
        else if(colSum == 6){
            return 2;
        }
    }
    
    //check diagonals
    diagSum1 = board[0][0] + board[1][1] + board[2][2];
    diagSum2 = board[2][0] + board[1][1] + board[0][2];
    if(diagSum1 == 3 || diagSum2 == 3){
        return 1;
    }
    else if(diagSum1 == 6 || diagSum2 == 6){
        return 2;
    }
    
    return 0;
}