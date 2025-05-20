//FormAI DATASET v1.0 Category: Chess engine ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// defining the Chess board
char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// defining the Chess board print function
void printBoard(){
    // iterate through each row of the board
    for(int i=0; i<8; i++){
        // iterate through each element of the row
        for(int j=0; j<8; j++){
            // print the element of the board
            printf("%c ", board[i][j]);
        }
        // move to the next line
        printf("\n");
    }
}

// defining the Chess engine
void playChess(){
    // print the current state of the board
    printBoard();

    // ask for user input
    printf("Enter the piece you want to move: ");
    char fromPiece;
    scanf("%c", &fromPiece);

    // ask for user input
    printf("Enter the position to move it to: ");
    char toPosition;
    scanf("%c", &toPosition);

    // move the piece
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j] == fromPiece){
                board[i][j] = ' ';
                board[i][j] = toPosition;
            }
        }
    }

    // print the new state of the board
    printBoard();
}

// defining the main function
int main(){
    // print a welcome message
    printf("Welcome to the exciting world of Chess!\n");
    // start the game
    playChess();
    // end the game
    return 0;
}