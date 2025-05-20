//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 3
#define NUM_COLS 3

/*
    Function to display the game board
*/
void display_board(char board[NUM_ROWS][NUM_COLS]){
    printf("\n\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\t     |     |     \n\n");
}

/*
    Function to determine if there is a winner
*/
char check_winner(char board[NUM_ROWS][NUM_COLS]){
    int i;

    // Check rows
    for(i=0;i<NUM_ROWS;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
    }

    // Check columns
    for(i=0;i<NUM_COLS;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return board[0][i];
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }

    return ' ';
}

/*
    Function for the computer's move
*/
void computer_move(char board[NUM_ROWS][NUM_COLS]){
    int row, col;

    srand(time(NULL));
    do{
        row = rand() % NUM_ROWS;
        col = rand() % NUM_COLS;
    }while(board[row][col] != ' ');

    board[row][col] = 'O';
}

/*
    Function to get the player's move
*/
void player_move(char board[NUM_ROWS][NUM_COLS]){
    int row, col;

    do{
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter col (1-3): ");
        scanf("%d", &col);
        row--;
        col--;
    }while(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

    board[row][col] = 'X';
}

/*
    Main function to start the game
*/
int main(){
    char board[NUM_ROWS][NUM_COLS] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char winner = ' ';
    int player_turn = 1;

    printf("Welcome to the Tic Tac Toe game!\n\n");
    printf("Player: X, Computer: O\n\n");

    // Game loop
    while(winner == ' '){
        display_board(board);

        if(player_turn){
            player_move(board);
        }
        else{
            computer_move(board);
        }

        player_turn = !player_turn;
        winner = check_winner(board);
    }

    display_board(board);

    // Print winner
    if(winner == 'X'){
        printf("Congratulations! You won!\n");
    }
    else if(winner == 'O'){
        printf("Sorry, you lost. Better luck next time!\n");
    }
    else{
        printf("It's a tie!\n");
    }

    return 0;
}