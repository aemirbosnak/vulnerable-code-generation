//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
bool gameOver = false;

// Function declarations
void init();
void draw();
bool isWinner(char);
bool isTie();
void playerMove();
void aiMove();
int evaluate(char);
int minimax(int, bool);

int main() {
    int choice;
    bool aiFirst = false;
    
    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n");
    
    // Prompt user to choose to play first or second
    printf("Do you want to play first or second? (1/2) ");
    scanf("%d", &choice);
    
    // check choice
    if (choice == 2) {
        aiFirst = true;
    }
    
    // start game
    init();
    draw();
    
    // game loop
    while (!gameOver) {
        if (aiFirst) {
            aiMove();
            draw();
        }
        
        playerMove();
        draw();
        
        if (isWinner('X')) {
            printf("You win!\n");
            gameOver = true;
        } else if (isWinner('O')) {
            printf("You lose!\n");
            gameOver = true;
        } else if (isTie()) {
            printf("It's a tie!\n");
            gameOver = true;
        } else {
            aiMove();
            draw();
            
            if (isWinner('X')) {
                printf("You win!\n");
                gameOver = true;
            } else if (isWinner('O')) {
                printf("You lose!\n");
                gameOver = true;
            } else if (isTie()) {
                printf("It's a tie!\n");
                gameOver = true;
            }
        }
    }
    
    return 0;
}

// Function to initialize the board
void init() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '_';
        }
    }
}

// Function to draw the board
void draw() {
    printf("\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    
    printf("\n");
}

// Function to check if player has won
bool isWinner(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

// Function to check if it's a tie
bool isTie() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '_') {
                return false;
            }
        }
    }
    
    return true;
}

// Function to get player's move
void playerMove() {
    int row, col;
    
    printf("Enter row (1-3): ");
    scanf("%d", &row);
    row--;
    
    printf("Enter column (1-3): ");
    scanf("%d", &col);
    col--;
    
    if (board[row][col] == '_') {
        board[row][col] = 'X';
    } else {
        printf("That spot is already taken.\n");
        playerMove();
    }
}

// Function to get AI's move
void aiMove() {
    int bestScore = -1000;
    int row, col;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '_') {
                // Make a move in this spot and evaluate its score
                board[i][j] = 'O';
                int score = minimax(0, false);
                board[i][j] = '_';
                
                // If the score is better than what we've seen so far, update the move
                if (score > bestScore) {
                    row = i;
                    col = j;
                    bestScore = score;
                }
            }
        }
    }
    
    board[row][col] = 'O';
    printf("AI placed an O in row %d, col %d.\n", row+1, col+1);
}

// Function to evaluate the score of a given board
int evaluate(char player) {
    if (isWinner(player)) {
        return 10;
    } else if (isWinner((player == 'X') ? 'O' : 'X')) {
        return -10;
    } else {
        return 0;
    }
}

// Function to calculate the best move using minimax algorithm
int minimax(int depth, bool isMaximizing) {
    // Evaluate score if game is over or maximum recursion depth has been reached
    if (isWinner('X')) {
        return -10 + depth;
    } else if (isWinner('O')) {
        return 10 - depth;
    } else if (isTie()) {
        return 0;
    }
    
    // Maximizing player (AI)
    if (isMaximizing) {
        int bestScore = -1000;
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'O';
                    int score = minimax(depth+1, false);
                    board[i][j] = '_';
                    if (score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        
        return bestScore;
    } 
    // Minimizing player (player)
    else {
        int bestScore = 1000;
        
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = 'X';
                    int score = minimax(depth+1, true);
                    board[i][j] = '_';
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        
        return bestScore;
    }
}