//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struct to represent a Chess piece
typedef struct Piece{
    int x; // x-coordinate
    int y; // y-coordinate
    char type; // K for King, Q for Queen, B for Bishop, R for Rook, N for Knight
} Piece;

// Array of all chess pieces
Piece pieces[8] = {
    {6, 0, 'K'}, {7, 0, 'Q'}, {6, 1, 'B'}, {7, 1, 'R'},
    {5, 2, 'N'}, {6, 2, 'N'}, {7, 2, 'N'}, {5, 3, 'N'}
};

// Function to check if a move is valid
bool isMoveValid(Piece piece, int dx, int dy) {
    if(piece.type == 'K'){ // King
        if(dx == 1 && dy == 1) return true; // Castling
        else if(dx == 1 && dy == 0) return true; // Castling
        else if(dx == 0 && dy == 1) return true; // Castling
        else if(dx == 0 && dy == 0) return true; // Castle
        else return false;
    }
    else if(piece.type == 'Q' || piece.type == 'R' || piece.type == 'B' || piece.type == 'N'){ // Queen, Rook, Bishop, Knight
        if(dx == 0 && dy == 0) return true; // Normal move
        else return false;
    }
    else return false;
}

// Function to print the current state of the board
void printBoard() {
    printf("K Q B R N N N N\n");
    printf("K Q B R N N N N\n");
    printf("K Q B R N N N N\n");
}

int main() {
    printBoard();
    printf("\nEnter a move (e.g., K6 K7): ");
    char move[10];
    fgets(move, 10, stdin);
    int dx, dy;
    sscanf(move, "%d %d", &dx, &dy);
    int x = dx, y = dy;
    while(x >= 0 && x <= 7 && y >= 0 && y <= 7){
        Piece piece = pieces[x];
        if(isMoveValid(piece, dx, dy)){
            printf("Move accepted.\n");
            pieces[x].x = dx;
            pieces[x].y = dy;
            printBoard();
        }
        else{
            printf("Move rejected.\n");
        }
        printf("Enter a move (e.g., K6 K7): ");
        fgets(move, 10, stdin);
        sscanf(move, "%d %d", &dx, &dy);
        x = dx;
        y = dy;
    }
    printf("Game over.\n");
    return 0;
}