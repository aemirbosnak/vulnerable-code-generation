//GEMINI-pro DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 8

// Define the number of players
#define NUM_PLAYERS 2

// Define the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player pieces
char player_pieces[NUM_PLAYERS] = {'X', 'O'};

// Define the game state
enum game_state {
    GAME_IN_PROGRESS,
    GAME_PLAYER_1_WIN,
    GAME_PLAYER_2_WIN,
    GAME_DRAW
};

// Define the game functions
void initialize_board();
void print_board();
int check_winner();
void make_move(int player, int row, int col);

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Initialize the game board
    initialize_board();

    // Print the game board
    print_board();

    // Game loop
    while (1) {
        // Get the current player
        int player = rand() % NUM_PLAYERS;

        // Get the player's move
        int row, col;
        printf("Player %d, enter your move (row, col): ", player + 1);
        scanf("%d %d", &row, &col);

        // Make the player's move
        make_move(player, row, col);

        // Print the game board
        print_board();

        // Check for a winner
        int winner = check_winner();
        if (winner != GAME_IN_PROGRESS) {
            if (winner == GAME_PLAYER_1_WIN) {
                printf("Player 1 wins!\n");
            } else if (winner == GAME_PLAYER_2_WIN) {
                printf("Player 2 wins!\n");
            } else {
                printf("Draw!\n");
            }
            break;
        }
    }

    return 0;
}

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() {
    // Check for a winner in each row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? GAME_PLAYER_1_WIN : GAME_PLAYER_2_WIN;
        }
    }

    // Check for a winner in each column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == 'X' ? GAME_PLAYER_1_WIN : GAME_PLAYER_2_WIN;
        }
    }

    // Check for a winner in each diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? GAME_PLAYER_1_WIN : GAME_PLAYER_2_WIN;
    }
    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return board[2][0] == 'X' ? GAME_PLAYER_1_WIN : GAME_PLAYER_2_WIN;
    }

    // Check for a draw
    int num_empty_cells = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                num_empty_cells++;
            }
        }
    }
    if (num_empty_cells == 0) {
        return GAME_DRAW;
    }

    // No winner or draw yet
    return GAME_IN_PROGRESS;
}

void make_move(int player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player_pieces[player];
    } else {
        printf("Invalid move!\n");
    }
}