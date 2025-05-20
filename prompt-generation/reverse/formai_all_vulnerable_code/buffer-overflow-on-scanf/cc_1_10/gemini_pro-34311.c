//GEMINI-pro DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

// Define the game state
#define STATE_PLAYING 0
#define STATE_X_WIN 1
#define STATE_O_WIN 2
#define STATE_TIE 3

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
char board[BOARD_SIZE * BOARD_SIZE];

// Define the current player
char current_player = PLAYER_X;

// Define the game state
int game_state = STATE_PLAYING;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        board[i] = EMPTY;
    }
}

// Print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i * BOARD_SIZE + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Get the player's move
int get_move() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move - 1;
}

// Make a move
void make_move(int move) {
    board[move] = current_player;
}

// Check if the game is over
int check_game_over() {
    // Check if there is a winner
    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0]] == current_player &&
            board[winning_combinations[i][1]] == current_player &&
            board[winning_combinations[i][2]] == current_player) {
            return current_player == PLAYER_X ? STATE_X_WIN : STATE_O_WIN;
        }
    }

    // Check if there is a tie
    int empty_count = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board[i] == EMPTY) {
            empty_count++;
        }
    }
    if (empty_count == 0) {
        return STATE_TIE;
    }

    return STATE_PLAYING;
}

// Switch the current player
void switch_player() {
    current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
}

// Play the game
void play_game() {
    init_board();
    print_board();

    while (game_state == STATE_PLAYING) {
        int move = get_move();
        make_move(move);
        print_board();

        game_state = check_game_over();
        switch_player();
    }

    if (game_state == STATE_X_WIN) {
        printf("Player X wins!\n");
    } else if (game_state == STATE_O_WIN) {
        printf("Player O wins!\n");
    } else if (game_state == STATE_TIE) {
        printf("Tie!\n");
    }
}

int main() {
    srand(time(NULL));
    play_game();

    return 0;
}