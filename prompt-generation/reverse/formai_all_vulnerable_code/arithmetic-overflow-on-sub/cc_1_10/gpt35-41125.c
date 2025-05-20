//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Struct for storing board status and player information
struct TicTacToe {
    char board[3][3];
    int player;
    int ai;
};

//Function to print the current board status
void displayBoard(struct TicTacToe t) {
    printf("\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%c ",t.board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the game is over
int gameOver(struct TicTacToe t) {
    //Checking all rows for winner
    for(int i=0;i<3;i++) {
        if(t.board[i][0]==t.board[i][1] && t.board[i][0]==t.board[i][2] && t.board[i][0]!=' ') {
            return 1;
        }
    }
    //Checking all columns for winner
    for(int i=0;i<3;i++) {
        if(t.board[0][i]==t.board[1][i] && t.board[0][i]==t.board[2][i] && t.board[0][i]!=' ') {
            return 1;
        }
    }
    //Checking both diagonals for winner
    if(t.board[0][0]==t.board[1][1] && t.board[0][0]==t.board[2][2] && t.board[0][0]!=' ') {
        return 1;
    }
    if(t.board[0][2]==t.board[1][1] && t.board[0][2]==t.board[2][0] && t.board[0][2]!=' ') {
        return 1;
    }
    //Checking for tie
    int x=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(t.board[i][j]==' ') {
                x=1;
                break;
            }
        }
        if(x) {
            break;
        }
    }
    if(x) {
        return 0;
    }
    else {
        return 2;
    }
}

//Function to get user input for move
void getUserMove(struct TicTacToe *t) {
    int r,c;
    printf("Enter row and column for move (1-3): ");
    scanf("%d %d",&r,&c);
    while(t->board[r-1][c-1]!=' ') {
        printf("Invalid Move, Enter row and column for move (1-3): ");
        scanf("%d %d",&r,&c);
    }
    t->board[r-1][c-1]=(t->player==1)?('X'):('O');
    displayBoard(*t);
}

//Function to get AI move
void getAIMove(struct TicTacToe *t) {
    int r,c;
    do {
        r=rand()%3;
        c=rand()%3;
    }while(t->board[r][c]!=' ');
    printf("\nAI move: (%d,%d)\n",r+1,c+1);
    t->board[r][c]=(t->ai==1)?('X'):('O');
    displayBoard(*t);
}

//Function to get player and AI selection
void getSelections(struct TicTacToe *t) {
    printf("Select your symbol (X or O): ");
    char ch;
    scanf(" %c",&ch);
    while(ch!='X' && ch!='O') {
        printf("Invalid Symbol Selected, Select your symbol (X or O): ");
        scanf(" %c",&ch);
    }
    t->player=(ch=='X')?(1):(2);
    t->ai=(ch=='X')?(2):(1);
}

//Main function
int main() {
    srand(time(NULL)); //Seeding random for AI
    struct TicTacToe t;
    //Initializing board to empty spaces
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            t.board[i][j]=' ';
        }
    }
    displayBoard(t);
    getSelections(&t);
    //Game loop
    while(1) {
        getUserMove(&t);
        if(gameOver(t)) {
            break;
        }
        getAIMove(&t);
        if(gameOver(t)) {
            break;
        }
    }
    int status=gameOver(t);
    if(status==1) {
        printf("\nPlayer %d wins!\n",t.player);
    }
    else if(status==2) {
        printf("\nTie game!\n");
    }
    else {
        printf("\nAI wins!\n");
    }
    return 0;
}