//Falcon-180B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define WIN_CONDITION 3

int board[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int player = 1;

void print_board() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    int choice;

    while(1) {
        system("clear");
        print_board();
        printf("Player %d's turn\n", player);

        choice = rand() % COLS;
        if(board[0][choice]!= 0) {
            board[0][choice] = player;
            break;
        }
    }

    while(1) {
        int x, y;
        system("clear");
        print_board();
        printf("Player %d's turn\n", player);

        scanf("%d %d", &x, &y);
        if(x >= 0 && x < COLS && y >= 0 && y < ROWS && board[y][x] == 0) {
            board[y][x] = player;
            if(check_win()) {
                printf("Player %d wins!\n", player);
                break;
            }
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}