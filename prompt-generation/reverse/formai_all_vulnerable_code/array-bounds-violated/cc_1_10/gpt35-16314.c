//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // Tic Tac Toe Board

// Function to display the Tic Tac Toe board
void display_board() {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n");
}

// Function to initialize the Tic Tac Toe board
void initialize_board() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to check if the player has won the game
int check_if_won(char player) {
    // Checking Rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Checking Columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Checking Diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to get the next move from the player
void get_player_move(char player) {
    int row, col;
    printf("\n%s's turn (X or O): ", player == 'X' ? "Player 1" : "Player 2");
    scanf("%d %d", &row, &col);
    if(board[row-1][col-1] == ' ') {
        board[row-1][col-1] = player;
    }
    else {
        printf("\nInvalid Move! Please Try Again.\n");
        get_player_move(player);
    }
}

// Function to get the best move for the AI player
void get_AI_move() {
    int row, col;
    // If AI can win in the next move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(check_if_won('O')) {
                    return;
                }
                else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    // If player can win in the next move, block the move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(check_if_won('X')) {
                    board[i][j] = 'O';
                    return;
                }
                else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    // If AI can't win nor block player's move, choose random move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != ' ');
    board[row][col] = 'O';
}

// Function to check if the game is a tie
int check_if_tie() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to start and play the game
void play_game() {
    char player = 'X';
    int game_status = 0; // 0 - Game is Incomplete, 1 - Player Wins, 2 - AI Wins, 3 - Tie Game
    initialize_board();
    display_board();
    while(game_status == 0) {
        if(player == 'X') {
            get_player_move(player);
        }
        else {
            get_AI_move();
        }
        display_board();
        if(check_if_won(player)) {
            game_status = player == 'X' ? 1 : 2;
        }
        else if(check_if_tie()) {
            game_status = 3;
        }
        player = player == 'X' ? 'O' : 'X';
    }
    if(game_status == 1) {
        printf("Congratulations! Player 1 Wins!");
    }
    else if(game_status == 2) {
        printf("Sorry, AI Wins. Better Luck Next Time.");
    }
    else {
        printf("It's a Tie Game!");
    }
}

int main() {
    printf("Welcome to Tic Tac Toe.\n");
    play_game();
    return 0;
}