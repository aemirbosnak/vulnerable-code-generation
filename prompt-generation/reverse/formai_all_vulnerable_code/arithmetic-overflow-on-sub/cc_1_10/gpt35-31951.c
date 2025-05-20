//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3]; // Board of Tic Tac Toe
bool player = true; // true = Player 1, false = Player 2
int moves = 0; // Number of moves played

// Function to initialize the board
void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        printf("\n");
        if(i != 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check if there is a winner
bool isWinner() {
    // Checking rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return true;
        }
    }
    
    // Checking columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return true;
        }
    }
    
    // Checking diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return true;
    }
    
    // If no winner yet
    return false;
}

// Function to check if the game is a tie
bool isTie() {
    if(moves == 9 && !isWinner()) {
        return true;
    }
    return false;
}

// Function to get player input
void getPlayerInput() {
    int row, col;
    do {
        printf("Enter row (1 - 3) and column (1 - 3) to place your move: ");
        scanf("%d %d", &row, &col);
        // Converting to 0-based indexing
        row--;
        col--;
        if(row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid input. Please try again.\n");
        }
        else if(board[row][col] != '-') {
            printf("The cell is already occupied. Please try again.\n");
        }
        else {
            board[row][col] = player ? 'X' : 'O';
            moves++;
            break;
        }
    } while(true);
}

// Function to get AI input
void getAIInput() {
    printf("AI has played its move.\n");
    int row, col;
    row = rand() % 3;
    col = rand() % 3;
    while(board[row][col] != '-') {
        row = rand() % 3;
        col = rand() % 3;
    }
    board[row][col] = player ? 'X' : 'O';
    moves++;
}

// Function to play the game
void playGame() {
    printf("Welcome to Tic Tac Toe!\nPlayer 1 is X and Player 2 is O.\n\n");
    initializeBoard();
    displayBoard();
    do {
        if(player) {
            getPlayerInput();
        }
        else {
            getAIInput();
        }
        displayBoard();
        if(isWinner()) {
            printf(player ? "Congratulations! You have won!\n" : "AI has won!\n");
            break;
        }
        if(isTie()) {
            printf("The game is a tie!\n");
            break;
        }
        player = !player;
    } while(true);
}

// Main function
int main() {
    playGame();
    return 0;
}