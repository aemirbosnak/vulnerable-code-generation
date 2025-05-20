//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define EMPTY_CELL '-'

typedef enum {
    PLAYER_X = 1,
    PLAYER_O = 2
} Player;

typedef struct {
    Player player;
    int row;
    int col;
} Move;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    Player current_player;
} Game;

void init_game(Game* game) {
    memset(game->board, EMPTY_CELL, sizeof(game->board));
    game->current_player = PLAYER_X;
}

void print_board(const Game* game) {
    for (int row=0; row<BOARD_SIZE; ++row) {
        for (int col=0; col<BOARD_SIZE; ++col) {
            printf("%c ", game->board[row][col]);
        }
        printf("\n");
    }
}

Move get_move_input(const Game* game) {
    Move move;
    printf("Player %d: Enter move [row col]: ", game->current_player);
    scanf("%d %d", &move.row, &move.col);
    move.player = game->current_player;
    return move;
}

int is_valid_move(const Game* game, const Move* move) {
    if (move->row >= BOARD_SIZE || move->col >= BOARD_SIZE) {
        return 0;
    }
    if (game->board[move->row][move->col] != EMPTY_CELL) {
        return 0;
    }
    return 1;
}

int is_win(const Game* game) {
    for (int i=0; i<BOARD_SIZE; ++i) {
        if (game->board[i][0] != EMPTY_CELL && 
            game->board[i][0] == game->board[i][1] && 
            game->board[i][1] == game->board[i][2])
            return 1;
        if (game->board[0][i] != EMPTY_CELL && 
            game->board[0][i] == game->board[1][i] && 
            game->board[1][i] == game->board[2][i])
            return 1;
    }
    if (game->board[0][0] != EMPTY_CELL && 
        game->board[0][0] == game->board[1][1] && 
        game->board[1][1] == game->board[2][2])
        return 1;
    if (game->board[2][0] != EMPTY_CELL && 
        game->board[2][0] == game->board[1][1] && 
        game->board[1][1] == game->board[0][2])
        return 1;
    return 0;
}

int is_tie(const Game* game) {
    for (int row=0; row<BOARD_SIZE; ++row) {
        for (int col=0; col<BOARD_SIZE; ++col) {
            if (game->board[row][col] == EMPTY_CELL) {
                return 0;
            }
        }
    }
    return 1;
}

void make_move(Game* game, const Move* move) {
    game->board[move->row][move->col] = (move->player == PLAYER_X) ? 'X' : 'O';
    if (game->current_player == PLAYER_X) {
        game->current_player = PLAYER_O;
    } else {
        game->current_player = PLAYER_X;
    }
}

Move get_computer_move(const Game* game) {
    Move move;
    char computer_symbol = (game->current_player == PLAYER_X) ? 'X' : 'O';
    char opponent_symbol = (game->current_player == PLAYER_X) ? 'O' : 'X';

    // Check if the computer can win in the next move
    for (int row=0; row<BOARD_SIZE; ++row) {
        for (int col=0; col<BOARD_SIZE; ++col) {
            if (game->board[row][col] == EMPTY_CELL) {
                Game temp_game = *game;
                temp_game.board[row][col] = computer_symbol;
                if (is_win(&temp_game)) {
                    move.row = row;
                    move.col = col;
                    move.player = game->current_player;
                    return move;
                }
            }
        }
    }

    // Check if the opponent can win in the next move and block
    for (int row=0; row<BOARD_SIZE; ++row) {
        for (int col=0; col<BOARD_SIZE; ++col) {
            if (game->board[row][col] == EMPTY_CELL) {
                Game temp_game = *game;
                temp_game.board[row][col] = opponent_symbol;
                if (is_win(&temp_game)) {
                    move.row = row;
                    move.col = col;
                    move.player = game->current_player;
                    return move;
                }
            }
        }
    }

    // Choose a random move
    while (1) {
        move.row = rand() % BOARD_SIZE;
        move.col = rand() % BOARD_SIZE;
        move.player = game->current_player;
        if (is_valid_move(game, &move)) {
            return move;
        }
    }
}

int main() {
    Game game;
    Move move;
    int is_game_over;

    srand((unsigned int) time(NULL));

    init_game(&game);

    while (1) {
        print_board(&game);
        if (game.current_player == PLAYER_X) {
            move = get_move_input(&game);
        } else {
            move = get_computer_move(&game);
            printf("Computer chooses: %d %d\n", move.row, move.col);
        }
        if (!is_valid_move(&game, &move)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        make_move(&game, &move);
        if (is_win(&game)) {
            printf("Player %d wins!\n", game.current_player);
            is_game_over = 1;
        } else if (is_tie(&game)) {
            printf("It's a tie!\n");
            is_game_over = 1;
        } else {
            is_game_over = 0;
        }
        if (is_game_over) {
            printf("Do you want to play again? [y/n]: ");
            char response;
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                printf("Starting a new game...\n");
                init_game(&game);
                is_game_over = 0;
            } else {
                break;
            }
        }
    }

    return 0;
}