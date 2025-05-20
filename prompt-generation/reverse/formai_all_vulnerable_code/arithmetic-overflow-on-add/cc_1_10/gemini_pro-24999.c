//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 8

// Define the player types
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
#define GAME_IN_PROGRESS 0
#define GAME_OVER_X_WIN 1
#define GAME_OVER_O_WIN 2
#define GAME_OVER_TIE 3

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the current player
char current_player = PLAYER_X;

// Define the game state
int game_state = GAME_IN_PROGRESS;

// Declare the function prototypes
void initialize_board();
void print_board();
int get_player_move();
int is_valid_move(int row, int col);
void make_move(int row, int col);
int check_game_state();
void declare_winner();

// Define the main function
int main() {
    // Initialize the board
    initialize_board();

    // Print the board
    print_board();

    // Get the first player's move
    int player_move = get_player_move();

    // Make the first player's move
    make_move(player_move / BOARD_SIZE, player_move % BOARD_SIZE);

    // Print the board
    print_board();

    // Continue playing the game until it is over
    while (game_state == GAME_IN_PROGRESS) {
        // Get the current player's move
        player_move = get_player_move();

        // Make the current player's move
        make_move(player_move / BOARD_SIZE, player_move % BOARD_SIZE);

        // Print the board
        print_board();

        // Check the game state
        game_state = check_game_state();
    }

    // Declare the winner
    declare_winner();

    return 0;
}

// Define the function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Define the function to print the board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Define the function to get the player's move
int get_player_move() {
    int row, col;

    printf("Enter the row and column of your move (e.g., 1 2): ");
    scanf("%d %d", &row, &col);

    return row * BOARD_SIZE + col;
}

// Define the function to check if a move is valid
int is_valid_move(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

// Define the function to make a move
void make_move(int row, int col) {
    board[row][col] = current_player;

    // Switch the current player
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

// Define the function to check the game state
int check_game_state() {
    // Check if there is a winner
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check for a winner in each row
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == PLAYER_X) ? GAME_OVER_X_WIN : GAME_OVER_O_WIN;
        }

        // Check for a winner in each column
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == PLAYER_X) ? GAME_OVER_X_WIN : GAME_OVER_O_WIN;
        }
    }

    // Check for a winner in each diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == PLAYER_X) ? GAME_OVER_X_WIN : GAME_OVER_O_WIN;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == PLAYER_X) ? GAME_OVER_X_WIN : GAME_OVER_O_WIN;
    }

    // Check if there is a tie
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return GAME_IN_PROGRESS;
            }
        }
    }

    return GAME_OVER_TIE;
}

// Define the function to declare the winner
void declare_winner() {
    switch (game_state) {
        case GAME_OVER_X_WIN:
            printf("Player X wins!\n");
            break;
        case GAME_OVER_O_WIN:
            printf("Player O wins!\n");
            break;
        case GAME_OVER_TIE:
            printf("The game is a tie!\n");
            break;
    }
}