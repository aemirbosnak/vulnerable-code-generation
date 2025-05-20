//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Board dimensions
#define BOARD_SIZE 3

// Player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Game state
typedef enum {
    IN_PROGRESS,
    PLAYER_X_WIN,
    PLAYER_O_WIN,
    TIE
} GameState;

// Game board
char board[BOARD_SIZE][BOARD_SIZE];

// Function to check for a win
GameState check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER_X) {
                return PLAYER_X_WIN;
            } else if (board[i][0] == PLAYER_O) {
                return PLAYER_O_WIN;
            }
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == PLAYER_X) {
                return PLAYER_X_WIN;
            } else if (board[0][j] == PLAYER_O) {
                return PLAYER_O_WIN;
            }
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == PLAYER_X) {
            return PLAYER_X_WIN;
        } else if (board[0][0] == PLAYER_O) {
            return PLAYER_O_WIN;
        }
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == PLAYER_X) {
            return PLAYER_X_WIN;
        } else if (board[0][2] == PLAYER_O) {
            return PLAYER_O_WIN;
        }
    }

    // Check for a tie
    int empty_cells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                empty_cells++;
            }
        }
    }

    if (empty_cells == 0) {
        return TIE;
    }

    // Game is still in progress
    return IN_PROGRESS;
}

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the player's move
int get_player_move(char player_symbol) {
    int move;

    printf("Enter your move (%c): ", player_symbol);
    scanf("%d", &move);

    return move;
}

// Function to make a move
void make_move(int move, char player_symbol) {
    int row = move / 3;
    int col = move % 3;

    board[row][col] = player_symbol;
}

// Function to check if a move is valid
int is_valid_move(int move) {
    int row = move / 3;
    int col = move % 3;

    return board[row][col] == ' ';
}

// Function to play the game
void play_game() {
    // Initialize game state
    GameState state = IN_PROGRESS;

    // Initialize player turn
    char player_turn = PLAYER_X;

    // Game loop
    while (state == IN_PROGRESS) {
        // Print the game board
        print_board();

        // Get the player's move
        int move = get_player_move(player_turn);

        // Check if the move is valid
        while (!is_valid_move(move)) {
            printf("Invalid move. Try again.\n");
            move = get_player_move(player_turn);
        }

        // Make the move
        make_move(move, player_turn);

        // Check for a win
        state = check_win();

        // Switch player turn
        if (player_turn == PLAYER_X) {
            player_turn = PLAYER_O;
        } else {
            player_turn = PLAYER_X;
        }
    }

    // Print the game board
    print_board();

    // Announce the winner
    switch (state) {
        case PLAYER_X_WIN:
            printf("Player X wins!\n");
            break;
        case PLAYER_O_WIN:
            printf("Player O wins!\n");
            break;
        case TIE:
            printf("Tie!\n");
            break;
    }
}

int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Play the game
    play_game();

    return 0;
}