//FormAI DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to display the game board
void display_board(char board[][3]){
    printf("\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("\t%c", board[i][j]);
        }
        printf("\n");
    }
}

//Function to check if there is a winner
int check_winner(char board[][3], char player){
    for (int i=0; i<3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

//Main function to run the game
int main(){
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1, choice, row, col;
    char mark;

    srand(time(0)); //To generate random number
    int systemchoice = rand()%9 + 1; //Random number generation for system

    while (1){
        display_board(board);

        //Player turn
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);
        row = (choice-1) / 3;
        col = (choice-1) % 3;
        mark = (player == 1)? 'X': 'O';

        if (board[row][col] == mark){
            board[row][col] = mark;
        }
        else{
            printf("Invalid move. Try again.\n");
            continue;
        }

        //Checking winner
        if (check_winner(board, mark)){
            display_board(board);
            printf("Player %d wins!\n", player);
            break;
        }

        //Checking draw scenario
        int check_draw = 1;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j] != 'X' && board[i][j] != 'O'){
                    check_draw = 0;
                    break;
                }
            }
        }
        if (check_draw){
            printf("Draw game!\n");
            break;
        }

        //System turn
        printf("System chooses: %d\n", systemchoice);
        row = (systemchoice-1) / 3;
        col = (systemchoice-1) % 3;
        mark = (player == 1)? 'O': 'X';

        if (board[row][col] == mark){
            board[row][col] = mark;
        }
        else{
            continue;
        }

        //Checking winner
        if (check_winner(board, mark)){
            display_board(board);
            printf("System wins!\n");
            break;
        }

        //Checking draw scenario
        check_draw = 1;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[i][j] != 'X' && board[i][j] != 'O'){
                    check_draw = 0;
                    break;
                }
            }
        }
        if (check_draw){
            printf("Draw game!\n");
            break;
        }

        player = (player == 1)? 2: 1; //Changing player turn
    }
    
    return 0;
}