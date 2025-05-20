//Falcon-180B DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display the game board
void display_board(int board[3][3]) {
    printf("\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j] == 0) {
                printf(" %d ",i*3+j+1);
            }
            else if(board[i][j] == 1) {
                printf(" X ");
            }
            else {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

// Function to check the game status
int check_game_status(int board[3][3]) {
    for(int i=0;i<3;i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return board[i][i];
        }
    }
    for(int i=0;i<3;i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][i];
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

// Function to check if a move is valid
int check_move(int board[3][3], int row, int col) {
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0) {
        return 1;
    }
    return 0;
}

// Function to make a move
void make_move(int board[3][3], int row, int col) {
    if(check_move(board,row,col)) {
        board[row][col] = 1;
        display_board(board);
        if(check_game_status(board) == 1) {
            printf("\nPlayer 1 wins!");
            exit(0);
        }
        else if(check_game_status(board) == -1) {
            printf("\nPlayer 2 wins!");
            exit(0);
        }
    }
    else {
        printf("\nInvalid move!");
    }
}

// Function to play the game
void play_game(int board[3][3]) {
    int player = 1;
    while(1) {
        display_board(board);
        printf("\nPlayer %d's turn:",player);
        int row, col;
        scanf("%d%d",&row,&col);
        make_move(board,row,col);
        if(check_game_status(board)!= 0) {
            break;
        }
        player = (player == 1)? 2 : 1;
    }
}

int main() {
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    srand(time(NULL));
    play_game(board);
    return 0;
}