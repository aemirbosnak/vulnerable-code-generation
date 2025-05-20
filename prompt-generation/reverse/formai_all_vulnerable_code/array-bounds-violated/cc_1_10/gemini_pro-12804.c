//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size and player symbols
#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Declare the game board
char board[BOARD_SIZE][BOARD_SIZE];

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
            printf("| %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over
int is_game_over() {
    // Check for a winning row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check for a winning column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check for a winning diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check for a tie
    int tie = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                tie = 0;
            }
        }
    }
    if (tie) {
        return 2;
    }

    // Game is not over
    return 0;
}

// Function to get the player's move
int get_player_move() {
    int row, column;

    printf("Enter your move (row, column): ");
    scanf("%d %d", &row, &column);

    while (row < 1 || row > BOARD_SIZE || column < 1 || column > BOARD_SIZE || board[row-1][column-1] != ' ') {
        printf("Invalid move. Try again: ");
        scanf("%d %d", &row, &column);
    }

    return row*10 + column;
}

// Function to get the AI's move
int get_ai_move() {
    // Check for a winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_O;
                if (is_game_over() == 1) {
                    board[i][j] = ' ';
                    return (i+1)*10 + (j+1);
                }
                board[i][j] = ' ';
            }
        }
    }

    // Check for a blocking move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER_X;
                if (is_game_over() == 1) {
                    board[i][j] = ' ';
                    return (i+1)*10 + (j+1);
                }
                board[i][j] = ' ';
            }
        }
    }

    // Choose a random move
    srand(time(NULL));
    int move;
    do {
        move = rand() % (BOARD_SIZE * BOARD_SIZE) + 1;
    } while (board[(move-1)/10][(move-1)%10] != ' ');

    return move;
}

// Function to play the game
void play_game() {
    initialize_board();

    int player_turn = 1;  // 1 for player, 2 for AI
    int game_over = 0;

    while (!game_over) {
        if (player_turn == 1) {
            int move = get_player_move();
            board[(move-1)/10][(move-1)%10] = PLAYER_X;
            player_turn = 2;
        } else {
            int move = get_ai_move();
            board[(move-1)/10][(move-1)%10] = PLAYER_O;
            player_turn = 1;
        }

        print_board();

        game_over = is_game_over();
    }

    if (game_over == 1) {
        if (player_turn == 2) {
            printf("Player X wins!\n");
        } else {
            printf("AI wins!\n");
        }
    } else {
        printf("Tie!\n");
    }
}

int main() {
    play_game();

    return 0;
}