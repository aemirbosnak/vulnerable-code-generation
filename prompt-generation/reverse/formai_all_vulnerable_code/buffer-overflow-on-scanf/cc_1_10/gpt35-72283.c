//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to print the table
void printTable(int table[]){
    for(int i=0;i<9;i++){
        printf("%d ",table[i]);
        // If we reach the end of a row
        if((i+1)%3==0) printf("\n");
    }
}

// Function to check if a player has won
int checkWin(int table[], int player){
    // Rows
    for(int i=0;i<9;i+=3){
        if(table[i]==player && table[i+1]==player && table[i+2]==player) return 1;
    }
    
    // Columns
    for(int i=0;i<3;i++){
        if(table[i]==player && table[i+3]==player && table[i+6]==player) return 1;
    }
    
    // Diagonals
    if(table[0]==player && table[4]==player && table[8]==player) return 1;
    if(table[2]==player && table[4]==player && table[6]==player) return 1;
    
    return 0;
}

int main(){
    int table[9]={1,2,3,4,5,6,7,8,9}; // The table
    int player=1; // The current player
    int move; // The move selected by the player
    
    printf("Welcome to the C Table Game!\n\n");
    
    printf("Here is the initial table:\n\n");
    printTable(table);
    printf("\n");
    
    while(1){
        // Check if the game is over
        if(checkWin(table,1)){
            printf("Player 1 wins!\n");
            break;
        }
        else if(checkWin(table,2)){
            printf("Player 2 wins!\n");
            break;
        }
        int valid=0;
        while(!valid){
            printf("Player %d, please enter your move (1-9): ",player);
            scanf("%d",&move);
            // Check if the move is valid
            if(move<1 || move>9){
                printf("Invalid move. Please choose a number between 1 and 9.\n");
            }
            else if(table[move-1]=='X' || table[move-1]=='O'){
                printf("That square is already occupied. Please choose another square.\n");
            }
            else{
                valid=1;
            }
        }
        // Make the move
        if(player==1){
            table[move-1]='X';
            player=2;
        }
        else{
            table[move-1]='O';
            player=1;
        }
        // Print the updated table
        printf("\n");
        printTable(table);
        printf("\n");
    }
    
    return 0;
}