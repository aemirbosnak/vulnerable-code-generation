//FormAI DATASET v1.0 Category: Table Game ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to display the Table
void displayTable(int table[3][3]){
    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++){
            printf("%d\t",table[i][j]);
        }
    }
    printf("\n");
}

//Function to check if any of the player won 
int checkWin(int table[3][3],int player){
    //Vertical
    for(int j=0;j<3;j++){
        if(table[0][j]==player && table[1][j]==player && table[2][j]==player){
            return 1;
        }
    }
    //Horizontal
    for(int i=0;i<3;i++){
        if(table[i][0]==player && table[i][1]==player && table[i][2]==player){
            return 1;
        }
    }
    //Diagonal
    if(table[0][0]==player && table[1][1]==player && table[2][2]==player){
        return 1;
    }
    if(table[0][2]==player && table[1][1]==player && table[2][0]==player){
        return 1;
    }
    return 0;
}

int main(){
    //Creating Table and Initializing to zero
    int table[3][3]={0};
    int turn=1;
    int row,col;
    while(1){
        printf("Table:\n");
        //Displaying Table
        displayTable(table);
        
        //Getting the row and col from the player
        printf("Player %d, enter the row(1-3) and col(1-3) to enter the value(1 or 2): ",turn);
        scanf("%d %d",&row,&col);
        //Checking if the player is making a valid move
        if(row>3 || col>3 || row<1 || col<1){
            printf("Invalid Selection.\n");
            continue;
        }
        if(table[row-1][col-1]!=0){
            printf("Already used.\n");
            continue;
        }
        
        //Getting the player value
        int playerVal;
        if(turn==1){
            playerVal=1;
        }
        else{
            playerVal=2;
        }
        
        table[row-1][col-1]=playerVal;
        //Checking if any of the players won
        if(checkWin(table,playerVal)==1){
            displayTable(table);
            printf("Player %d Won!\n",turn);
            break;
        }
        //Checking if there are any empty cells in the table
        int flag=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(table[i][j]==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        //If no empty cells means it is a draw
        if(flag==0){
            displayTable(table);
            printf("Draw!\n");
            break;
        }
        //Next Turn
        if(turn==1){
            turn=2;
        }
        else{
            turn=1;
        }
    }
    return 0;
}