//GEMINI-pro DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEART "❤️"
#define ROSE "🌹"
#define CANDLE "🕯️"

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a romantic message
void print_message() {
    printf("My love for you is like a %s that burns brightly, even in the darkest of times.\n", CANDLE);
    printf("It is as fragrant as a %s, filling my heart with its sweet scent.\n", ROSE);
    printf("And it is as precious as a %s, something I will treasure forever.\n", HEART);
}

// Function to play the game
void play_game() {
    // Initialize the game board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    // Get the player's names
    char player1_name[20];
    char player2_name[20];
    printf("Player 1, enter your name: ");
    scanf("%s", player1_name);
    printf("Player 2, enter your name: ");
    scanf("%s", player2_name);
    
    // Decide who goes first
    int first_player = random_range(1, 2);
    
    // Play the game until there is a winner or a draw
    int turn = 0;
    while (turn < 9) {
        // Print the game board
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        // Get the player's move
        int row, col;
        if (turn % 2 == 0) {
            printf("%s, it's your turn (enter row and column): ", player1_name);
        } else {
            printf("%s, it's your turn (enter row and column): ", player2_name);
        }
        scanf("%d %d", &row, &col);
        
        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // Place the player's symbol on the board
        if (turn % 2 == 0) {
            board[row - 1][col - 1] = 'X';
        } else {
            board[row - 1][col - 1] = 'O';
        }
        
        // Check if there is a winner
        int winner = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                winner = board[i][0];
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                winner = board[0][i];
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            winner = board[0][0];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            winner = board[0][2];
        }
        
        // Declare the winner
        if (winner != 0) {
            if (winner == 'X') {
                printf("%s wins!\n", player1_name);
            } else {
                printf("%s wins!\n", player2_name);
            }
            break;
        }
        
        // Check if there is a draw
        if (turn == 8) {
            printf("It's a draw!\n");
        }
        
        // Increment the turn number
        turn++;
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Print a welcome message
    printf("Welcome to the Romantic Tic-Tac-Toe game!\n");
    
    // Play the game
    play_game();
    
    // Print a goodbye message
    print_message();
    
    return 0;
}