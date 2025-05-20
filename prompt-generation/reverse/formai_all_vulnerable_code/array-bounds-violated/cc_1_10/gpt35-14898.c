//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*function declaration*/
void display_board(char board[3][3]);
int check_win(char board[3][3]);
int check_tie(char board[3][3]);

int main() {
    char board[3][3]; /*creating 3x3 board*/
    int i, j, row, column, player = 1;

    /*initializing the board*/
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = ' '; /*blanks space in board*/
        }
    }

    printf("Welcome to Tic Tac Toe game!\n");
    printf("Player 1: X\nPlayer 2: O\n\n");

    /*game loop*/
    while(1) {
        display_board(board);

        /*player turn*/
        if(player%2 != 0) {
            printf("Player 1, enter row and column (e.g. 1-1): ");
            scanf("%d %d", &row, &column); /*input location of player move*/
            if(board[row-1][column-1] == ' ') { /*if position not taken*/
                board[row-1][column-1] = 'X'; /*make move*/
                player++; /*next player's turn*/
            }
            else {
                printf("That spot is already taken. Try again.\n");
            }
        }
        else {
            printf("Player 2, enter row and column (e.g. 2-3): ");
            scanf("%d %d", &row, &column);
            if(board[row-1][column-1] == ' ') {
                board[row-1][column-1] = 'O';
                player++;
            }
            else {
                printf("That spot is already taken. Try again.\n");
            }
        }

        /*check win condition*/
        if(check_win(board)) {
            display_board(board);
            if(player%2 != 0) {
                printf("Player 1 wins!\n");
            }
            else {
                printf("Player 2 wins!\n");
            }
            break;
        }

        /*check tie condition*/
        if(check_tie(board)) {
            display_board(board);
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}

/*function definitions*/
void display_board(char board[3][3]) {
    int i, j;
    printf("\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if(j != 2) {
                printf("|"); /*print | between columns*/
            }
        }
        if(i != 2) {
            printf("\n-----------\n"); /*print - between rows*/
        }
    }
    printf("\n\n");
}

int check_win(char board[3][3]) {
    int i;

    /*check rows*/
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    /*check columns*/
    for(i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    /*check diagonal*/
    if((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }

    return 0;
}

int check_tie(char board[3][3]) {
    int i, j;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0; /*not a tie*/
            }
        }
    }

    return 1; /*tie*/
}