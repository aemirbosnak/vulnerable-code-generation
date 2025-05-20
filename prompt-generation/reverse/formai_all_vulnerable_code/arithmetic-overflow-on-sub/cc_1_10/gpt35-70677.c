//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>

// Checkerboard array
char checkers[8][8] = {
    {' ', '*', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', '*', ' ', '*', ' ', '*'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' '}
};

// Function to print the checkerboard
void printCheckers() {
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            printf("%c ", checkers[row][col]);
        }
        printf("\n");
    }
}

// Function to move a checker piece
void moveCheckers(int fromRow, int fromCol, int toRow, int toCol) {
    if(checkers[toRow][toCol] != ' ') {
        printf("Invalid move!\n");
        return;
    }
    
    if(fromRow == toRow && fromCol == toCol) {
        printf("Invalid move!\n");
        return;
    }
    
    if(fromRow == toRow+1 || fromRow == toRow-1) {
        if(fromCol == toCol+1 || fromCol == toCol-1) {
            checkers[toRow][toCol] = checkers[fromRow][fromCol];
            checkers[fromRow][fromCol] = ' ';
            return;
        }
    }
    
    printf("Invalid move!\n");
}

int main() {
    int fromRow, fromCol, toRow, toCol;
    
    printf("Welcome to the Checkers Game!\n");
    printf("Type in the row and column of the checkerpiece you want to move, then the row and column of the square you want to move it to.\n");
    
    while(1) {
        printCheckers();
        printf("\nEnter the row and column of the checkerpiece, separated by a space: ");
        scanf("%d %d", &fromRow, &fromCol);
        
        printf("Enter the row and column of the destination square, separated by a space: ");
        scanf("%d %d", &toRow, &toCol);
        
        moveCheckers(fromRow, fromCol, toRow, toCol);
    }
    
    return 0;
}