//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
enum GameState {
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    DRAW
};

// Initialize the game board
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the game is over
enum GameState check_game_over() {
    // Check for rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // Check for draw
    int empty_count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                empty_count++;
            }
        }
    }
    if (empty_count == 0) {
        return DRAW;
    }

    // Otherwise, the game is still playing
    return PLAYING;
}

// Get the player's move
int get_player_move(char player_symbol) {
    int move;
    printf("Player %c, enter your move (1-9): ", player_symbol);
    scanf("%d", &move);
    return move;
}

// Place the player's symbol on the board
void place_symbol(char player_symbol, int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player_symbol;
}

// Play the game
void play_game() {
    enum GameState game_state = PLAYING;
    char current_player_symbol = player1_symbol;

    while (game_state == PLAYING) {
        print_board();
        int move = get_player_move(current_player_symbol);
        place_symbol(current_player_symbol, move);
        game_state = check_game_over();
        current_player_symbol = current_player_symbol == player1_symbol ? player2_symbol : player1_symbol;
    }

    print_board();

    switch (game_state) {
        case PLAYER1_WIN:
            printf("Player 1 wins!\n");
            break;
        case PLAYER2_WIN:
            printf("Player 2 wins!\n");
            break;
        case DRAW:
            printf("It's a draw!\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    init_board();
    play_game();
    return 0;
}