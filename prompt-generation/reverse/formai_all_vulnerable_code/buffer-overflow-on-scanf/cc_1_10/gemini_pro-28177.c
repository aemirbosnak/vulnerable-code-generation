//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int value;
    int x;
    int y;
} tile;

tile board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = 0;
            board[i][j].x = i;
            board[i][j].y = j;
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j].value);
        }
        printf("\n");
    }
}

int move_tile(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
        x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return -1;
    }

    if (board[x1][y1].value == 0) {
        return -1;
    }

    if (board[x2][y2].value != 0) {
        return -1;
    }

    board[x2][y2].value = board[x1][y1].value;
    board[x1][y1].value = 0;

    return 0;
}

int check_win() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].value != (i * BOARD_SIZE + j + 1) % (BOARD_SIZE * BOARD_SIZE)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;
    int x1, y1, x2, y2;

    srand(time(NULL));

    init_board();

    while (!check_win()) {
        print_board();

        printf("Enter the coordinates of the tile you want to move (x1, y1): ");
        scanf("%d %d", &x1, &y1);

        printf("Enter the coordinates of the empty space (x2, y2): ");
        scanf("%d %d", &x2, &y2);

        if (move_tile(x1, y1, x2, y2) == -1) {
            printf("Invalid move!\n");
        }
    }

    print_board();

    printf("Congratulations! You win!\n");

    return 0;
}