//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[][3]) {
    printf("-------------\n");
    for(int i=0; i<3; i++) {
        printf("| ");
        for(int j=0; j<3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int check_win(int board[][3], char player) {
    for(int i=0; i<3; i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) {
            return 1;
        }
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) {
            return 1;
        }
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) {
        return 1;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) {
        return 1;
    }
    return 0;
}

int main() {
    int board[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j]=' ';
        }
    }
    srand(time(NULL));
    char player1;
    char player2;
    int rand_num = rand() % 2;
    if(rand_num == 0) {
        player1 = 'X';
        player2 = 'O';
        printf("Player 1 will be X\n");
        printf("Player 2 will be O\n");
    }
    else {
        player1 = 'O';
        player2 = 'X';
        printf("Player 1 will be O\n");
        printf("Player 2 will be X\n");
    }
    int player_turn = 1;
    int row;
    int column;
    while(1) {
        print_board(board);
        if(player_turn == 1) {
            printf("Player 1's turn (");
            printf("%c", player1);
            printf("): ");
            scanf("%d %d", &row, &column);
            if(row<1 || row>3) {
                printf("Invalid row number\n");
                continue;
            }
            else if(column<1 || column>3) {
                printf("Invalid column number\n");
                continue;
            }
            else if(board[row-1][column-1]!=' ') {
                printf("That spot is already taken\n");
                continue;
            }
            else {
                board[row-1][column-1] = player1;
                if(check_win(board, player1)) {
                    printf("Player 1 wins!\n");
                    return 0;
                }
                player_turn = 2;
            }
        }
        else {
            printf("Player 2's turn (");
            printf("%c", player2);
            printf("): ");
            scanf("%d %d", &row, &column);
            if(row<1 || row>3) {
                printf("Invalid row number\n");
                continue;
            }
            else if(column<1 || column>3) {
                printf("Invalid column number\n");
                continue;
            }
            else if(board[row-1][column-1]!=' ') {
                printf("That spot is already taken\n");
                continue;
            }
            else {
                board[row-1][column-1] = player2;
                if(check_win(board, player2)) {
                    printf("Player 2 wins!\n");
                    return 0;
                }
                player_turn = 1;
            }
        }
    }
}