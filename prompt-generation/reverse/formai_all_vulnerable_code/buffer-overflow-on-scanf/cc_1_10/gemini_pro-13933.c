//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Game board dimensions
#define ROWS 6
#define COLS 7

// Player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Game state
typedef enum {
    PLAYING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    TIE
} GameState;

// Game board
char board[ROWS][COLS];

// Current player
char current_player = PLAYER_1;

// Function to initialize the game board
void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void print_board() {
    printf("  1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  - - - - - - - -\n");
}

// Function to check if a move is valid
int is_valid_move(int col) {
    return col >= 1 && col <= COLS && board[0][col - 1] == ' ';
}

// Function to make a move
void make_move(int col) {
    int row = ROWS - 1;
    while (board[row][col - 1] != ' ' && row >= 0) {
        row--;
    }
    if (row >= 0) {
        board[row][col - 1] = current_player;
    }
}

// Function to check if there is a winner
GameState check_winner() {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][2] == board[i][3]) {
            return current_player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j] &&
            board[2][j] == board[3][j]) {
            return current_player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[2][2] == board[3][3]) {
        return current_player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }

    if (board[0][3] != ' ' &&
        board[0][3] == board[1][2] &&
        board[1][2] == board[2][1] &&
        board[2][1] == board[3][0]) {
        return current_player == PLAYER_1 ? PLAYER_1_WINS : PLAYER_2_WINS;
    }

    // Check for a tie
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == ROWS * COLS) {
        return TIE;
    }

    return PLAYING;
}

// Function to switch players
void switch_player() {
    current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

// Main game loop
void play_game() {
    int col;
    GameState state;

    init_board();
    print_board();

    while (state == PLAYING) {
        printf("%c's turn: ", current_player);
        scanf("%d", &col);
        if (!is_valid_move(col)) {
            printf("Invalid move. Try again.\n");
        } else {
            make_move(col);
            print_board();
            state = check_winner();
            switch_player();
        }
    }

    if (state == PLAYER_1_WINS) {
        printf("Player 1 wins!\n");
    } else if (state == PLAYER_2_WINS) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int main() {
    play_game();

    return 0;
}