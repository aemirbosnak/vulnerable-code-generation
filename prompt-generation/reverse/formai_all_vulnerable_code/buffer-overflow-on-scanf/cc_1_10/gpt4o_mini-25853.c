//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char player, computer;

// Function to initialize the game board
void initializeBoard() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

// Function to display the current state of the board
void displayBoard() {
    printf("Current Board:\n");
    for(int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a winner
bool checkWinner(char mark) {
    // Check rows and columns
    for(int i = 0; i < SIZE; i++) {
        if((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
           (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return true;
    }
    // Check diagonals
    if((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
       (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j] == ' ')
                return false;
    return true;
}

// Function for the player's move
void playerMove() {
    int x, y;
    while (true) {
        printf("Choose your move [row, column]: ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == ' ') {
            board[x][y] = player;
            break;
        } else {
            printf("Oops! That's not a valid move! Try again, oh wise one!\n");
        }
    }
}

// Random number generator for AI to pick its move
void aiMove() {
    int x, y;
    while (true) {
        x = rand() % SIZE;
        y = rand() % SIZE;
        if (board[x][y] == ' ') {
            board[x][y] = computer;
            printf("AI makes its move at (%d, %d)! Guess it got lucky...\n", x, y);
            break;
        }
    }
}

// The main game loop
void playGame() {
    printf("Welcome to the funniest Tic Tac Toe ever!\n\n");
    initializeBoard();
    
    // Player chooses X or O
    printf("Player, choose your character (X or O): ");
    scanf(" %c", &player);
    computer = (player == 'X') ? 'O' : 'X';

    int turn = 0;
    while (true) {
        displayBoard();
        if (turn % 2 == 0) {
            playerMove();
            if (checkWinner(player)) {
                displayBoard();
                printf("Congratulations! You win! The AI has crumbled like a bad cookie!\n");
                break;
            }
        } else {
            aiMove();
            if (checkWinner(computer)) {
                displayBoard();
                printf("Oh snap! The AI wins! It's time to brush up on your skills!\n");
                break;
            }
        }
        if (checkDraw()) {
            displayBoard();
            printf("It's a draw! Everyone gets a participant trophy!\n");
            break;
        }
        turn++;
    }

    printf("Thanks for playing! Now go have some tacos!\n");
}

// The entry point of our program
int main() {
    srand(time(0)); // Seed the random number generator
    playGame();
    return 0;
}