//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 10

// Define the player symbols
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define the game state
#define STATE_PLAYING 0
#define STATE_PLAYER_1_WIN 1
#define STATE_PLAYER_2_WIN 2
#define STATE_DRAW 3

// Define the AI difficulty levels
#define AI_EASY 0
#define AI_MEDIUM 1
#define AI_HARD 2

// Declare the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Declare the game state
int state = STATE_PLAYING;

// Declare the current player
char current_player = PLAYER_1;

// Declare the AI difficulty
int ai_difficulty = AI_EASY;

// Function to initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

// Function to make a move
void make_move(int row, int col) {
    board[row][col] = current_player;
}

// Function to check if a player has won
int check_win() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player == PLAYER_1 ? STATE_PLAYER_1_WIN : STATE_PLAYER_2_WIN;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return current_player == PLAYER_1 ? STATE_PLAYER_1_WIN : STATE_PLAYER_2_WIN;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player == PLAYER_1 ? STATE_PLAYER_1_WIN : STATE_PLAYER_2_WIN;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player == PLAYER_1 ? STATE_PLAYER_1_WIN : STATE_PLAYER_2_WIN;
    }

    // Check draw
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }

    if (count == BOARD_SIZE * BOARD_SIZE) {
        return STATE_DRAW;
    }

    return STATE_PLAYING;
}

// Function to get the AI move
int get_ai_move(int difficulty) {
    int row, col;

    // Easy AI
    if (difficulty == AI_EASY) {
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (!is_valid_move(row, col));
    }

    // Medium AI
    else if (difficulty == AI_MEDIUM) {
        // Check if there is a winning move
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (is_valid_move(i, j)) {
                    board[i][j] = current_player;
                    if (check_win() == (current_player == PLAYER_1 ? STATE_PLAYER_1_WIN : STATE_PLAYER_2_WIN)) {
                        row = i;
                        col = j;
                        board[i][j] = ' ';
                        return row * BOARD_SIZE + col;
                    }
                    board[i][j] = ' ';
                }
            }
        }

        // Check if there is a blocking move
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (is_valid_move(i, j)) {
                    board[i][j] = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
                    if (check_win() == (current_player == PLAYER_1 ? STATE_PLAYER_2_WIN : STATE_PLAYER_1_WIN)) {
                        row = i;
                        col = j;
                        board[i][j] = ' ';
                        return row * BOARD_SIZE + col;
                    }
                    board[i][j] = ' ';
                }
            }
        }

        // Otherwise, make a random move
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (!is_valid_move(row, col));
    }

    // Hard AI
    else if (difficulty == AI_HARD) {
        // TODO: Implement hard AI
        do {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        } while (!is_valid_move(row, col));
    }

    return row * BOARD_SIZE + col;
}

// Function to play the game
void play_game() {
    // Initialize the game board
    init_board();

    // Print the game board
    print_board();

    while (state == STATE_PLAYING) {
        // Get the player's move
        int row, col;
        if (current_player == PLAYER_1) {
            printf("Player 1, enter your move (row, col): ");
            scanf("%d %d", &row, &col);
        } else {
            int move = get_ai_move(ai_difficulty);
            row = move / BOARD_SIZE;
            col = move % BOARD_SIZE;
        }

        // Check if the move is valid
        if (!is_valid_move(row, col)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move
        make_move(row, col);

        // Print the game board
        print_board();

        // Check if the game is over
        state = check_win();

        // Switch to the other player
        current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }

    // Print the game over message
    if (state == STATE_PLAYER_1_WIN) {
        printf("Player 1 wins!\n");
    } else if (state == STATE_PLAYER_2_WIN) {
        printf("Player 2 wins!\n");
    } else if (state == STATE_DRAW) {
        printf("Draw!\n");
    }
}

// Main function
int main() {
    // Set the AI difficulty
    printf("Enter the AI difficulty (0-2): ");
    scanf("%d", &ai_difficulty);

    // Play the game
    play_game();

    return 0;
}