//GEMINI-pro DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Define the game states
#define STATE_PLAYING 0
#define STATE_PLAYER1_WIN 1
#define STATE_PLAYER2_WIN 2
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

// Print the game board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won
int check_win(char player) {
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            int row = winning_combinations[i][j] / BOARD_SIZE;
            int col = winning_combinations[i][j] % BOARD_SIZE;
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == 3) {
            return player == PLAYER1 ? STATE_PLAYER1_WIN : STATE_PLAYER2_WIN;
        }
    }
    return STATE_PLAYING;
}

// Check if the game is a tie
int check_tie() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return STATE_PLAYING;
            }
        }
    }
    return STATE_TIE;
}

// Get the player's move
int get_move(char player) {
    int move;
    while (1) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);
        move--; // Convert to 0-based index
        if (move >= 0 && move < BOARD_SIZE * BOARD_SIZE && board[move / BOARD_SIZE][move % BOARD_SIZE] == ' ') {
            return move;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

// Play the game
int play_game() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Determine which player starts first
    srand(time(NULL));
    char player = rand() % 2 == 0 ? PLAYER1 : PLAYER2;

    // Main game loop
    while (1) {
        // Print the game board
        print_board();

        // Get the player's move
        int move = get_move(player);

        // Place the player's symbol on the board
        int row = move / BOARD_SIZE;
        int col = move % BOARD_SIZE;
        board[row][col] = player;

        // Check if the game is over
        int state = check_win(player);
        if (state == STATE_PLAYER1_WIN || state == STATE_PLAYER2_WIN) {
            // A player has won
            return state;
        } else if (state == STATE_TIE) {
            // The game is a tie
            return STATE_TIE;
        }

        // Switch to the other player
        player = player == PLAYER1 ? PLAYER2 : PLAYER1;
    }
}

// Main function
int main() {
    // Play the game
    int state = play_game();

    // Print the game result
    if (state == STATE_PLAYER1_WIN) {
        printf("Player 1 wins!\n");
    } else if (state == STATE_PLAYER2_WIN) {
        printf("Player 2 wins!\n");
    } else if (state == STATE_TIE) {
        printf("Tie game!\n");
    }

    return 0;
}