//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#define BOARD_SIZE 8

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                printf("x ");
            } else if (board[i][j] == 2) {
                printf("o ");
            } else {
                printf(". ");
            }
        }
        printf("%d\n", i+1);
    }
    printf("  a b c d e f g h\n");
}

void move(int board[BOARD_SIZE][BOARD_SIZE], int player, int from_x, int from_y, int to_x, int to_y) {
    // Check if move is valid
    if (board[from_x][from_y] == player && board[to_x][to_y] == 0 && abs(to_x-from_x) == 1 && abs(to_y-from_y) == 1) {
        board[from_x][from_y] = 0;
        board[to_x][to_y] = player;
    } else if (board[from_x][from_y] == player && board[to_x][to_y] == 0 && abs(to_x-from_x) == 2 && abs(to_y-from_y) == 2) {
        int middle_x = (from_x + to_x) / 2;
        int middle_y = (from_y + to_y) / 2;
        if (board[middle_x][middle_y] == 3 - player) {
            board[from_x][from_y] = 0;
            board[middle_x][middle_y] = 0;
            board[to_x][to_y] = player;
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0}
    };
    int player = 1;
    printBoard(board);
    while (1) {
        printf("Player %d's turn\n", player);
        int from_x, from_y, to_x, to_y;
        printf("Enter piece to move: ");
        scanf("%d %d", &from_x, &from_y);
        printf("Enter destination: ");
        scanf("%d %d", &to_x, &to_y);
        move(board, player, from_x-1, from_y-1, to_x-1, to_y-1);
        printBoard(board);
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    return 0;
}