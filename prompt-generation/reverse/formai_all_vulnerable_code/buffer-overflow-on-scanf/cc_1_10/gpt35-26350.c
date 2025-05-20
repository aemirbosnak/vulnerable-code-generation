//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the game board and the number of winning sequences
#define BOARD_SIZE 3
#define NUM_WIN_SEQUENCES 8

// Global variables to hold the game board and winning sequences
char board[BOARD_SIZE][BOARD_SIZE];
int win_sequences[NUM_WIN_SEQUENCES][BOARD_SIZE][2] = {
    {{0,0}, {0,1}, {0,2}}, // Top row
    {{1,0}, {1,1}, {1,2}}, // Middle row
    {{2,0}, {2,1}, {2,2}}, // Bottom row
    {{0,0}, {1,0}, {2,0}}, // Left column
    {{0,1}, {1,1}, {2,1}}, // Middle column
    {{0,2}, {1,2}, {2,2}}, // Right column
    {{0,0}, {1,1}, {2,2}}, // Diagonal from top left to bottom right
    {{0,2}, {1,1}, {2,0}} // Diagonal from top right to bottom left
};

// Function to print out the game board
void print_board() {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won the game
int has_won(char player) {
    for(int i = 0; i < NUM_WIN_SEQUENCES; i++) {
        int count = 0;
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[win_sequences[i][j][0]][win_sequences[i][j][1]] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }
    return 0;
}

// Function to get the player's move
void player_move(char player) {
    int row, col;
    printf("Enter your move (row, column) for player %c:", player);
    scanf("%d %d", &row, &col);
    while(board[row][col] != '_') {
        printf("That spot is already taken. Please pick a different spot.\n");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = player;
}

// Function for the AI to make its move
void ai_move(char player) {
    int row, col;
    srand(time(NULL));
    row = rand() % 3;
    col = rand() % 3;
    while(board[row][col] != '_') {
        row = rand() % 3;
        col = rand() % 3;
    }
    printf("AI has chosen its move.\n");
    board[row][col] = player;
}

int main() {
    char player1 = 'X';
    char player2 = 'O';
    int round = 1;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '_';
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    print_board();
    while(round <= 9) {
        if(round % 2 != 0) {
            player_move(player1);
        } else {
            ai_move(player2);
        }
        print_board();
        if(has_won(player1)) {
            printf("Player %c has won the game!\n", player1);
            return 0;
        } else if(has_won(player2)) {
            printf("Player %c has won the game!\n", player2);
            return 0;
        }
        round++;
    }
    printf("It's a tie game!\n");
    return 0;
}