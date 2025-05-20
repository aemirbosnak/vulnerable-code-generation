//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_SYMBOL 'X'
#define COMPUTER_SYMBOL 'O'
#define EMPTY_SYMBOL '-'

// Define some constants
#define MAX_MOVES BOARD_SIZE*BOARD_SIZE

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int getMove(char board[BOARD_SIZE][BOARD_SIZE]);
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int move, char symbol);
char checkWin(char board[BOARD_SIZE][BOARD_SIZE]);

// Define the main function
int main() {
    // Declare and initialize variables
    char board[BOARD_SIZE][BOARD_SIZE];
    int move;
    char symbol;
    char winner;
    
    // Initialize the board
    initializeBoard(board);
    
    // Print the instructions
    printf("Welcome to Tic Tac Toe!\n");
    printf("Enter a number between 1 and 9 to make your move.\n");
    printf("You are %c and the computer is %c.\n", PLAYER_SYMBOL, COMPUTER_SYMBOL);
    printf("Let's begin!\n\n");
    
    // Game loop
    for (int i = 1; i <= MAX_MOVES; i++) {
        // Print the board
        printBoard(board);
        
        // Determine whose turn it is
        if (i % 2 == 1) {
            // Player's turn
            symbol = PLAYER_SYMBOL;
            move = getMove(board);
        } else {
            // Computer's turn
            symbol = COMPUTER_SYMBOL;
            printf("Computer's turn...\n");
            // Simulate thinking time
            srand(time(NULL));
            int thinking_time = rand() % 3;
            sleep(thinking_time);
            // Make a move
            move = rand() % MAX_MOVES + 1;
            while (board[(move-1)/BOARD_SIZE][(move-1)%BOARD_SIZE] != EMPTY_SYMBOL) {
                move = rand() % MAX_MOVES + 1;
            }
        }
        
        // Make the move
        makeMove(board, move, symbol);
        
        // Check for a win
        winner = checkWin(board);
        if (winner != EMPTY_SYMBOL) {
            // Print the board
            printBoard(board);
            // Print the winner
            if (winner == PLAYER_SYMBOL) {
                printf("Congratulations, you win!\n");
            } else {
                printf("Sorry, computer wins.\n");
            }
            return 0;
        }
    }
    
    // If we get here, it's a tie
    printBoard(board);
    printf("It's a tie!\n");
    return 0;
}

// Function to initialize the board
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Loop through each cell and set to EMPTY_SYMBOL
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SYMBOL;
        }
    }
}

// Function to print the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Loop through each cell and print the symbol
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get a move from the player
int getMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Declare and initialize variables
    int move = 0;
    int row, col;
    
    // Loop until a valid move is entered
    while (move < 1 || move > MAX_MOVES || board[(move-1)/BOARD_SIZE][(move-1)%BOARD_SIZE] != EMPTY_SYMBOL) {
        // Prompt the user for a move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
    }
    
    // Convert the move to a row and column
    row = (move-1)/BOARD_SIZE;
    col = (move-1)%BOARD_SIZE;
    
    // Return the move as a single index
    return row*BOARD_SIZE + col + 1;
}

// Function to make a move on the board
void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int move, char symbol) {
    // Convert the move to a row and column
    int row = (move-1)/BOARD_SIZE;
    int col = (move-1)%BOARD_SIZE;
    
    // Set the cell to the given symbol
    board[row][col] = symbol;
}

// Function to check for a winning state
char checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Loop through each row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // Loop through each column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    
    // Check the diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    // If we get here, there's no winner
    return EMPTY_SYMBOL;
}