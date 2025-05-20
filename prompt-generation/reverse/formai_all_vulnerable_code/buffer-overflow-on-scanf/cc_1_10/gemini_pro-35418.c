//GEMINI-pro DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 4
int board[BOARD_SIZE][BOARD_SIZE];

// Define the player types
#define PLAYER_X 1
#define PLAYER_O 2

// Define the game states
#define GAME_PLAYING 1
#define GAME_OVER 2
#define GAME_DRAW 3

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

// Function to initialize the game board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("   ");
            } else if (board[i][j] == PLAYER_X) {
                printf(" X ");
            } else if (board[i][j] == PLAYER_O) {
                printf(" O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a player has won
int check_win(int player) {
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
            return 1;
        }
    }
    return 0;
}

// Function to check if the game is a draw
int check_draw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the player's move
int get_move(int player) {
    int move;
    while (1) {
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &move);
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / BOARD_SIZE;
            int col = (move - 1) % BOARD_SIZE;
            if (board[row][col] == 0) {
                return move;
            } else {
                printf("Invalid move. Please try again.\n");
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

// Function to play the game
void play_game() {
    int game_state = GAME_PLAYING;
    int current_player = PLAYER_X;

    initialize_board();

    while (game_state == GAME_PLAYING) {
        print_board();

        int move = get_move(current_player);

        int row = (move - 1) / BOARD_SIZE;
        int col = (move - 1) % BOARD_SIZE;

        board[row][col] = current_player;

        if (check_win(current_player)) {
            game_state = GAME_OVER;
            printf("Player %d wins!\n", current_player);
        } else if (check_draw()) {
            game_state = GAME_DRAW;
            printf("The game is a draw.\n");
        } else {
            current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));

    play_game();

    return 0;
}