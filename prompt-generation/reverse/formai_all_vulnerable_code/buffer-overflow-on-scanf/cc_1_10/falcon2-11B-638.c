//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define BOARD_EMPTY '-'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
    int player;
    int moves;
} Player;

Player player1, player2;
Board board;

void generate_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board.board[i][j] = BOARD_EMPTY;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board.board[i][j]);
        }
        printf("\n");
    }
}

void set_player(int player) {
    if (player == 1) {
        player1.player = 1;
        player2.player = 2;
    } else if (player == 2) {
        player1.player = 2;
        player2.player = 1;
    }
}

int is_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == BOARD_EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void make_move(int player, int row, int col) {
    board.board[row][col] = (char)player;
}

int player_move(int player) {
    int row, col;
    while (1) {
        printf("Player %d, make your move (row, col): ", player);
        scanf("%d%d", &row, &col);
        if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE || board.board[row][col]!= BOARD_EMPTY) {
            printf("Invalid move. Try again.\n");
        } else {
            break;
        }
    }
    make_move(player, row, col);
    return 1;
}

void ai_move(int player) {
    int row, col;
    while (1) {
        srand(time(0));
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
        if (board.board[row][col] == BOARD_EMPTY) {
            break;
        }
    }
    make_move(player, row, col);
}

int is_winner(int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == player && 
                (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) &&
                (board.board[i + 1][j + 1] == player || board.board[i + 1][j - 1] == player || board.board[i - 1][j - 1] == player || board.board[i - 1][j + 1] == player)) {
                return 1;
            }
        }
    }
    return 0;
}

int check_winner() {
    if (is_full()) {
        return 1;
    } else {
        if (is_winner(player1.player)) {
            printf("Player 1 wins!\n");
            return 1;
        } else if (is_winner(player2.player)) {
            printf("Player 2 wins!\n");
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Select a difficulty level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    int difficulty;
    scanf("%d", &difficulty);
    set_player(difficulty);
    printf("Let's play!\n");
    while (!check_winner()) {
        if (player1.moves < 9) {
            player_move(player1.player);
        } else {
            ai_move(player2.player);
        }
        print_board();
        printf("\n");
        if (!check_winner()) {
            if (player2.moves < 9) {
                player_move(player2.player);
            } else {
                ai_move(player1.player);
            }
        }
    }
    return 0;
}