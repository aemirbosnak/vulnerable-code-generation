//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to display the board
void display_board(char board[][3]){
    int i, j;
    printf("\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf(" %c |",board[i][j]);
        }
        printf("\n");
        if(i<2)
            printf("-----------\n");
    }
}

//function to check if any player has won
int check_win(char board[][3], char symbol){
    //checking rows
    int i;
    for(i=0; i<3; i++){
        if(board[i][0]==symbol && board[i][1]==symbol && board[i][2]==symbol){
            return 1;
        }
    }
    //checking columns
    int j;
    for(j=0; j<3; j++){
        if(board[0][j]==symbol && board[1][j]==symbol && board[2][j]==symbol){
            return 1;
        }
    }
    //checking diagonals
    if(board[0][0]==symbol && board[1][1]==symbol && board[2][2]==symbol){
        return 1;
    }
    else if(board[0][2]==symbol && board[1][1]==symbol && board[2][0]==symbol){
        return 1;
    }
    else{
        return 0;
    }
}

//function to check if the board is full
int is_full(char board[][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 1;
}

//function to get user input and update board
void get_user_input(char board[][3], char symbol){
    int row, col;
    printf("\n\nEnter row and column (1-3) separated by space\n\n");

    //getting user input
    int valid_input = 0;
    while(!valid_input){
        scanf("%d %d",&row,&col);
        if(row>=1 && row<=3 && col>=1 && col<=3 && board[row-1][col-1]==' '){
            board[row-1][col-1] = symbol;
            valid_input = 1;
        }
        else{
            printf("\nInvalid input. Try again\n");
        }
    }
}

//function to get computer input and update board
void get_computer_input(char board[][3], char symbol){
    printf("\n\nComputer's turn\n\n");

    //generating computer input
    int valid_input = 0, row, col;
    while(!valid_input){
        row = rand() % 3;
        col = rand() % 3;
        if(board[row][col]==' '){
            board[row][col] = symbol;
            valid_input = 1;
        }
    }
}

int main(){
    printf("\n\n*****Welcome to the game of Tic Tac Toe*****\n\n");

    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    //choosing symbol for player
    char player_symbol, computer_symbol;
    printf("\nChoose your symbol (X/O)\n\n");
    int valid_input = 0;
    while(!valid_input){
        scanf("%c",&player_symbol);
        if(player_symbol=='X'||player_symbol=='O'){
            valid_input = 1;
            if(player_symbol=='X'){
                computer_symbol = 'O';
            }
            else{
                computer_symbol = 'X';
            }
        }
        else{
            printf("\nInvalid input. Try again\n");
        }
    }

    int player_turn = 1;
    while(!is_full(board)){
        printf("\n");
        if(player_turn){
            printf("Player's turn\n");
            display_board(board);
            get_user_input(board, player_symbol);
            if(check_win(board, player_symbol)){
                printf("\n\n*******Player wins!!********\n\n");
                display_board(board);
                return 0;
            }
        }
        else{
            get_computer_input(board, computer_symbol);
            if(check_win(board, computer_symbol)){
                printf("\n\n*******Computer wins!!********\n\n");
                display_board(board);
                return 0;
            }
        }
        player_turn = !player_turn;
    }

    printf("\n\n*******It's a tie!!********\n\n");
    display_board(board);
    return 0;
}