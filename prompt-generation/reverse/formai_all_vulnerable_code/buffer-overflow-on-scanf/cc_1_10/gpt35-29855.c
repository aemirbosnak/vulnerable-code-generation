//FormAI DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVE 16

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    int prev_value = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int curr_value = board[row][col];
            if (prev_value > curr_value) {
                return 0;
            }
            prev_value = curr_value;
        }
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int move_count = 0;
    int max_move = MAX_MOVE;

    srand(time(NULL)); 

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = row * BOARD_SIZE + col + 1;
        }
    }
    board[BOARD_SIZE - 1][BOARD_SIZE - 1] = 0;

    int prev_row = BOARD_SIZE - 1; 
    int prev_col = BOARD_SIZE - 1;

    while (move_count < max_move) {
        print_board(board);
        int input;
        printf("Enter the number you want to move: ");
        scanf("%d", &input);

        int curr_row, curr_col;

        if (input == 0) {
            curr_row = BOARD_SIZE - 1;
            curr_col = BOARD_SIZE - 1;
        }
        else {
            curr_row = (input - 1) / BOARD_SIZE;
            curr_col = (input - 1) % BOARD_SIZE;
        }

        if (curr_row < 0 || curr_row >= BOARD_SIZE || curr_col < 0 || curr_col >= BOARD_SIZE) {
            printf("Invalid input!\n");
            continue;
        }

        if ((curr_row == prev_row && abs(curr_col - prev_col) == 1) || (curr_col == prev_col && abs(curr_row - prev_row) == 1)) {
            board[prev_row][prev_col] = board[curr_row][curr_col];
            board[curr_row][curr_col] = 0;
            prev_row = curr_row;
            prev_col = curr_col;
            move_count++;
        }
        else {
            printf("Invalid move!\n");
        }

        if (check_win(board)) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    if (move_count == max_move) {
        printf("Sorry, you lost. Better luck next time!\n");
    }

    return 0;
}