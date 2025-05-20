//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main() {
    int board[10][10];
    
    //initialize the board
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            board[i][j] = 0;
        }
    }
    
    //initialize the first row
    for(int i=0;i<10;i++) {
        board[0][i] = 1;
    }
    
    //initialize the last row
    for(int i=0;i<10;i++) {
        board[9][i] = 1;
    }
    
    //initialize the first column
    for(int i=0;i<10;i++) {
        board[i][0] = 1;
    }
    
    //initialize the last column
    for(int i=0;i<10;i++) {
        board[i][9] = 1;
    }
    
    //initialize the center
    board[4][4] = 1;
    
    int x,y;
    int count = 0;
    
    //print the board
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(board[i][j] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    while(count < 10) {
        //get user input
        printf("Enter x: ");
        scanf("%d",&x);
        printf("Enter y: ");
        scanf("%d",&y);
        
        //check if the position is valid
        if(x >= 0 && x < 10 && y >= 0 && y < 10) {
            board[x][y] = 1;
        }
        else {
            printf("Invalid position!\n");
        }
        
        //print the board
        count++;
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                if(board[i][j] == 1) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}