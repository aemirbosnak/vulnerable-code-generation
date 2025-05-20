//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BOARD_SIZE 3

int board[BOARD_SIZE][BOARD_SIZE] = {0};  // Initialize board to all zeros
int player_turn = 1;
int game_over = 0;

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int player) {
    // Check rows for a winning condition
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns for a winning condition
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals for a winning condition
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

void* play_game(void* arg) {
    int thread_player = *(int*) arg;

    while (!game_over) {
        while (player_turn != thread_player) {
            // Wait for player's turn
        }

        print_board();

        int row, col;
        do {
            printf("Player %d, enter a row and column (e.g. 1 2): ", thread_player);
            scanf("%d %d", &row, &col);
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0);

        board[row-1][col-1] = thread_player;

        if (check_win(thread_player)) {
            printf("Player %d wins!\n", thread_player);
            game_over = 1;
        }

        player_turn = 3 - player_turn;  // Toggle player turn
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int player1 = 1, player2 = 2;

    printf("Starting tic-tac-toe game...\n");

    // Create threads for both players
    pthread_create(&thread1, NULL, play_game, &player1);
    pthread_create(&thread2, NULL, play_game, &player2);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Game over!\n");

    return 0;
}