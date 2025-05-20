//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int numPlayers;
int board[5][5];
int calledNumbers[75];
int lastNumberCalled;
int gameWon;

// Function prototypes
void initializeBoard();
void displayBoard(int player);
int callNumber();
int checkWin(int player);

int main() {
    // Get number of players
    printf("Welcome to Bingo! How many players? ");
    scanf("%d", &numPlayers);
    if(numPlayers <= 0) {
        printf("Invalid number of players!");
        return 1;
    }
    // Initialize board for each player
    for(int i = 1; i <= numPlayers; i++) {
        printf("Player %d's board:\n", i);
        initializeBoard();
        displayBoard(i);
    }
    // Game loop
    while(!gameWon) {
        int calledNumber = callNumber();
        printf("Next number is: %d\n", calledNumber);
        // Check each player's board for called number
        for(int i = 1; i <= numPlayers; i++) {
            printf("Player %d's board:\n", i);
            displayBoard(i);
            int winner = checkWin(i);
            if(winner) {
                printf("Congratulations, Player %d wins!\n", i);
                gameWon = 1;
                break;
            }
        }
    }
    return 0;
}

// Function to initialize each board
void initializeBoard() {
    // Initialize each square to 0
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }
    // Fill board with random numbers
    srand(time(NULL));
    for(int i = 0; i < 25; i++) {
        int row = i / 5;
        int col = i % 5;
        int num = (row * 15) + (rand() % 15) + 1;
        // Check for duplicate numbers
        if(board[row][col] == 0) {
            board[row][col] = num;
        }
        else {
            i--;
        }
    }
}

// Function to display board for given player
void displayBoard(int player) {
    printf("+----+----+----+----+----+\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("|");
            if(board[i][j] == 0) {
                printf("    ");
            }
            else if(board[i][j] < 10) {
                printf(" %d  ", board[i][j]);
            }
            else {
                printf("%d  ", board[i][j]);
            }
        }
        printf("|\n");
        printf("+----+----+----+----+----+\n");
    }
}

// Function to call a random number
int callNumber() {
    int num;
    do {
        num = (rand() % 75) + 1;
    } while(calledNumbers[num] == 1);
    calledNumbers[num] = 1;
    lastNumberCalled = num;
    return num;
}

// Function to check if given player has won
int checkWin(int player) {
    // Check rows
    for(int i = 0; i < 5; i++) {
        int rowSum = 0;
        for(int j = 0; j < 5; j++) {
            rowSum += board[i][j];
        }
        if(rowSum == 0) {
            return 1;
        }
    }
    // Check columns
    for(int i = 0; i < 5; i++) {
        int colSum = 0;
        for(int j = 0; j < 5; j++) {
            colSum += board[j][i];
        }
        if(colSum == 0) {
            return 1;
        }
    }
    // Check diagonals
    int diagonal1Sum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
    int diagonal2Sum = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
    if(diagonal1Sum == 0 || diagonal2Sum == 0) {
        return 1;
    }
    return 0;
}