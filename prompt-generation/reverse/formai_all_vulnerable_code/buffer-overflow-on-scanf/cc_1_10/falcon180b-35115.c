//Falcon-180B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_PLAYERS 2

char board[SIZE][SIZE]; // game board
int player_count; // number of players
int current_player; // current player
int game_over; // game status
int winner; // game winner

// Initialize game board
void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }
}

// Print game board
void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if game is over
int game_over_check() {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0]!= '*' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            count++;
        }
        if (board[0][i]!= '*' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            count++;
        }
    }
    if (count == SIZE) {
        return 1;
    } else if (count == SIZE * SIZE - 1) {
        return 2;
    } else {
        return 0;
    }
}

// Get player input
int get_player_input(int player) {
    int row, col;
    printf("Player %d, enter your move (row, column): ", player);
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '*') {
        board[row][col] = (player == 1)? 'X' : 'O';
        return 1;
    } else {
        printf("Invalid move. Try again.\n");
        return 0;
    }
}

// Play game
void play_game() {
    init_board();
    player_count = 2;
    current_player = 1;
    game_over = 0;
    while (!game_over) {
        print_board();
        if (current_player == 1) {
            printf("Player 1's turn.\n");
        } else {
            printf("Player 2's turn.\n");
        }
        int valid_move = get_player_input(current_player);
        if (valid_move) {
            if (game_over_check() == 1) {
                printf("Player %d wins!\n", current_player);
                winner = current_player;
                game_over = 1;
            } else if (game_over_check() == 2) {
                printf("Tie game.\n");
                game_over = 1;
            } else {
                current_player = (current_player == 1)? 2 : 1;
            }
        } else {
            current_player = (current_player == 1)? 2 : 1;
        }
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}