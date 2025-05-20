//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

char board[SIZE][SIZE];
char current_player;

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void display_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int is_winner(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int is_board_full() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void switch_player() {
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void player_move() {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = current_player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void ai_move() {
    // Simple AI that picks the first available move
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = current_player;
                return;
            }
        }
    }
}

void play_game() {
    initialize_board();
    current_player = PLAYER_X;

    while (1) {
        display_board();
        if (current_player == PLAYER_X) {
            player_move();
        } else {
            ai_move();
            printf("AI (Player %c) made a move.\n", current_player);
        }
        
        if (is_winner(current_player)) {
            display_board();
            printf("Player %c wins!\n", current_player);
            return;
        }

        if (is_board_full()) {
            display_board();
            printf("It's a draw!\n");
            return;
        }

        switch_player();
    }
}

int main() {
    play_game();
    return 0;
}