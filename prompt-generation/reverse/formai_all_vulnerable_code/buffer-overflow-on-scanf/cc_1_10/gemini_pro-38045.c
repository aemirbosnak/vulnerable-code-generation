//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 10

// Define the player symbol
#define PLAYER_SYMBOL 'X'

// Define the computer symbol
#define COMPUTER_SYMBOL 'O'

// Define the empty symbol
#define EMPTY_SYMBOL ' '

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

// Define the game board
char board[BOARD_SIZE];

// Function to initialize the game board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = EMPTY_SYMBOL;
    }
}

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i % 3 == 0) {
            printf("\n");
        }
        printf(" %c |", board[i]);
    }
    printf("\n");
}

// Function to check if a player has won
int check_win(char symbol) {
    for (int i = 0; i < 8; i++) {
        if (board[winning_combinations[i][0]] == symbol &&
            board[winning_combinations[i][1]] == symbol &&
            board[winning_combinations[i][2]] == symbol) {
            return 1;
        }
    }
    return 0;
}

// Function to get the player's move
int get_player_move() {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    return move - 1;
}

// Function to make a move on the board
void make_move(int move, char symbol) {
    board[move] = symbol;
}

// Function to get the computer's move
int get_computer_move() {
    srand(time(NULL));
    int move;
    do {
        move = rand() % BOARD_SIZE;
    } while (board[move] != EMPTY_SYMBOL);
    return move;
}

// Function to play the game
void play_game() {
    int turn = 0; // 0 = player, 1 = computer
    int winner = 0; // 0 = no winner, 1 = player, 2 = computer

    initialize_board();

    while (!winner) {
        if (turn == 0) {
            int move = get_player_move();
            make_move(move, PLAYER_SYMBOL);
            winner = check_win(PLAYER_SYMBOL);
        } else {
            int move = get_computer_move();
            make_move(move, COMPUTER_SYMBOL);
            winner = check_win(COMPUTER_SYMBOL);
        }
        print_board();
        turn = (turn + 1) % 2;
    }

    if (winner == 1) {
        printf("Player wins!\n");
    } else if (winner == 2) {
        printf("Computer wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int main() {
    play_game();
    return 0;
}