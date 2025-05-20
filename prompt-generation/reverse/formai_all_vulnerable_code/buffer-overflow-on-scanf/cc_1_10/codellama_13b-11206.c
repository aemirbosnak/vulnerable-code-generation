//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GAMES 10

// Function to get a random move for the AI
int get_random_move(int board[3][3]) {
    int move;
    do {
        move = rand() % 9;
    } while (board[move / 3][move % 3] != 0);
    return move;
}

// Function to check if the game is over
int is_game_over(int board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return -1;
}

// Function to print the board
void print_board(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int ai = 2;

    // Play the game
    while (1) {
        // Print the board
        print_board(board);

        // Get the player's move
        int move;
        do {
            printf("Enter a move (1-9): ");
            scanf("%d", &move);
        } while (move < 1 || move > 9 || board[move / 3][move % 3] != 0);
        board[move / 3][move % 3] = player;

        // Get the AI's move
        int ai_move = get_random_move(board);
        board[ai_move / 3][ai_move % 3] = ai;

        // Check if the game is over
        int result = is_game_over(board);
        if (result == player) {
            printf("Player wins!\n");
            break;
        } else if (result == ai) {
            printf("AI wins!\n");
            break;
        } else if (result == 0) {
            printf("Draw!\n");
            break;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}