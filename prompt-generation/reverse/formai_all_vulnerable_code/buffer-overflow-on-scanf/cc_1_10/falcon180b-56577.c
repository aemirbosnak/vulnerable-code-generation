//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    for(j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void play_game() {
    int player = 1;
    int choice;
    int valid_move = 1;

    srand(time(NULL));
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    board[start_row][start_col] = 'X';

    while(valid_move) {
        system("clear");
        print_board();
        printf("\nPlayer %d's turn\n", player);

        valid_move = 0;
        do {
            printf("Enter your move (row col): ");
            scanf("%d %d", &choice, &choice);
            if(choice >= 0 && choice < ROWS && choice >= 0 && choice < COLS) {
                if(board[choice][choice] == '-') {
                    board[choice][choice] = (player == 1)? 'X' : 'O';
                    valid_move = 1;
                }
            }
        } while(!valid_move);

        if(check_win()) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }
}

int main() {
    play_game();
    return 0;
}