//GEMINI-pro DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 4

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

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

// Function to initialize the game board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
enum GameState check_game_over() {
    // Check for horizontal wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return board[i][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j]) {
            return board[0][j] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for diagonal wins
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return board[0][0] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }
    if (board[0][3] != ' ' && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return board[0][3] == player1_symbol ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // Check for draw
    int num_empty_cells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                num_empty_cells++;
            }
        }
    }
    if (num_empty_cells == 0) {
        return DRAW;
    }

    // Game is still playing
    return PLAYING;
}

// Function to get the player's move
int get_player_move(char player_symbol) {
    int move;
    while (1) {
        printf("Player %c, enter your move (1-9): ", player_symbol);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
        } else if (board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] != ' ') {
            printf("That cell is already occupied. Please enter another move.\n");
        } else {
            return move;
        }
    }
}

// Function to make a move on the game board
void make_move(int move, char player_symbol) {
    board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = player_symbol;
}

// Function to play the game
void play_game() {
    // Initialize the game board
    initialize_board();

    // Print the game board
    print_board();

    // Get the first player's move
    int move = get_player_move(player1_symbol);

    // Make the move on the game board
    make_move(move, player1_symbol);

    // Print the game board
    print_board();

    // Check if the game is over
    enum GameState game_state = check_game_over();

    // While the game is still playing
    while (game_state == PLAYING) {
        // Get the second player's move
        move = get_player_move(player2_symbol);

        // Make the move on the game board
        make_move(move, player2_symbol);

        // Print the game board
        print_board();

        // Check if the game is over
        game_state = check_game_over();
    }

    // Print the game result
    switch (game_state) {
        case PLAYER1_WIN:
            printf("Player 1 wins!\n");
            break;
        case PLAYER2_WIN:
            printf("Player 2 wins!\n");
            break;
        case DRAW:
            printf("Draw!\n");
            break;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}