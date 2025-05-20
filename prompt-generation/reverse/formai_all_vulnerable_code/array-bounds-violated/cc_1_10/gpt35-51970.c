//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
// C Tic Tac Toe AI Example Program
#include <stdio.h>
#include <stdlib.h>

// Global Variables
char board[3][3];
char player = 'X'; // X always goes first
int moves = 0;

// Function Prototypes
void printBoard();
void play();
int checkWin(char);
int minimax(char);
int computerMove();

int main() {
    // Initialize the board with spaces
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Tic Tac Toe Game\n");
    printf("You are '%c' and the computer is 'O'\n", player);

    // Play the game until there is a winner or tie
    while(checkWin('X') == 0 && checkWin('O') == 0 && moves < 9) {
        printBoard();
        play();
    }

    // Display the final board
    printBoard();

    // Check for a winner or tie
    if(checkWin('X') == 1) {
        printf("Congrats! You win!\n");
    } else if(checkWin('O') == 1) {
        printf("Sorry, the computer wins.\n");
    } else {
        printf("It's a tie.\n");
    }

    return 0;
}

// Function to print the tic tac toe board
void printBoard() {
    printf("  1 2 3\n");
    for(int i=0; i<3; i++) {
        printf("%c ", 'A'+i);
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function for player to make a move
void play() {
    int row = -1;
    int col = -1;

    printf("\nEnter your move (ex. A1, B2, C3): ");
    scanf(" %c%d", &row, &col);

    // Convert input to indices
    row -= 'A';
    col--;

    if(board[row][col] == ' ') {
        board[row][col] = player;
        moves++;
    } else {
        printf("That spot is already taken, try again.\n");
        play();
    }

    // Switch the player
    player = (player == 'X') ? 'O' : 'X';
}

// Function to check if a player has won
int checkWin(char c) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c) {
            return 1;
        }
    }

    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c) {
        return 1;
    }
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c) {
        return 1;
    }

    return 0;
}

// Function to implement AI with MiniMax algorithm
int minimax(char c) {
    int score;

    // Check for terminal states
    if(checkWin('X')) {
        return -10;
    }
    if(checkWin('O')) {
        return 10;
    }
    if(moves == 9) {
        return 0;
    }

    // Maximize score for 'O' and minimize for 'X'
    if(c == 'O') {
        score = -1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    moves++;
                    score = (score > minimax('X')) ? score : minimax('X');
                    board[i][j] = ' ';
                    moves--;
                }
            }
        }
    } else {
        score = 1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    moves++;
                    score = (score < minimax('O')) ? score : minimax('O');
                    board[i][j] = ' ';
                    moves--;
                }
            }
        }
    }

    return score;
}

// Function for computer to make a move
int computerMove() {
    int row = -1;
    int col = -1;
    int bestScore = -1000;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                moves++;
                int score = minimax('X');
                board[i][j] = ' ';
                moves--;
                if(score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    board[row][col] = 'O';
    moves++;
}