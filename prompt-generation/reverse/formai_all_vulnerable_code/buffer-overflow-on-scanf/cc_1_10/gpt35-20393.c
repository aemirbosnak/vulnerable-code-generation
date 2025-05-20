//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; //the tictactoe board
int moveCount=0; //the number of moves made so far

/* function to initialize the board with spaces */
void initBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}

/* function to display the board */
void displayBoard(){
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ",board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("-----------\n");
    }
    printf("\n");
}

/* function to get user's move */
void getUserMove(){
    int row,col;
    while(1){
        printf("Enter your move (row column): ");
        scanf("%d %d",&row,&col);
        if(row>=1 && row<=3 && col>=1 && col<=3 && board[row-1][col-1]==' '){
            board[row-1][col-1]='X';
            moveCount++;
            break;
        }
        printf("Invalid move. Try again.\n");
    }
}

/* function to check if the board is full */
int isBoardFull(){
    return moveCount==9;
}

/* function to check if there is a winner */
char checkWinner(){
    //check rows
    for(int i=0;i<3;i++){
        if(board[i][0]!=' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int j=0;j<3;j++){
        if(board[0][j]!=' ' && board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            return board[0][j];
        }
    }
    //check diagonals
    if(board[1][1]!=' '){
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return board[1][1];
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return board[1][1];
        }
    }
    //no winner
    return ' ';
}

/* function to get computer's move */
void getComputerMove(){
    int row,col;
    while(1){
        /* generate random row and column values */
        row=rand()%3;
        col=rand()%3;
        if(board[row][col]==' '){ //if the cell is empty
            board[row][col]='O';
            moveCount++;
            break;
        }
    }
}

int main(){
    char winner;
    int turn; //0 for user, 1 for computer
    srand(time(NULL)); //seed the random generator with current time

    initBoard(); //initialize the board to empty

    /* randomize the starting player */
    turn=rand()%2;

    while(1){
        displayBoard(); //display the board
        if(turn==0){
            getUserMove(); //user's turn
        }
        else{
            getComputerMove(); //computer's turn
        }
        winner=checkWinner(); //check for a winner
        if(winner!=' '){ //if there is a winner
            displayBoard(); //display final board
            printf("%c wins!\n",winner);
            break;
        }
        if(isBoardFull()){ //if the board is full
            displayBoard(); //display final board
            printf("It's a tie!\n");
            break;
        }
        turn=1-turn; //change turn
    }

    return 0;
}