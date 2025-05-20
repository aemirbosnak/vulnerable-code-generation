//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum CellState { EMPTY, PLAYER_ONE, PLAYER_TWO } CellState;

CellState board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

CellState player_turn = PLAYER_ONE;

void place_mark(int x, int y) {
    if (board[x][y] != EMPTY) {
        return;
    }
    board[x][y] = player_turn;
}

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != EMPTY) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY) {
        return 1;
    }

    // If all else fails, it's a draw
    return 2;
}

int main() {
    int game_loop = 1;
    while (game_loop) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Place the mark
        place_mark(x, y);

        // Check if the game has ended
        int winner = check_win();
        if (winner == 1) {
            printf("You win!");
        } else if (winner == 2) {
            printf("It's a draw!");
        } else {
            // Switch to the next player
            player_turn = (player_turn == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }

        // Ask if the player wants to continue
        printf("Do you want to continue? (Y/N): ");
        char continue_answer;
        scanf("%c", &continue_answer);

        // If the player does not want to continue, end the game
        if (continue_answer == 'N') {
            game_loop = 0;
        }
    }

    return 0;
}