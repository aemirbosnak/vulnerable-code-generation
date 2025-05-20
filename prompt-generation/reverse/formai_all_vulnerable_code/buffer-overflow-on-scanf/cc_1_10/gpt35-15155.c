//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X';
int count = 0;

void draw_board();
void player_turn();
void check_winner(char);

int main(){
    int i, j;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
    draw_board();
    while (1){
        count++;
        player_turn();
        draw_board();
        check_winner(player);
        if(count == 9){
            printf("It's a draw!");
            exit(0);
        }
        if(player == 'X'){
            player = 'O';
        } else {
            player = 'X';
        }
    }
    return 0;
}

void draw_board(){
    int i, j;
    printf("\n");
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf(" %c ", board[i][j]);
            if (j<2){
                printf("|");
            }
        }
        if(i<2){
            printf("\n---|---|---\n");
        }
        printf("\n");
    }
}

void player_turn(){
    int row, col;
    printf("\nPlayer %c turn: ", player);
    scanf("%d %d", &row, &col);
    if (row<0 || row>2 || col<0 || col>2){
        printf("\nInvalid move! Try again.");
        player_turn();
    } else if (board[row][col] != ' '){
        printf("\nPosition taken! Try again.");
        player_turn();
    } else {
        board[row][col] = player;
    }
}

void check_winner(char player){
    int i, j;
    for (i=0; i<3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
            printf("\nPlayer %c is the winner!", player);
            exit(0);
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            printf("\nPlayer %c is the winner!", player);
            exit(0);
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        printf("\nPlayer %c is the winner!", player);
        exit(0);
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
        printf("\nPlayer %c is the winner!", player);
        exit(0);
    }
}