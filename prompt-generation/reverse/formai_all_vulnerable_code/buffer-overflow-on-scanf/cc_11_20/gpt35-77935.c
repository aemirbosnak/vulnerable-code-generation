//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the board
void display_board(char board[][3]) {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("\t%c", board[i][j]);
            if(j!=2) printf(" |");
        }
        printf("\n\t-----------------\n");
    }
    printf("\n");
}

// function to check if the game has been won
int check_win(char board[][3], char player) {
    if((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
       (board[1][0] == player && board[1][1] == player && board[1][2] == player) || 
       (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
       (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
       (board[0][1] == player && board[1][1] == player && board[2][1] == player) || 
       (board[0][2] == player && board[1][2] == player && board[2][2] == player) || 
       (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
       (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    else
        return 0;
}

int main() {
    char board[3][3] = { // initialize empty board
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player1, player2;
    int row, col, turn = 1, draw = 0, win = 0, valid_move = 0;
    srand(time(NULL));

    // randomly assign player 1 and player 2
    if(rand() % 2 == 0) {
        player1 = 'X';
        player2 = 'O';
    } else {
        player1 = 'O';
        player2 = 'X';
    }

    while(!win && !draw) { // game loop
        display_board(board);
        valid_move = 0;
        while(!valid_move) { // loop to get valid move from player
            if(turn % 2 == 1) {
                printf("Player 1 (%c), enter a row (0-2) and column (0-2): ", player1);
                scanf("%d%d", &row, &col);
                if(row>=0 && row<=2 && col>=0 && col<=2 && board[row][col]==' ') {
                    board[row][col] = player1;
                    valid_move = 1;
                } else {
                    printf("Invalid move, try again.\n");
                }
            } else {
                printf("Player 2 (%c), enter a row (0-2) and column (0-2): ", player2);
                scanf("%d%d", &row, &col);
                if(row>=0 && row<=2 && col>=0 && col<=2 && board[row][col]==' ') {
                    board[row][col] = player2;
                    valid_move = 1;
                } else {
                    printf("Invalid move, try again.\n");
                }
            }
        }
        if(check_win(board, player1)) {
            display_board(board);
            printf("Player 1 (%c) wins!\n", player1);
            win = 1;
        } else if(check_win(board, player2)) {
            display_board(board);
            printf("Player 2 (%c) wins!\n", player2);
            win = 1;
        } else if(turn == 9) {
            display_board(board);
            printf("It's a draw!\n");
            draw = 1;
        }
        turn++;
    }
    return 0;
}