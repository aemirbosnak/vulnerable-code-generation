//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3  // size of the game board

void print_board(char board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        if(i != SIZE - 1){
            printf("-----------\n");
        }
    }
}

int check_winner(char board[SIZE][SIZE]){
    // check rows
    for(int i = 0; i < SIZE; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'X'){
                return 1;
            }
            else if(board[i][0] == 'O'){
                return 2;
            }
        }
    }

    // check columns
    for(int i = 0; i < SIZE; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == 'X'){
                return 1;
            }
            else if(board[0][i] == 'O'){
                return 2;
            }
        }
    }

    // check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'X'){
            return 1;
        }
        else if(board[0][0] == 'O'){
            return 2;
        }
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'X'){
            return 1;
        }
        else if(board[0][2] == 'O'){
            return 2;
        }
    }
    
    // check if the game is a draw
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] != ' '){
                count++;
            }
        }
    }
    if(count == SIZE*SIZE){
        return 3;
    }

    return 0; // game is still ongoing
}

int main(){
    char board[SIZE][SIZE];
    srand(time(NULL)); // random seed
    int turn = rand() % 2 + 1; // randomly select player 1 or 2 to start

    // initialize the board with empty spaces
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = ' ';
        }
    }

    while(1){
        // print out the board
        printf("Player %d's turn\n", turn);
        print_board(board);

        // get the player's move
        int row, col;
        while(1){
            printf("Enter the row (1-3): ");
            scanf("%d", &row);
            printf("Enter the column (1-3): ");
            scanf("%d", &col);
            if(row < 1 || row > 3 || col < 1 || col > 3){
                printf("Invalid input! Please enter numbers between 1 and 3.\n");
            }
            else if(board[row-1][col-1] != ' '){
                printf("That spot is already taken! Please choose another spot.\n");
            }
            else{
                break;
            }
        }

        // update the board with the player's move
        if(turn == 1){
            board[row-1][col-1] = 'X';
        }
        else{
            board[row-1][col-1] = 'O';
        }

        // check if the game is over and print out the winner or if it's a draw
        int result = check_winner(board);
        if(result == 1){
            print_board(board);
            printf("Player 1 wins!\n");
            break;
        }
        else if(result == 2){
            print_board(board);
            printf("Player 2 wins!\n");
            break;
        }
        else if(result == 3){
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        // switch turns
        if(turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }
    }

    return 0;
}