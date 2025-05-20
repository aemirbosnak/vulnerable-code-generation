//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4  // Size of the board
#define NUM_PAIRS (SIZE * SIZE / 2)

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
char symbols[NUM_PAIRS];
int attempts = 0;

void initializeSymbols() {
    for(int i = 0; i < NUM_PAIRS; i++) {
        symbols[i] = 'A' + i; // Fill symbols A, B, C, ..., based on number of pairs
    }
}

void shuffleSymbols() {
    for(int i = 0; i < NUM_PAIRS; i++) {
        int randomIndex = rand() % NUM_PAIRS;
        char temp = symbols[i];
        symbols[i] = symbols[randomIndex];
        symbols[randomIndex] = temp;
    }
}

void createBoard() {
    int index = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if (index < NUM_PAIRS) {
                board[i][j] = symbols[index / 2]; // Each symbol appears twice
                index++;
            }
        }
    }
}

void displayBoard() {
    printf("Attempts: %d\n", attempts);
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void revealCard(int x, int y) {
    revealed[x][y] = 1; // Reveal the card
}

void hideCard(int x, int y) {
    revealed[x][y] = 0; // Hide the card
}

int isMatch(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int isGameWon() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if (!revealed[i][j])
                return 0;
    return 1;
}

void gameLoop() {
    int x1, y1, x2, y2;
    
    while(!isGameWon()) {
        displayBoard();
        
        printf("Select first card (row col): ");
        scanf("%d %d", &x1, &y1);
        revealCard(x1, y1);
        displayBoard();
        
        printf("Select second card (row col): ");
        scanf("%d %d", &x2, &y2);
        revealCard(x2, y2);
        
        attempts++;
        if (!isMatch(x1, y1, x2, y2)) {
            printf("No match! Try again.\n");
            hideCard(x1, y1);
            hideCard(x2, y2);
        } else {
            printf("Match found!\n");
        }
    }
    
    printf("Congratulations! You've matched all cards in %d attempts!\n", attempts);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initializeSymbols();
    shuffleSymbols();
    
    memset(revealed, 0, sizeof(revealed)); // Initialize revealed state to all hidden
    createBoard();
    
    gameLoop();
    return 0;
}