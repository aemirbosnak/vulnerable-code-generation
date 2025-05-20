//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 9

// Define the player symbols
#define PLAYER1_SYMBOL 'X'
#define PLAYER2_SYMBOL 'O'

// Define the game state
#define GAME_STATE_IN_PROGRESS 0
#define GAME_STATE_PLAYER1_WIN 1
#define GAME_STATE_PLAYER2_WIN 2
#define GAME_STATE_TIE 3

// Define the winning combinations
int winning_combinations[8][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

// Define the game board
char game_board[BOARD_SIZE];

// Initialize the game board
void init_game_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        game_board[i] = ' ';
    }
}

// Print the game board
void print_game_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 3 == 0) {
            printf("+---+---+---+\n");
        }
        printf("| %c |", game_board[i]);
    }
    printf("+---+---+---+\n");
}

// Get the player's move
int get_player_move() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move - 1;
}

// Check if the move is valid
int is_valid_move(int move) {
    return move >= 0 && move < BOARD_SIZE && game_board[move] == ' ';
}

// Make the player's move
void make_move(int player, int move) {
    game_board[move] = player == 1 ? PLAYER1_SYMBOL : PLAYER2_SYMBOL;
}

// Check if the game is over
int is_game_over() {
    // Check for a win
    for (int i = 0; i < 8; i++) {
        if (game_board[winning_combinations[i][0]] == game_board[winning_combinations[i][1]] &&
            game_board[winning_combinations[i][1]] == game_board[winning_combinations[i][2]] &&
            game_board[winning_combinations[i][0]] != ' ') {
            return game_board[winning_combinations[i][0]] == PLAYER1_SYMBOL ? GAME_STATE_PLAYER1_WIN : GAME_STATE_PLAYER2_WIN;
        }
    }

    // Check for a tie
    int empty_cells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game_board[i] == ' ') {
            empty_cells++;
        }
    }
    if (empty_cells == 0) {
        return GAME_STATE_TIE;
    }

    // The game is still in progress
    return GAME_STATE_IN_PROGRESS;
}

// Play the game
void play_game() {
    int player = 1;
    int game_state = GAME_STATE_IN_PROGRESS;

    while (game_state == GAME_STATE_IN_PROGRESS) {
        print_game_board();
        int move = get_player_move();
        if (is_valid_move(move)) {
            make_move(player, move);
            game_state = is_game_over();
            player = player == 1 ? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    print_game_board();

    switch (game_state) {
        case GAME_STATE_PLAYER1_WIN:
            printf("Player 1 wins!\n");
            break;
        case GAME_STATE_PLAYER2_WIN:
            printf("Player 2 wins!\n");
            break;
        case GAME_STATE_TIE:
            printf("Tie game!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    init_game_board();
    play_game();
    return 0;
}