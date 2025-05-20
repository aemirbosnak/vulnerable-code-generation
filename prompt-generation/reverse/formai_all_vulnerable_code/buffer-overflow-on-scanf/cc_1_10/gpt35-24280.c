//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Defines the size of the game board

int board[SIZE][SIZE]; // The game board

// Function to initialize the board with random numbers
void initializeBoard() {
    srand(time(NULL));
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            board[i][j] = rand() % 100;
        }
    }
}

// Function to display the board
void displayBoard() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Function to shuffle the board
void shuffleBoard() {
    srand(time(NULL));
    int i, j, temp;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            temp = board[i][j];
            board[i][j] = board[x][y];
            board[x][y] = temp;
        }
    }
}

// Function to play the game
void playGame() {
    int i, j, tries = 0;
    int revealed[SIZE][SIZE]; // The revealed cells
    int score = 0; // The player's score
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            revealed[i][j] = 0;
        }
    }
    while(score < (SIZE*SIZE)/2) { // Loop until all pairs have been found
        int row1, col1, row2, col2;
        printf("\nEnter the first cell coordinates (row column): ");
        scanf("%d %d", &row1, &col1);
        if(row1 < 0 || row1 >= SIZE || col1 < 0 || col1 >= SIZE) {
            printf("Invalid cell coordinates!\n");
            continue;
        }
        if(revealed[row1][col1]) {
            printf("This cell has already been revealed!\n");
            continue;
        }
        revealed[row1][col1] = 1;
        printf("The value in this cell is %d.\n", board[row1][col1]);
        printf("\nEnter the second cell coordinates (row column): ");
        scanf("%d %d", &row2, &col2);
        if(row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE) {
            printf("Invalid cell coordinates!\n");
            revealed[row1][col1] = 0;
            continue;
        }
        if(revealed[row2][col2]) {
            printf("This cell has already been revealed!\n");
            revealed[row1][col1] = 0;
            continue;
        }
        revealed[row2][col2] = 1;
        printf("The value in this cell is %d.\n", board[row2][col2]);
        if(board[row1][col1] == board[row2][col2]) { // If the values match
            score++;
            printf("Congratulations! You found a pair!\n");
            printf("Score: %d\n", score);
        } else { // If the values do not match
            tries++;
            printf("Sorry, the values do not match.\n");
            printf("Tries: %d\n", tries);
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }
    }
    printf("\nCongratulations! You won the game with %d tries!\n", tries);
}

int main() {
    initializeBoard();
    printf("The initial board is:\n");
    displayBoard();
    shuffleBoard();
    printf("\nThe shuffled board is:\n");
    displayBoard();
    playGame();
    return 0;
}