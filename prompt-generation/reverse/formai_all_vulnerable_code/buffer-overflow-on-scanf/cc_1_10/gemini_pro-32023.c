//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define BOARD_SIZE 3

typedef enum {
    NOUGHT,
    CROSS,
    EMPTY
} player;

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// The current player
player current_player;

// Mutex to protect the game board
pthread_mutex_t board_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when the game is over
pthread_cond_t game_over_cond = PTHREAD_COND_INITIALIZER;

// Function to check if the game is over
int is_game_over() {
    // Check if there is a winner
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check if there is a tie
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to make a move
void make_move(int x, int y) {
    // Lock the game board
    pthread_mutex_lock(&board_mutex);

    // Make the move
    board[x][y] = current_player;

    // Unlock the game board
    pthread_mutex_unlock(&board_mutex);

    // Signal that the game is over if necessary
    if (is_game_over()) {
        pthread_cond_signal(&game_over_cond);
    }
}

// Function to get the best move for the computer
int get_best_move() {
    // Loop through all possible moves
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // If the move is valid, make it and see if it wins
            if (board[i][j] == EMPTY) {
                board[i][j] = current_player;
                if (is_game_over()) {
                    return i * BOARD_SIZE + j;
                }
                // If the move doesn't win, undo it
                board[i][j] = EMPTY;
            }
        }
    }

    // If no winning move is found, return a random move
    while (1) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[x][y] == EMPTY) {
            return x * BOARD_SIZE + y;
        }
    }
}

// Function to play the game
void play_game() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Set the current player
    current_player = CROSS;

    // Loop until the game is over
    while (!is_game_over()) {
        // Get the player's move
        int x, y;
        if (current_player == CROSS) {
            printf("Enter your move (x, y): ");
            scanf("%d %d", &x, &y);
            make_move(x, y);
        } else {
            int move = get_best_move();
            make_move(move / BOARD_SIZE, move % BOARD_SIZE);
        }

        // Switch the current player
        current_player = (current_player == CROSS) ? NOUGHT : CROSS;
    }

    // Print the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Print the winner
    if (current_player == CROSS) {
        printf("Noughts win!\n");
    } else if (current_player == NOUGHT) {
        printf("Crosses win!\n");
    } else {
        printf("Tie!\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}