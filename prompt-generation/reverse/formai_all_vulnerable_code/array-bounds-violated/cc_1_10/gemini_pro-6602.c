//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define PIECE_COUNT 16

typedef struct {
    char type;
    int color;
    int position;
} Piece;

typedef struct {
    Piece pieces[PIECE_COUNT];
    int turn;
    int winner;
} Game;

void print_board(Game *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece *piece = &game->pieces[(i * BOARD_SIZE) + j];
            if (piece->type == ' ') {
                printf("..");
            } else {
                printf("%c%c", piece->color == 0 ? 'W' : 'B', piece->type);
            }
        }
        printf("\n");
    }
}

int is_valid_move(Game *game, int from, int to) {
    Piece *piece = &game->pieces[from];
    if (piece->type == ' ') {
        return 0;
    }
    if (piece->color != game->turn) {
        return 0;
    }
    switch (piece->type) {
        case 'P':
            if (piece->color == 0) {
                if (to == from - 8 || (from % BOARD_SIZE == 1 && to == from - 9)) {
                    return 1;
                }
            } else {
                if (to == from + 8 || (from % BOARD_SIZE == 6 && to == from + 7)) {
                    return 1;
                }
            }
            break;
        case 'R':
            if (from % BOARD_SIZE == to % BOARD_SIZE || from / BOARD_SIZE == to / BOARD_SIZE) {
                return 1;
            }
            break;
        case 'N':
            if ((abs(from % BOARD_SIZE - to % BOARD_SIZE) == 1 && abs(from / BOARD_SIZE - to / BOARD_SIZE) == 2) ||
                (abs(from % BOARD_SIZE - to % BOARD_SIZE) == 2 && abs(from / BOARD_SIZE - to / BOARD_SIZE) == 1)) {
                return 1;
            }
            break;
        case 'B':
            if (abs(from % BOARD_SIZE - to % BOARD_SIZE) == abs(from / BOARD_SIZE - to / BOARD_SIZE)) {
                return 1;
            }
            break;
        case 'Q':
            if (from % BOARD_SIZE == to % BOARD_SIZE || from / BOARD_SIZE == to / BOARD_SIZE ||
                abs(from % BOARD_SIZE - to % BOARD_SIZE) == abs(from / BOARD_SIZE - to / BOARD_SIZE)) {
                return 1;
            }
            break;
        case 'K':
            if (abs(from % BOARD_SIZE - to % BOARD_SIZE) <= 1 && abs(from / BOARD_SIZE - to / BOARD_SIZE) <= 1) {
                return 1;
            }
            break;
    }
    return 0;
}

void make_move(Game *game, int from, int to) {
    Piece *piece = &game->pieces[from];
    game->pieces[to] = *piece;
    game->pieces[from].type = ' ';
    game->turn = (game->turn + 1) % 2;
}

int check_for_winner(Game *game) {
    for (int i = 0; i < PIECE_COUNT; i++) {
        Piece *piece = &game->pieces[i];
        if (piece->type == 'K' && piece->color != game->turn) {
            return game->turn;
        }
    }
    return -1;
}

int main() {
    Game game;
    memset(&game, 0, sizeof(Game));
    game.pieces[0] = (Piece) { 'R', 0, 0 };
    game.pieces[1] = (Piece) { 'N', 0, 1 };
    game.pieces[2] = (Piece) { 'B', 0, 2 };
    game.pieces[3] = (Piece) { 'Q', 0, 3 };
    game.pieces[4] = (Piece) { 'K', 0, 4 };
    game.pieces[5] = (Piece) { 'B', 0, 5 };
    game.pieces[6] = (Piece) { 'N', 0, 6 };
    game.pieces[7] = (Piece) { 'R', 0, 7 };
    game.pieces[8] = (Piece) { 'P', 0, 16 };
    game.pieces[9] = (Piece) { 'P', 0, 17 };
    game.pieces[10] = (Piece) { 'P', 0, 18 };
    game.pieces[11] = (Piece) { 'P', 0, 19 };
    game.pieces[12] = (Piece) { 'P', 0, 20 };
    game.pieces[13] = (Piece) { 'P', 0, 21 };
    game.pieces[14] = (Piece) { 'P', 0, 22 };
    game.pieces[15] = (Piece) { 'P', 0, 23 };
    game.pieces[48] = (Piece) { 'R', 1, 56 };
    game.pieces[49] = (Piece) { 'N', 1, 57 };
    game.pieces[50] = (Piece) { 'B', 1, 58 };
    game.pieces[51] = (Piece) { 'Q', 1, 59 };
    game.pieces[52] = (Piece) { 'K', 1, 60 };
    game.pieces[53] = (Piece) { 'B', 1, 61 };
    game.pieces[54] = (Piece) { 'N', 1, 62 };
    game.pieces[55] = (Piece) { 'R', 1, 63 };
    game.pieces[56] = (Piece) { 'P', 1, 40 };
    game.pieces[57] = (Piece) { 'P', 1, 41 };
    game.pieces[58] = (Piece) { 'P', 1, 42 };
    game.pieces[59] = (Piece) { 'P', 1, 43 };
    game.pieces[60] = (Piece) { 'P', 1, 44 };
    game.pieces[61] = (Piece) { 'P', 1, 45 };
    game.pieces[62] = (Piece) { 'P', 1, 46 };
    game.pieces[63] = (Piece) { 'P', 1, 47 };
    print_board(&game);
    while (1) {
        char input[5];
        printf("Enter your move (e.g. e2e4): ");
        gets(input);
        int from = (input[0] - 'a') + ((input[1] - '1') * BOARD_SIZE);
        int to = (input[2] - 'a') + ((input[3] - '1') * BOARD_SIZE);
        if (is_valid_move(&game, from, to)) {
            make_move(&game, from, to);
            print_board(&game);
            int winner = check_for_winner(&game);
            if (winner != -1) {
                printf("Player %d wins!\n", winner + 1);
                break;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    return 0;
}