//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Board dimensions
#define BOARD_SIZE 3

// Possible moves
#define EMPTY 0
#define X 1
#define O 2

// Player types
#define HUMAN 0
#define AI 1

// Game state
#define IN_PROGRESS 0
#define DRAW 1
#define X_WINS 2
#define O_WINS 3

// Function prototypes
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int check_winner(int board[BOARD_SIZE][BOARD_SIZE]);
int make_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int x, int y);
int ai_move(int board[BOARD_SIZE][BOARD_SIZE], int player);

// Main function
int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    int board[BOARD_SIZE][BOARD_SIZE] = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    };

    // Game loop
    int game_state = IN_PROGRESS;
    int current_player = HUMAN;
    while (game_state == IN_PROGRESS) {
        // Print the board
        print_board(board);

        // Get the player's move
        int x, y;
        if (current_player == HUMAN) {
            printf("Your move (x, y): ");
            scanf("%d %d", &x, &y);
        } else {
            // Make the AI's move
            x = ai_move(board, current_player);
            y = ai_move(board, current_player);
        }

        // Make the move
        int move_result = make_move(board, current_player, x, y);

        // Check the game state
        game_state = check_winner(board);

        // Switch players
        current_player = (current_player + 1) % 2;
    }

    // Print the final board
    print_board(board);

    // Print the game state
    switch (game_state) {
        case DRAW:
            printf("Draw!\n");
            break;
        case X_WINS:
            printf("X wins!\n");
            break;
        case O_WINS:
           printf("O wins!\n");
           break;
    }

    return 0;
}

// Function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case X:
                    printf("X");
                    break;
                case O:
                    printf("O");
                    break;
            }
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

// Function to check the winner
int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for draw
    int empty_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                empty_count++;
            }
        }
    }
    if (empty_count == 0) {
        return DRAW;
    }

    // No winner yet
    return IN_PROGRESS;
}

// Function to make a move
int make_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int x, int y) {
    // Check if the move is valid
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != EMPTY) {
        return -1;
    }

    // Make the move
    board[x][y] = player;

    return 0;
}

// Function to make the AI's move
int ai_move(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    // Get a list of all possible moves
    int possible_moves[BOARD_SIZE * BOARD_SIZE];
    int num_possible_moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                possible_moves[num_possible_moves++] = i * BOARD_SIZE + j;
            }
        }
    }

    // Choose a random move
    int move_index = rand() % num_possible_moves;
    int move = possible_moves[move_index];

    return move;
}