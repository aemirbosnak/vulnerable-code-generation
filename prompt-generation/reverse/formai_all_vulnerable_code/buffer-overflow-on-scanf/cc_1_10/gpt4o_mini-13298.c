//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Size of the board (4x4)
#define PAIR_COUNT (SIZE * SIZE) / 2

void initializeBoard(int board[SIZE][SIZE], int values[PAIR_COUNT]);
void displayBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool flipCard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE], int x, int y);
bool checkMatch(int board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY);
void shuffle(int *array, size_t n);
void clearScreen();

int main() {
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    int values[PAIR_COUNT];
    int moves = 0, firstCardX = -1, firstCardY = -1;
    int secondCardX, secondCardY;
    int pairsFound = 0;

    srand(time(NULL));

    // Fill values for pairs
    for (int i = 0; i < PAIR_COUNT; i++) {
        values[i] = i / 2 + 1; // Create pairs (1,1), (2,2), ...
    }
    
    shuffle(values, PAIR_COUNT); // Shuffle card values
    initializeBoard(board, values);

    while (pairsFound < PAIR_COUNT) {
        clearScreen();
        displayBoard(board, revealed);
        
        printf("Moves: %d\n", moves);
        printf("Pairs found: %d\n", pairsFound);
        
        // Get first card
        printf("Select first card (row and column): ");
        scanf("%d %d", &firstCardX, &firstCardY);
        
        if (!flipCard(board, revealed, firstCardX, firstCardY)) {
            printf("Invalid selection or already revealed! Try again.\n");
            continue;
        }

        clearScreen();
        displayBoard(board, revealed);
        printf("Select second card (row and column): ");
        scanf("%d %d", &secondCardX, &secondCardY);

        if (!flipCard(board, revealed, secondCardX, secondCardY) || (firstCardX == secondCardX && firstCardY == secondCardY)) {
            printf("Invalid selection! Try again.\n");
            revealed[firstCardX][firstCardY] = false; // Undo first card reveal
            continue;
        }

        moves++;
        
        if (checkMatch(board, firstCardX, firstCardY, secondCardX, secondCardY)) {
            printf("Match found!\n");
            pairsFound++;
        } else {
            printf("No match! Try again.\n");
            revealed[firstCardX][firstCardY] = false; // Hide first card
            revealed[secondCardX][secondCardY] = false; // Hide second card
        }
        // Wait for user to see result
        printf("Press Enter to continue...");
        while (getchar() != '\n'); // To consume the leftover newline
        getchar();
    }

    printf("Congratulations! You've found all pairs!\nTotal Moves: %d\n", moves);
    return 0;
}

void initializeBoard(int board[SIZE][SIZE], int values[PAIR_COUNT]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = values[i * SIZE + j];
        }
    }
}

void displayBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("[%d] ", board[i][j]);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

bool flipCard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE], int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && !revealed[x][y]) {
        revealed[x][y] = true;
        return true;
    }
    return false;
}

bool checkMatch(int board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY) {
    return board[firstX][firstY] == board[secondX][secondY];
}

void shuffle(int *array, size_t n) {
    if (n > 1) {
        for (size_t i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}