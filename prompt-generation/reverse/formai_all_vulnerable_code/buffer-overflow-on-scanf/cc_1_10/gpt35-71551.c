//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_board(char board[][3]);
int check_winner(char board[][3], char player);
int validate_input(char board[][3], int row, int col);
void play_game();

// Main function
int main() {
    int choice;
    
    // Display menu
    printf("Welcome to C Table Game!\n");
    printf("1. Start game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            play_game();
            break;
        case 2:
            printf("Thank you for playing!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}

// Function to display the board
void display_board(char board[][3]) {
    printf("\n");
    printf("\t1\t2\t3\n");
    printf("\t-\t-\t-\n");
    for(int i=0; i<3; i++) {
        printf("%d |\t%c\t%c\t%c\n", i+1, board[i][0], board[i][1], board[i][2]);
        printf("\t-\t-\t-\n");
    }
}

// Function to check if a player has won
int check_winner(char board[][3], char player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    
    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    
    // No winner yet
    return 0;
}

// Function to validate user input
int validate_input(char board[][3], int row, int col) {
    if(row < 1 || row > 3 || col < 1 || col > 3) {
        return 0;
    }
    if(board[row-1][col-1] != ' ') {
        return 0;
    }
    return 1;
}

// Function to play the game
void play_game() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    int row, col;
    int turn = 1;
    int winner = 0;
    
    srand(time(NULL)); // Seed random number generator
    
    // Randomly choose starting player
    int starting_player = rand() % 2;
    if(starting_player == 0) {
        printf("Player 1 starts!\n");
    }
    else {
        printf("Player 2 starts!\n");
    }
    
    // Game loop
    while(1) {
        // Display board
        display_board(board);
        
        // Get user input
        printf("Player %d's turn. Enter row and column (e.g. 1 2): ", turn);
        scanf("%d %d", &row, &col);
        
        // Validate input
        if(!validate_input(board, row, col)) {
            printf("Invalid input!\n");
            continue;
        }
        
        // Fill cell on board
        if(turn == 1) {
            board[row-1][col-1] = player1;
        }
        else {
            board[row-1][col-1] = player2;
        }
        
        // Check for winner
        if(turn == 1) {
            winner = check_winner(board, player1);
        }
        else {
            winner = check_winner(board, player2);
        }
        
        if(winner) {
            display_board(board);
            printf("Player %d wins!\n", turn);
            break;
        }
        
        // Check for tie
        int count = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    count++;
                    break;
                }
            }
        }
        if(count == 0) {
            display_board(board);
            printf("It's a tie!\n");
            break;
        }
        
        // Switch player
        if(turn == 1) {
            turn = 2;
        }
        else {
            turn = 1;
        }
    }
}