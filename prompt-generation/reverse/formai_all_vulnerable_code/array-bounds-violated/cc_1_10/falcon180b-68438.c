//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int check_draw(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j]!= 1 && board[i][j]!= -1)
                return 0;
        }
    }
    return 1;
}

void ai_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    int move = rand() % BOARD_SIZE;
    int row = rand() % BOARD_SIZE;
    while (board[row][move]!= 0) {
        move = rand() % BOARD_SIZE;
        row = rand() % BOARD_SIZE;
    }
    board[row][move] = -1;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int player = 1;
    while (1) {
        system("clear");
        print_board(board);
        printf("Player %d's turn\n", player);
        int x, y;
        if (player == 1) {
            scanf("%d %d", &x, &y);
            if (board[x][y] == 0) {
                board[x][y] = 1;
                player = -1;
            }
        } else {
            ai_move(board);
            player = 1;
        }
        if (check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        } else if (check_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}