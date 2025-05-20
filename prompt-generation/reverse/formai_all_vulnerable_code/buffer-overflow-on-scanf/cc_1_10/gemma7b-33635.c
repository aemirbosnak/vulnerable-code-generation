//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
    int game_status;
} Board;

void initialize_board(Board *board) {
    board->game_status = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }
    board->current_player = PLAYER_X;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    if (board->game_status == 0 && board->board[0][0] != ' ') {
        return 2;
    }

    return 0;
}

void play_game(Board *board) {
    int move_number = 0;

    // Loop until there is a winner or a draw
    while (check_win(board) == 0) {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Validate the move
        if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        if (board->board[row][column] == ' ') {
            board->board[row][column] = board->current_player;
            move_number++;
        } else {
            printf("That move is not valid.\n");
            continue;
        }

        // Switch the player
        board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Print the winner or draw message
    if (check_win(board) == 1) {
        printf("Winner: %c!\n", board->current_player);
    } else if (check_win(board) == 2) {
        printf("Draw!\n");
    }
}

int main() {
    Board board;
    initialize_board(&board);
    play_game(&board);

    return 0;
}