//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 8
#define MAX_MOVES 64

#define WHITE 1
#define BLACK -1

typedef struct board {
    int pieces[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int turn;
    int game_over;
} Board;

Board create_board() {
    Board board;
    board.turn = WHITE;
    board.game_over = 0;
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            board.pieces[i][j] = 0;
        }
    }
    return board;
}

int get_piece(Board board, int x, int y) {
    return board.pieces[x][y];
}

void set_piece(Board board, int x, int y, int piece) {
    board.pieces[x][y] = piece;
}

void print_board(Board board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            printf("%d ", get_piece(board, i, j));
        }
        printf("\n");
    }
}

void make_move(Board board, int x, int y, int piece) {
    set_piece(board, x, y, piece);
}

void flip_turn(Board board) {
    board.turn *= -1;
}

int check_winner(Board board) {
    int winner = 0;

    if (board.pieces[0][0]!= 0 && board.pieces[0][0] == board.pieces[1][1] && board.pieces[1][1] == board.pieces[2][2] && board.pieces[2][2] == board.pieces[3][3] && board.pieces[3][3] == board.pieces[4][4] && board.pieces[4][4] == board.pieces[5][5] && board.pieces[5][5] == board.pieces[6][6] && board.pieces[6][6] == board.pieces[7][7] && board.pieces[7][7] == board.pieces[0][0]) {
        winner = board.pieces[0][0];
    } else if (board.pieces[0][7]!= 0 && board.pieces[0][7] == board.pieces[1][6] && board.pieces[1][6] == board.pieces[2][5] && board.pieces[2][5] == board.pieces[3][4] && board.pieces[3][4] == board.pieces[4][3] && board.pieces[4][3] == board.pieces[5][2] && board.pieces[5][2] == board.pieces[6][1] && board.pieces[6][1] == board.pieces[7][0] && board.pieces[7][0] == board.pieces[0][7]) {
        winner = board.pieces[0][7];
    } else if (board.pieces[0][0]!= 0 && board.pieces[0][0] == board.pieces[7][7] && board.pieces[7][7] == board.pieces[6][6] && board.pieces[6][6] == board.pieces[5][5] && board.pieces[5][5] == board.pieces[4][4] && board.pieces[4][4] == board.pieces[3][3] && board.pieces[3][3] == board.pieces[2][2] && board.pieces[2][2] == board.pieces[1][1] && board.pieces[1][1] == board.pieces[0][0]) {
        winner = board.pieces[0][0];
    } else if (board.pieces[0][7]!= 0 && board.pieces[0][7] == board.pieces[7][6] && board.pieces[7][6] == board.pieces[6][5] && board.pieces[6][5] == board.pieces[5][4] && board.pieces[5][4] == board.pieces[4][3] && board.pieces[4][3] == board.pieces[3][2] && board.pieces[3][2] == board.pieces[2][1] && board.pieces[2][1] == board.pieces[1][0] && board.pieces[1][0] == board.pieces[0][7]) {
        winner = board.pieces[0][7];
    }

    return winner;
}

int main() {
    Board board = create_board();
    int moves[MAX_MOVES];
    int piece = WHITE;

    while (!board.game_over) {
        print_board(board);
        printf("It's %d's turn.\n", board.turn);
        scanf("%d", &moves[0]);

        if (moves[0] > 0 && get_piece(board, moves[0] % 8, moves[0] / 8) == 0) {
            make_move(board, moves[0] % 8, moves[0] / 8, piece);
            if (check_winner(board) == piece) {
                board.game_over = 1;
                printf("Player %d wins!\n", piece);
            } else {
                flip_turn(board);
            }
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}