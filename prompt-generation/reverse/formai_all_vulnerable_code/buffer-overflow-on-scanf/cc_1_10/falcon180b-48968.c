//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define AI_DELAY 1000000 // in microseconds

int board[BOARD_SIZE][BOARD_SIZE]; // game board
int player = 1; // current player
int ai_player = 2; // AI player
int game_over = 0; // flag to indicate game over

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

void ai_move() {
    int x, y;
    while (1) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x!= 0 && y!= 0) {
                break;
            }
        }
        usleep(AI_DELAY);
        if (check_winner() == 1) {
            game_over = 1;
            break;
        }
    }
    board[x][y] = ai_player;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    while (!game_over) {
        int x, y;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d%d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == 0) {
            board[x][y] = player;
            print_board();
            if (check_winner() == 1) {
                game_over = 1;
                printf("Player %d wins!\n", player);
            } else {
                player = (player == 1)? 2 : 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    if (game_over == 0) {
        printf("It's a draw.\n");
    }
    return 0;
}