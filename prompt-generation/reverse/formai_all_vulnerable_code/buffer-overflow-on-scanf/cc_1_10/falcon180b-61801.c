//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BOARD_SIZE 3
#define EMPTY '.'
#define X 'X'
#define O 'O'

char board[BOARD_SIZE][BOARD_SIZE];
int turn = 0;
int game_over = 0;
int winner = 0;

void draw_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void check_winner() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = turn;
            game_over = 1;
            break;
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner = turn;
            game_over = 1;
            break;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = turn;
        game_over = 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = turn;
        game_over = 1;
    }
}

void make_move(int row, int col) {
    if (board[row][col] == EMPTY) {
        board[row][col] = (turn % 2 == 0)? X : O;
        turn++;
        check_winner();
    }
}

void* player_thread(void* arg) {
    int player = *(int*) arg;
    char input[3];
    while (game_over == 0) {
        printf("Player %d, enter your move (row, column): ", player);
        scanf("%s", input);
        int row = input[0] - '0';
        int col = input[1] - '0';
        make_move(row, col);
        draw_board();
        printf("Player %d's turn.\n", (player % 2) + 1);
        fflush(stdout);
        usleep(100000);
    }
    pthread_exit(0);
}

int main() {
    pthread_t threads[2];
    int players[2] = {0, 1};
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, player_thread, &players[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}