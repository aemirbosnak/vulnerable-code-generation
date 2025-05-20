//Falcon-180B DATASET v1.0 Category: Chess AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
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

void place_piece(char piece, int x, int y) {
    board[x][y] = piece;
}

int main() {
    init_board();
    int player = 1;
    while (1) {
        print_board();
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y]!= '.') {
            printf("Invalid move!\n");
            continue;
        }
        place_piece('X', x, y);
        player++;
        if (player % 2 == 0) {
            place_piece('O', (x+y) / 2, (x+y) / 2);
        }
        if (check_win()) {
            printf("Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}

int check_win() {
    // TODO: implement win condition check
    return 0;
}