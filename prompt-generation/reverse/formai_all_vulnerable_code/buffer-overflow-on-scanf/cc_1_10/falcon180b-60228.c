//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY 0

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

int check_tie(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int get_empty_position(int board[BOARD_SIZE][BOARD_SIZE]) {
    int x, y;

    srand(time(NULL));
    x = rand() % BOARD_SIZE;
    y = rand() % BOARD_SIZE;

    while (board[x][y]!= EMPTY) {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    }

    return x * BOARD_SIZE + y;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = { {EMPTY, EMPTY, EMPTY},
                                            {EMPTY, EMPTY, EMPTY},
                                            {EMPTY, EMPTY, EMPTY} };
    int player = PLAYER_X;
    int last_move_x, last_move_y;

    srand(time(NULL));
    last_move_x = rand() % BOARD_SIZE;
    last_move_y = rand() % BOARD_SIZE;
    board[last_move_x][last_move_y] = player;

    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);

        int move_x, move_y;
        scanf("%d %d", &move_x, &move_y);

        int position = get_empty_position(board);
        if (position == -1) {
            printf("Board is full. Try again.\n");
            continue;
        }

        if (board[position / BOARD_SIZE][position % BOARD_SIZE]!= EMPTY) {
            printf("Position already taken. Try again.\n");
            continue;
        }

        board[position / BOARD_SIZE][position % BOARD_SIZE] = player;

        if (check_winner(board)) {
            printf("Player %d wins!\n", player);
            break;
        } else if (check_tie(board)) {
            printf("Tie game.\n");
            break;
        }

        player = (player == PLAYER_X)? PLAYER_O : PLAYER_X;
    }

    return 0;
}