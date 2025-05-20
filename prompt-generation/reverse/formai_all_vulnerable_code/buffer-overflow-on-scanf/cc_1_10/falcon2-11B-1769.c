//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BOARD_SIZE 3
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY 0

void print_board(int board[][BOARD_SIZE], int board_size) {
    int i, j;
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", " ", " ", " ");
    printf("   |   |   \n");
    for (i = 0; i < board_size; i++) {
        printf("   |   |   \n");
        for (j = 0; j < board_size; j++) {
            printf(" %c | ", board[i][j] == PLAYER_1? "X" : (board[i][j] == PLAYER_2? "O" : " "));
        }
        printf("   |   |   \n");
    }
}

bool is_board_full(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool is_winner(int board[][BOARD_SIZE], int player) {
    bool result = false;
    int i, j;
    for (i = 0; i < BOARD_SIZE && result == false; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            result = true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            result = true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            result = true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            result = true;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    int player;
    int turn;
    bool game_over = false;
    int i, j;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X, Player 2: O\n");
    printf("Please enter your name:\n");
    scanf("%s", &player);
    printf("Alright, let's start!\n");
    print_board(board, BOARD_SIZE);
    turn = (rand() % 2) + 1;
    while (game_over == false) {
        printf("%s, it's your turn!\n", player);
        printf("Please enter your position:\n");
        scanf("%d %d", &i, &j);
        if (is_winner(board, turn) || is_board_full(board)) {
            game_over = true;
            if (is_winner(board, turn)) {
                printf("%s wins!\n", player);
            } else if (is_board_full(board)) {
                printf("It's a tie!\n");
            }
        } else {
            board[i][j] = turn;
            turn = (turn + 1) % 2;
            printf("You placed an %c at (%d, %d)\n", board[i][j] == PLAYER_1? "X" : "O", i, j);
            print_board(board, BOARD_SIZE);
        }
        printf("Player 2, it's your turn!\n");
        printf("Please enter your position:\n");
        scanf("%d %d", &i, &j);
        if (is_winner(board, (turn + 1) % 2) || is_board_full(board)) {
            game_over = true;
            if (is_winner(board, (turn + 1) % 2)) {
                printf("%s wins!\n", (turn + 1) % 2 == PLAYER_1? "Player 1" : "Player 2");
            } else if (is_board_full(board)) {
                printf("It's a tie!\n");
            }
        } else {
            board[i][j] = (turn + 1) % 2;
            printf("You placed an %c at (%d, %d)\n", board[i][j] == PLAYER_1? "X" : "O", i, j);
            print_board(board, BOARD_SIZE);
        }
    }
    return 0;
}