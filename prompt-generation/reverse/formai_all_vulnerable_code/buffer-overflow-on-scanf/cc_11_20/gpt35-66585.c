//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to check if a given player has won
int checkWin(char board[3][3], char player) {
    int i,j;

    for(i=0;i<3;i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    for(i=0;i<3;i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if(board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int i,j,player=1,row,col;
    char mark;

    printf("\n\n\t\t\tC Table Game\n\n");

    //loop to play the game until one player wins or the board is full
    while(1) {
        printf("Player %d, enter a row (1-3) and column (1-3) to place your mark: ", player);
        scanf("%d%d", &row, &col);

        //checking if the input is valid i.e., within the range and the cell is not already marked
        if(row<1 || row>3 || col<1 || col>3) {
            printf("Invalid input. Please enter a row (1-3) and column (1-3) again.\n");
            continue;
        }

        if(board[row-1][col-1] != ' ') {
            printf("Cell already marked. Please enter a row (1-3) and column (1-3) again.\n");
            continue;
        }

        //marking the cell with the respective player's mark
        if(player == 1) {
            mark = 'X';
        } else {
            mark = 'O';
        }

        board[row-1][col-1] = mark;

        //displaying the current state of the board
        printf("\n\n");
        printf("\t\t %c | %c | %c \n", board[0][0],board[0][1],board[0][2]);
        printf("\t\t-----------\n");
        printf("\t\t %c | %c | %c \n", board[1][0],board[1][1],board[1][2]);
        printf("\t\t-----------\n");
        printf("\t\t %c | %c | %c \n\n", board[2][0],board[2][1],board[2][2]);

        //checking if the current player has won the game
        if(checkWin(board, mark)) {
            printf("Congratulations! Player %d wins!\n", player);
            break;
        }

        //if the board is full and no one has won, the game is a draw
        int count = 0;
        for(i=0;i<3;i++) {
            for(j=0;j<3;j++) {
                if(board[i][j] != ' ') {
                    count++;
                }
            }
        }

        if(count == 9) {
            printf("Game draw\n");
            break;
        }

        //switching the turn to the next player
        if(player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}