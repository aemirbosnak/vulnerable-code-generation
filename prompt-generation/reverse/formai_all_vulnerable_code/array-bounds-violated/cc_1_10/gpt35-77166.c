//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

// function to check if a move is valid
int isValid(int i, int j, char board[][3]) {
    if(board[i][j] == '-')
        return 1;
    return 0;
}

// function to check if game is over
int checkGameOver(char board[][3], char c) {
    int i, j;

    for(i=0; i<3; i++) { //check horizontal rows
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return 1;
    }

    for(i=0; i<3; i++) { //check vertical columns
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return 1;
    }

    //check diagonal
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return 1;

    //check reverse diagonal
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return 1;

    //check if board is full
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if(board[i][j] == '-')
                return 0;
        }
    }

    return 2; //tie
}

int main() {
    char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    int i, j, pid, status, gameOver, turn;
    char c;

    turn = 0; // player 1's turn

    while(1) {
        // print board
        printf("\nBoard:\n");
        for(i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        if(turn == 0) {
            printf("\nPlayer 1 (X)'s turn:\n");
            c = 'X';
        }
        else {
            printf("\nPlayer 2 (O)'s turn:\n");
            c = 'O';
        }

        printf("Enter row and column (between 1-3):");
        scanf("%d %d", &i, &j);
        i--;
        j--;

        if(isValid(i, j, board)) {
            board[i][j] = c;
        }
        else {
            printf("Invalid move, try again.\n");
            continue;
        }

        gameOver = checkGameOver(board, c);

        if(gameOver == 1) {
            printf("\nPlayer %d (%c) won!\n", turn+1, c);
            break;
        }
        else if(gameOver == 2) {
            printf("\nIt's a tie!\n");
            break;
        }

        turn = !turn; // switch player turn
    }

    return 0;
}