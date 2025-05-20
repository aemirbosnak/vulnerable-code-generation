//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK -1
#define EMPTY 0

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

void init_board(GameState *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    // Placing pieces for White
    game->board[0][0] = game->board[0][7] = 'R';
    game->board[0][1] = game->board[0][6] = 'N';
    game->board[0][2] = game->board[0][5] = 'B';
    game->board[0][3] = 'Q';
    game->board[0][4] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) game->board[1][i] = 'P';

    // Placing pieces for Black
    game->board[7][0] = game->board[7][7] = 'r';
    game->board[7][1] = game->board[7][6] = 'n';
    game->board[7][2] = game->board[7][5] = 'b';
    game->board[7][3] = 'q';
    game->board[7][4] = 'k';
    for (int i = 0; i < BOARD_SIZE; i++) game->board[6][i] = 'p';

    game->turn = WHITE;
}

void print_board(GameState *game) {
    printf("\n   a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = game->board[i][j];
            printf("%c ", piece == EMPTY ? '.' : piece);
        }
        printf("|\n");
    }
    printf(" +-----------------\n");
}

int is_valid_move(int piece, int start_x, int start_y, int end_x, int end_y) {
    // Basic validation by piece type and movement distance
    // This can be expanded for more rules
    if (piece == 'P') return (end_x == start_x + 1 && end_y == start_y) || (end_x == start_x + 1 && abs(end_y - start_y) == 1);
    if (piece == 'p') return (end_x == start_x - 1 && end_y == start_y) || (end_x == start_x - 1 && abs(end_y - start_y) == 1);
    if (piece == 'R' || piece == 'r') return (end_x == start_x || end_y == start_y);
    if (piece == 'N' || piece == 'n') return (abs(end_x - start_x) == 2 && abs(end_y - start_y) == 1) || (abs(end_x - start_x) == 1 && abs(end_y - start_y) == 2);

    // Currently do not handle other pieces and check for obstructions further.
    return 0;
}

void move_piece(GameState *game, int start_x, int start_y, int end_x, int end_y) {
    int piece = game->board[start_x][start_y];
    if (is_valid_move(piece, start_x, start_y, end_x, end_y)) {
        game->board[end_x][end_y] = piece;
        game->board[start_x][start_y] = EMPTY;
        game->turn = (game->turn == WHITE) ? BLACK : WHITE;
    } else {
        printf("Invalid move!\n");
    }
}

void player_turn(GameState *game) {
    char start[3], end[3];
    printf("Player %s's turn. Enter move (e.g., a2 a3): ", game->turn == WHITE ? "White" : "Black");
    scanf("%s %s", start, end);

    int start_x = BOARD_SIZE - (start[1] - '0');
    int start_y = start[0] - 'a';
    int end_x = BOARD_SIZE - (end[1] - '0');
    int end_y = end[0] - 'a';

    move_piece(game, start_x, start_y, end_x, end_y);
}

void play_game() {
    GameState game;
    init_board(&game);
    
    while (1) {
        print_board(&game);
        player_turn(&game);
    }
}

int main() {
    printf("Welcome to the Curious Chess AI!\n");
    play_game();
    return 0;
}