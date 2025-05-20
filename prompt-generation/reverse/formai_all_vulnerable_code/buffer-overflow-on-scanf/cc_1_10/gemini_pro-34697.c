//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
// Introspective Tic Tac Toe AI in C

#include <stdio.h>
#include <stdlib.h>

// Define the board and player symbols
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE];
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

// Function to initialize the board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Function to print the board
void print_board() {
    printf("Current board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_win(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to check if the board is full
int check_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get the best move for the AI
int get_best_move(char player) {
    // I should think a little more strategically...

    // Check if there is a winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = player;
                if (check_win(player)) {
                    board[i][j] = EMPTY;  // I should not change the board state in this function
                    return i * BOARD_SIZE + j;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // Check if there is a blocking move
    char opponent = player == PLAYER_X ? PLAYER_O : PLAYER_X;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = opponent;
                if (check_win(opponent)) {
                    board[i][j] = EMPTY;
                    return i * BOARD_SIZE + j;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // If there is no winning or blocking move, choose a random empty cell
    int index;
    do {
        index = rand() % (BOARD_SIZE * BOARD_SIZE);
    } while (board[index / BOARD_SIZE][index % BOARD_SIZE] != EMPTY);

    return index;
}

// Main game loop
int main() {
    char player = PLAYER_X;

    // Initialize the board
    init_board();

    // Main game loop
    while (!check_win(PLAYER_X) && !check_win(PLAYER_O) && !check_full()) {
        if (player == PLAYER_X) {
            printf("Human's turn:\n");
            int move;
            scanf("%d", &move);
            if (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY) {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_X;
        } else {
            printf("AI's turn:\n");
            int move = get_best_move(PLAYER_O);
            board[move / BOARD_SIZE][move % BOARD_SIZE] = PLAYER_O;
        }

        print_board();
        player = player == PLAYER_X ? PLAYER_O : PLAYER_X;
    }

    // Check the game result
    if (check_win(PLAYER_X)) {
        printf("Human wins!\n");
    } else if (check_win(PLAYER_O)) {
        printf("AI wins!\n");
    } else {
        printf("Draw!\n");
    }

    return 0;
}