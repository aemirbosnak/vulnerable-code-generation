//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>

//The board size
#define BOARD_SIZE 3

//The available spots on the board
#define EMPTY '-'
#define PLAYER_TOKEN 'X'
#define AI_TOKEN 'O'

//The positions on the board
#define ROW 0
#define COLUMN 1

//The message to display when the game starts
char* WELCOME_MESSAGE = "Welcome to Tic Tac Toe!";

//The board structure
char board[BOARD_SIZE][BOARD_SIZE];

//Function to display the board
void display_board() {
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf(" %c ", board[row][col]);
            if (col < BOARD_SIZE-1) {
                printf("|");
            }
        }
        printf("\n");
        if (row < BOARD_SIZE-1) {
            printf("-----------\n");
        }
    }
}

//Function to check if the game is over
int is_game_over() {
    // Check if the board is full
    int is_full = 1;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                is_full = 0;
                break;
            }
        }
    }
    if (is_full) {
        return 1;
    }

    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != EMPTY) {
            return 1;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != EMPTY) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY) {
        return 1;
    }

    // Game is not over
    return 0;
}

//Function to make a move
void make_move(char token, int row, int col) {
    board[row][col] = token;
    display_board();
}

//Function to get the best move for the AI
void get_best_move() {
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                board[row][col] = AI_TOKEN;
                if (!is_game_over()) {
                    make_move(AI_TOKEN, row, col);
                    return;
                }
                board[row][col] = EMPTY;
            }
        }
    }

    // If we get here, there are no moves left
    printf("It's a tie!");
}

int main() {
    printf("%s\n", WELCOME_MESSAGE);

    // Initialize the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }
    display_board();

    // The game loop
    while (!is_game_over()) {
        // Player's turn
        int player_row, player_col;
        printf("Enter row (0-%d) and column (0-%d) to place your token: ", BOARD_SIZE-1, BOARD_SIZE-1);
        scanf("%d %d", &player_row, &player_col);
        if (board[player_row][player_col] != EMPTY) {
            printf("That spot is already taken! Try again.\n");
        } else {
            make_move(PLAYER_TOKEN, player_row, player_col);
        }

        // Check if the game is over
        if (is_game_over()) {
            break;
        }

        // AI's turn
        printf("AI's turn:\n");
        get_best_move();
    }

    return 0;
}