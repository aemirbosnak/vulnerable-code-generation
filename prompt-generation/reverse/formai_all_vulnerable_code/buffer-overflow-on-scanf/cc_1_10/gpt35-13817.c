//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DEBUG

typedef enum {PLAYER, COMPUTER} player;

char board[3][3];
int moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char player_markers[2] = {'X', 'O'};
int computer_marker;
player current_player = PLAYER;

// Function to draw the board
void draw_board() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf("\t\t\t\t   %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i != 2) printf("\t\t\t\t  ---|---|---\n");
    }
    printf("\n");
}

// Function to randomly select the computer's move
int get_random_move(int n) {

    // If there's only one available move, return it
    if(n == 1) return moves[0];

    // Otherwise, randomly select a move from the available moves 
    int index = rand() % n;
    int move = moves[index];

    // Remove the selected move from the available moves array
    moves[index] = moves[n-1];

    return move;
}

// Function to check if the given marker has won
int has_won(char marker) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) return 1;
    }
    // Check columns
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == marker && board[1][j] == marker && board[2][j] == marker) return 1;
    }
    // Check diagonals
    if(board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) return 1;
    if(board[2][0] == marker && board[1][1] == marker && board[0][2] == marker) return 1;

    return 0;
}

// Function to check if the game is over
int is_game_over() {

    // Check for a tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to get the computer's move
int get_computer_move() {
    
    #ifdef DEBUG
    printf("\nComputer's turn | Available moves: ");
    for(int i = 0; i < 9; i++) printf("%d ", moves[i]);
    printf("\n\n");
    #endif

    // Check if the computer can win on the next move
    for(int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if(board[row][col] == ' ') {
            board[row][col] = computer_marker;
            if(has_won(computer_marker)) {
                board[row][col] = ' ';
                return i;
            }
            board[row][col] = ' ';
        }
    }

    // Check if the player can win on the next move and block them
    for(int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if(board[row][col] == ' ') {
            board[row][col] = player_markers[PLAYER];
            if(has_won(player_markers[PLAYER])) {
                board[row][col] = ' ';
                return i;
            }
            board[row][col] = ' ';
        }
    }

    // Otherwise, make a random move
    return get_random_move(9);
}

// Function to get the player's move
int get_player_move() {
    int move;

    // Prompt the user to enter a valid move
    while(1) {
        printf("Enter your move (0-8): ");
        scanf("%d", &move);

        if(move < 0 || move > 8 || board[move/3][move%3] != ' ') {
            printf("Invalid move. Please try again.\n");
        } else {
            break;
        }
    }

    return move;
}

int main() {

    // Initialize the board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Randomly select who goes first
    srand(time(NULL));
    if(rand() % 2 == 0) {
        printf("You go first.\n\n");
        current_player = PLAYER;
    } else {
        printf("The computer goes first.\n\n");
        current_player = COMPUTER;
    }

    // Set the computer's marker
    computer_marker = (player_markers[current_player] == 'X') ? 'O' : 'X';

    // Play the game
    while(!is_game_over()) {
        
        if(current_player == PLAYER) {
            draw_board();
            int move = get_player_move();
            board[move/3][move%3] = player_markers[current_player];
            current_player = COMPUTER;
        } else {
            printf("The computer is thinking...\n");
            int move = get_computer_move();
            board[move/3][move%3] = computer_marker;
            current_player = PLAYER;
        }
    }

    // Draw the final board
    draw_board();

    // Print the final result
    if(has_won(player_markers[PLAYER])) {
        printf("Congratulations! You won!\n");
    } else if(has_won(computer_marker)) {
        printf("The computer won. Better luck next time!\n");
    } else {
        printf("The game ended in a tie!\n");
    }

    return 0;
}