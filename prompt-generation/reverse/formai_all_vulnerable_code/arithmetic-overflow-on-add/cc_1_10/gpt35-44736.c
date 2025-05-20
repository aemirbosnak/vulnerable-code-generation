//FormAI DATASET v1.0 Category: Chess engine ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

// array representing the chessboard
char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

// function to print the chessboard
void printBoard(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isLegalMove(int currX, int currY, int destX, int destY){
    // check if destination is out of bounds
    if(destX < 0 || destX > 7 || destY < 0 || destY > 7){
        printf("Destination out of bounds!\n");
        return false;
    }
    
    // check if destination is the same as current position
    if(currX == destX && currY == destY){
        printf("Destination is the same as current position!\n");
        return false;
    }
    
    // check if there is a piece in the current position
    if(board[currX][currY] == ' '){
        printf("No piece in the current position!\n");
        return false;
    }
    
    // check if the destination is occupied by the player's own piece
    if(board[destX][destY] != ' ' && board[currX][currY] == board[destX][destY]){
        printf("Destination occupied by player's own piece!\n");
        return false;
    }
    
    // check if the selected piece can move to the destination
    // in this example, only the pawn can move and capture
    if(board[currX][currY] == 'P'){
        // check if there is no piece in front of the pawn
        if(currX == destX && board[destX][destY] == ' '){
            if(destY == currY || (destY == currY+1 && board[currX+1][currY+1] != ' ') || (destY == currY-1 && board[currX+1][currY-1] != ' ')){
                return true;
            }
        }
        // check if the pawn can capture a piece
        else if(destX == currX+1 && (destY == currY+1 || destY == currY-1) && board[destX][destY] != ' '){
            return true;
        }
    }
    
    printf("Invalid move!\n");
    return false;
}

int main(){
    int currX, currY, destX, destY;
    
    while(true){
        printf("Enter current position (row, column): ");
        scanf("%d%d", &currX, &currY);
        printf("Enter destination position (row, column): ");
        scanf("%d%d", &destX, &destY);
        
        if(isLegalMove(currX, currY, destX, destY)){
            board[destX][destY] = board[currX][currY];
            board[currX][currY] = ' ';
            printf("Move was successful!\n");
        }
        
        printBoard();
    }
    
    return 0;
}