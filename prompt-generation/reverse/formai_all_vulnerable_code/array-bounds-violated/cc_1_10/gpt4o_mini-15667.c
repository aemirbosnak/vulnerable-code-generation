//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Define the size of the grid

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]);
void displayBoard(char display[SIZE][SIZE]);
void shuffleBoard(char board[SIZE][SIZE]);
bool checkMatch(char board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY);
bool isGameComplete(char display[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int firstX, firstY, secondX, secondY;
    int pairsFound = 0;

    initializeBoard(board, display);
    
    while (!isGameComplete(display)) {
        displayBoard(display);
        printf("Select first card (row, col): ");
        scanf("%d %d", &firstX, &firstY);
        
        display[firstX][firstY] = board[firstX][firstY];
        displayBoard(display);
        
        printf("Select second card (row, col): ");
        scanf("%d %d", &secondX, &secondY);
        
        display[secondX][secondY] = board[secondX][secondY];
        displayBoard(display);
        
        if (checkMatch(board, firstX, firstY, secondX, secondY)) {
            printf("It's a match! You've found a pair.\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            display[firstX][firstY] = '*';
            display[secondX][secondY] = '*';
        }
    }
    
    printf("Congratulations! You've found all pairs.\n");

    return 0;
}

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE]) {
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    int totalPairs = (SIZE * SIZE) / 2;

    // Initialize display for hiding the cards
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            display[i][j] = '*';
        }
    }

    // Fill the board with pairs
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < totalPairs) {
                board[i][j] = symbols[index / 2]; // Two similar symbols for each pair
            } 
            index++;
        }
    }

    // Shuffle the board
    shuffleBoard(board);
}

void shuffleBoard(char board[SIZE][SIZE]) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void displayBoard(char display[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

bool checkMatch(char board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY) {
    return (board[firstX][firstY] == board[secondX][secondY]);
}

bool isGameComplete(char display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == '*') {
                return false; // Game is not complete yet
            }
        }
    }
    return true; // All pairs found!
}