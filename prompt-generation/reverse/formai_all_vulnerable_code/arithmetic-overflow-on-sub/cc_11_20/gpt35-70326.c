//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to display the board
void display_board(char board[3][3]){
    printf("\n");
    printf("\t %c | %c | %c     1 2 3\n", board[0][0], board[0][1], board[0][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c     4 5 6\n", board[1][0], board[1][1], board[1][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c     7 8 9\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

//function to check if anyone has won
int check_win(char board[3][3], char mark){
    if ((board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) ||
        (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) ||
        (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark) ||
        (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) ||
        (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) ||
        (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark) ||
        (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return 1;
    else
        return 0;
}

int main(){
    char board[3][3];
    int choice, row, col, player = 1, winner = 0;
    char mark;

    //initialize board spaces with '-'
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }

    printf("Tic Tac Toe\n");
    display_board(board);

    while (!winner){
        //switch between player 1 and player 2
        player = (player % 2) ? 1 : 2;

        //get player's choice
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        //determine the row and column of the selected cell
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        //check if the selected cell is already taken
        if (board[row][col] == '-'){
            if (player == 1)
                mark = 'X';
            else
                mark = 'O';
            board[row][col] = mark;
        }
        else{
            printf("Cell is already taken!\n");
            continue;
        }

        //display updated board
        display_board(board);

        //check for winner
        if (check_win(board, mark)){
            printf("Player %d wins!\n", player);
            winner = 1;
        }
        else if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' &&
                 board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' &&
                 board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-'){
            printf("Draw!\n");
            winner = 1;
        }
    }

    return 0;
}