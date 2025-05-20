//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

// function to initialize the game board with random numbers from 1 to 8
void init_board(int board[][COL]){
    srand(time(NULL));  // seeding the random number generator
    int count = 0;
    while(count < 8){
        int rand_row = rand() % ROW;
        int rand_col = rand() % COL;
        if(board[rand_row][rand_col] == 0){
            board[rand_row][rand_col] = ++count;
            board[ROW - rand_row - 1][COL - rand_col - 1] = count; // setting the corresponding pair value
        }
    }
}

// function to print the current state of the game board
void print_board(int board[][COL]){
    printf("\n");
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(board[i][j] == 0){
                printf("  ");
            }else{
                printf("%d ",board[i][j]);
            }
        }
        printf("\n");
    }
}

// function to check if all the board elements have been "discovered"
int is_game_won(int board[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(board[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

// function to check if the selected cells for guessing are valid
int is_valid(int row1,int col1,int row2,int col2){
    if(row1 < 0 || row1 >= ROW || row2 < 0 || row2 >= ROW || col1 < 0 || col1 >= COL || col2 < 0 || col2 >= COL){
        return 0;
    }
    if(row1 == row2 && col1 == col2){
        return 0;
    }
    return 1;
}

// function to update the game board based on the selected cells
void update_board(int board[][COL],int row1,int col1,int row2,int col2){
    int temp = board[row1][col1];
    board[row1][col1] = 0;
    board[row2][col2] = 0;
    printf("\nMatched %d and %d!\n",temp,board[row2][col2]);
}

int main(){
    int game_board[ROW][COL] = {0};  // clear the game board
    init_board(game_board);  // initialize the game board
    printf("Welcome to the Memory Game!\n");
    while(!is_game_won(game_board)){
        print_board(game_board);  // print the current state of the board
        int row1,col1,row2,col2;
        printf("\nEnter the row and column numbers of the first cell to guess: ");
        scanf("%d%d",&row1,&col1);
        printf("Enter the row and column numbers of the second cell to guess: ");
        scanf("%d%d",&row2,&col2);
        if(!is_valid(row1,col1,row2,col2)){  // check if the selected cells are valid
            printf("\nInvalid input! Please enter valid row and column numbers.\n");
            continue;
        }
        if(game_board[row1][col1] == game_board[row2][col2]){  // update the game board if the selected cells match
            update_board(game_board,row1,col1,row2,col2);
        }else{
            printf("\nSorry, the selected cells do not match!\n");
        }
    }
    printf("Congratulations! You won the Memory Game!\n");
    return 0;
}