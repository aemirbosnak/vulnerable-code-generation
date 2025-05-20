//Falcon-180B DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int current_player = 0;
    int game_over = 0;

    while (!game_over) {
        printf("Player %d's turn\n", current_player + 1);
        int row, col;
        if (current_player % 2 == 0) {
            printf("Enter row and column: ");
            scanf("%d%d", &row, &col);
            board[row][col] = 1;
            current_player++;
        } else {
            int rand_row, rand_col;
            do {
                rand_row = rand() % BOARD_SIZE;
                rand_col = rand() % BOARD_SIZE;
            } while (board[rand_row][rand_col]!= 0);
            board[rand_row][rand_col] = 2;
            current_player++;
        }
        print_board(board);
        game_over = check_win(board);
    }

    printf("Game over! Player %d wins!\n", current_player % NUM_PLAYERS + 1);

    return 0;
}