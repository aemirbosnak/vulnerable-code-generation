//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char *positions[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
const char *marks[] = {"X", "O"};
char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool is_human_turn = true;
bool is_game_over = false;
int winner = -1;

void draw_board() {
    printf("\n");
    for (int i = 0; i < 9; i++) {
        printf(" %c ", board[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int get_move(bool is_human) {
    int move;
    if (is_human) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
    } else {
        // TODO: Implement AI move
        move = -1;
    }
    return move;
}

bool is_valid_move(int move) {
    return move >= 0 && move <= 8 && board[move] == ' ';
}

void make_move(int move, char mark) {
    board[move] = mark;
}

bool is_game_won() {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] != ' ') {
        return true;
    }
    if (board[2] == board[4] && board[2] == board[6] && board[2] != ' ') {
        return true;
    }

    return false;
}

void declare_winner() {
    if (winner == 0) {
        printf("Congratulations, you won!\n");
    } else if (winner == 1) {
        printf("Sorry, you lost.\n");
    } else {
        printf("It's a draw.\n");
    }
}

int main() {
    // Draw the initial board
    draw_board();

    // Game loop
    while (!is_game_over) {
        // Get the move from the current player
        int move = get_move(is_human_turn);

        // Check if the move is valid
        if (is_valid_move(move)) {
            // Make the move
            make_move(move, marks[is_human_turn]);

            // Check if the game is won
            if (is_game_won()) {
                winner = is_human_turn ? 0 : 1;
                is_game_over = true;
            } else {
                // Switch turns
                is_human_turn = !is_human_turn;
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }

        // Draw the updated board
        draw_board();
    }

    // Declare the winner
    declare_winner();

    return 0;
}