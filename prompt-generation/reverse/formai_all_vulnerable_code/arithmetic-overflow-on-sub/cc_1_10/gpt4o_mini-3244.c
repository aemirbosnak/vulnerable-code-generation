//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4
#define NUM_PAIRS (SIZE * SIZE) / 2

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE], int size);
void shufflePairs(char board[SIZE][SIZE]);
void displayBoard(char display[SIZE][SIZE]);
int checkMatch(char board[SIZE][SIZE], char display[SIZE][SIZE], int x1, int y1, int x2, int y2);
int isGameOver(char display[SIZE][SIZE]);
void revealCard(char board[SIZE][SIZE], char display[SIZE][SIZE], int x, int y);
void hideCard(char display[SIZE][SIZE], int x, int y);

int main() {
    char board[SIZE][SIZE];
    char display[SIZE][SIZE];
    int x1, y1, x2, y2;
    int matchFound;
    int attempts = 0;

    srand(time(NULL));
    initializeBoard(board, display, SIZE);
    shufflePairs(board);

    printf("Welcome to the Sherlock Holmes Memory Game!\n");
    printf("Detective, your task is to find all pairs of matching faces!\n");

    while (!isGameOver(display)) {
        displayBoard(display);
        
        printf("Enter coordinates for the first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        x1--; y1--; // Adjust for 0-based indexing
        
        revealCard(board, display, x1, y1);
        displayBoard(display);
        
        printf("Enter coordinates for the second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        x2--; y2--; // Adjust for 0-based indexing
        
        revealCard(board, display, x2, y2);
        displayBoard(display);
        
        matchFound = checkMatch(board, display, x1, y1, x2, y2);
        
        if (matchFound) {
            printf("A match is found, Detective! Well done!\n");
        } else {
            printf("No match, Sherlock! Let's hide them again...\n");
            usleep(2000000); // Hide cards after 2 seconds
            hideCard(display, x1, y1);
            hideCard(display, x2, y2);
        }
        attempts++;
    }

    printf("Congratulations, Detective! You've uncovered all pairs in %d attempts!\n", attempts);
    return 0;
}

void initializeBoard(char board[SIZE][SIZE], char display[SIZE][SIZE], int size) {
    int value = 'A';
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            display[i][j] = '*';  // All cards are initially hidden
            if (i * size + j < NUM_PAIRS) {
                board[i][j] = value; // Fill board with pairs
                if (j % 2 == 1) value++; // Increment to get the next pair
            } else {
                board[i][j] = 0; // Unused positions
            }
        }
    }
}

void shufflePairs(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        int j = rand() % (SIZE * SIZE);
        char temp = board[i / SIZE][i % SIZE];
        board[i / SIZE][i % SIZE] = board[j / SIZE][j % SIZE];
        board[j / SIZE][j % SIZE] = temp;
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
    printf("\n");
}

int checkMatch(char board[SIZE][SIZE], char display[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    if (board[x1][y1] == board[x2][y2]) {
        return 1; // Match found
    }
    return 0; // No match
}

int isGameOver(char display[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (display[i][j] == '*') return 0; // Game not over yet
        }
    }
    return 1; // Game over
}

void revealCard(char board[SIZE][SIZE], char display[SIZE][SIZE], int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        display[x][y] = board[x][y];
    }
}

void hideCard(char display[SIZE][SIZE], int x, int y) {
    display[x][y] = '*'; // Hide card again
}