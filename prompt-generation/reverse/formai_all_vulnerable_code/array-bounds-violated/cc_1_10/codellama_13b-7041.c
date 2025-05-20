//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define X 1
#define O 2
#define EMPTY 0

int board[SIZE][SIZE];

void print_board() {
    printf(" 1 | 2 | 3\n");
    printf("--------\n");
    printf(" 4 | 5 | 6\n");
    printf("--------\n");
    printf(" 7 | 8 | 9\n");
}

void draw_board() {
    printf(" ________\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[0][0]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[1][0]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[2][0]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[0][1]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[1][1]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[2][1]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[0][2]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[1][2]);
    printf("|_______|\n");
    printf("|       |\n");
    printf("|   %c   |\n", board[2][2]);
    printf("|_______|\n");
}

void clear_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int check_win(int player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                break;
            }
            if (j == SIZE - 1) {
                return player;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[j][i] != player) {
                break;
            }
            if (j == SIZE - 1) {
                return player;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            break;
        }
        if (i == SIZE - 1) {
            return player;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i][SIZE - i - 1] != player) {
            break;
        }
        if (i == SIZE - 1) {
            return player;
        }
    }
    return 0;
}

void make_move(int player, int row, int col) {
    if (board[row][col] != EMPTY) {
        printf("Invalid move.\n");
    } else {
        board[row][col] = player;
        printf("Player %d makes move at (%d, %d).\n", player, row, col);
    }
}

void play_game() {
    clear_board();
    int player = X;
    int row, col;
    while (1) {
        print_board();
        printf("Player %d, enter row and col: ", player);
        scanf("%d %d", &row, &col);
        make_move(player, row, col);
        if (check_win(player)) {
            printf("Player %d wins.\n", player);
            break;
        }
        player = player == X ? O : X;
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}