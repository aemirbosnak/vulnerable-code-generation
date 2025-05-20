//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 3 // Set the size of the board to 3

char board[BOARD_SIZE][BOARD_SIZE]; // Create the board array

void setup_board() {
    // Initialize the board with empty spaces
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

bool is_valid_move(int x, int y) {
    // Check if the move is within the bounds of the board
    if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false;
    }
    
    // Check if the move is on an empty square
    if(board[x][y] != ' ') {
        return false;
    }
    
    return true;
}

bool check_win(char symbol) {
    // Check rows for the same symbol
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }
    
    // Check columns for the same symbol
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }
    
    // Check diagonals for the same symbol
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    
    if(board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) {
        return true;
    }
    
    return false;
}

void print_board() {
    // Print the board to the terminal
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int main() {
    // Initialize the random seed
    srand(time(NULL));
    
    // Setup the board
    setup_board();
    
    // Game loop
    bool player_turn = true;
    while(true) {
        // Print the board to the terminal
        print_board();
        
        // Get the player move
        int x, y;
        if(player_turn) {
            printf("Player's turn (X).\n");
            printf("Enter the row (0-2): ");
            scanf("%d", &x);
            printf("Enter the column (0-2): ");
            scanf("%d", &y);
        } else {
            printf("Computer's turn (O).\n");
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
            while(!is_valid_move(x, y)) {
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            }
            printf("Computer chose row %d and column %d.\n", x, y);
        }
        
        // Make the move
        if(is_valid_move(x, y)) {
            if(player_turn) {
                board[x][y] = 'X';
            } else {
                board[x][y] = 'O';
            }
        } else {
            printf("Invalid move, try again.\n");
            continue;
        }
        
        // Check for a win or tie
        if(check_win('X')) {
            printf("Player wins!\n");
            break;
        } else if(check_win('O')) {
            printf("Computer wins!\n");
            break;
        } else if(!is_valid_move(0, 0) && !is_valid_move(1, 0) && !is_valid_move(2, 0)
                  && !is_valid_move(0, 1) && !is_valid_move(1, 1) && !is_valid_move(2, 1)
                  && !is_valid_move(0, 2) && !is_valid_move(1, 2) && !is_valid_move(2, 2)) {
            printf("Tie game!\n");
            break;
        }
        
        // Switch turns
        player_turn = !player_turn;
    }
    
    // Print the final board
    print_board();
    
    return 0;
}