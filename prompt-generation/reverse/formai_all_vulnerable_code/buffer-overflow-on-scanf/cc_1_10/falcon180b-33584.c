//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
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

void play_game() {
    int player = 0;
    int choice;
    init_board();
    while (1) {
        print_board();
        printf("Player %d's turn: ", player + 1);
        scanf("%d", &choice);
        if (choice < 0 || choice > 8) {
            printf("Invalid move!\n");
            continue;
        }
        int x, y;
        if (player % 2 == 0) {
            x = 0;
            y = choice;
        } else {
            x = choice;
            y = 0;
        }
        if (board[x][y]!= '-') {
            printf("Invalid move!\n");
            continue;
        }
        board[x][y] = (player % 2 == 0)? 'X' : 'O';
        if (check_winner()) {
            printf("Player %d wins!\n", player + 1);
            break;
        }
        player++;
        if (player % 2 == 0) {
            printf("AI's turn: ");
            int ai_move = rand() % 9;
            while (board[ai_move / 3][ai_move % 3]!= '-') {
                ai_move = rand() % 9;
            }
            board[ai_move / 3][ai_move % 3] = 'O';
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Tic Tac Toe!\n");
    play_game();
    return 0;
}