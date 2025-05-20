//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

char board[3][3];
char current_player;

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool is_winner(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool is_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void switch_player() {
    if (current_player == PLAYER_X) {
        current_player = PLAYER_O;
    } else {
        current_player = PLAYER_X;
    }
}

void human_move() {
    int x, y;
    do {
        printf("Player %c, enter your move (row and column: 0-2): ", current_player);
        scanf("%d %d", &x, &y);
    } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != EMPTY);
    board[x][y] = current_player;
}

void ai_move() {
    // AI chooses a move (this could be improved with a better AI strategy)
    int x, y;
    printf("AI %c is making a move...\n", current_player);
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            if (board[x][y] == EMPTY) {
                board[x][y] = current_player;
                if (is_winner(current_player)) {
                    printf("AI chose position (%d, %d)\n", x, y);
                    return;
                }
                board[x][y] = EMPTY; // Undo the move
            }
        }
    }
    // If no winning move found, just choose the first empty spot
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            if (board[x][y] == EMPTY) {
                board[x][y] = current_player;
                printf("AI chose position (%d, %d)\n", x, y);
                return;
            }
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are Player X and I am Player O.\n");

    initialize_board();
    current_player = PLAYER_X;

    while (true) {
        print_board();
        if (current_player == PLAYER_X) {
            human_move();
        } else {
            ai_move();
        }

        if (is_winner(current_player)) {
            print_board();
            printf("Player %c wins!\n", current_player);
            break;
        }
        if (is_draw()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        switch_player();
    }

    return 0;
}