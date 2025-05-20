//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define EMPTY 0

void draw_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == PLAYER_ONE) {
                printf("O ");
            } else if(board[i][j] == PLAYER_TWO) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player) {
    int dir = 0;

    if(player == PLAYER_ONE) {
        dir = 1;
    } else {
        dir = -1;
    }

    int r = row;
    int c = col;

    while(r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
        if(board[r][c] == EMPTY) {
            return 0;
        } else if(board[r][c] == player) {
            return 1;
        } else {
            r += dir;
            c += dir;
        }
    }

    return 0;
}

int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void swap_player(int *player) {
    if(*player == PLAYER_ONE) {
        *player = PLAYER_TWO;
    } else {
        *player = PLAYER_ONE;
    }
}

void make_move(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player) {
    if(player == PLAYER_ONE) {
        board[row][col] = PLAYER_ONE;
    } else {
        board[row][col] = PLAYER_TWO;
    }
}

int main() {
    srand(time(NULL));

    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY}};
    int player = PLAYER_ONE;
    int row, col;

    printf("Player one: X, Player two: O\n");
    printf("Player %d's turn\n", player);

    while(!is_game_over(board)) {
        system("clear");
        draw_board(board);
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        if(!is_valid_move(board, row, col, player)) {
            printf("Invalid move\n");
            continue;
        }

        make_move(board, row, col, player);
        swap_player(&player);
    }

    draw_board(board);
    printf("Game over! Player %d wins!\n", player);

    return 0;
}