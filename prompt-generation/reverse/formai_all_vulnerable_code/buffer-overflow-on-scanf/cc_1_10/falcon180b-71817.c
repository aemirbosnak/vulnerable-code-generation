//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define BOARD_SIZE (ROWS * COLS)
#define WINNING_CONDITIONS ((0b111 << (COLS - 1)) | (0b111 << (COLS - 2)))

void draw_board(bool board[BOARD_SIZE]) {
    printf("  1   2   3\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i * COLS + j]) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

bool check_win(bool board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i] & WINNING_CONDITIONS) == WINNING_CONDITIONS) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    bool board[BOARD_SIZE] = {false};
    int moves = 0;

    while (!check_win(board)) {
        int choice;
        printf("Player %d's turn.\n", moves + 1);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[choice - 1]) {
            printf("That spot is already taken.\n");
            continue;
        }
        board[choice - 1] = true;
        moves++;
        draw_board(board);
        if (check_win(board)) {
            printf("Player %d wins!\n", moves);
            break;
        }
    }

    return 0;
}