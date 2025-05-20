//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 4
#define TOTAL_CARDS (GRID_SIZE * GRID_SIZE)
#define MAX_ATTEMPTS 10

void generateDeck(char deck[], int size);
void shuffleDeck(char deck[], int size);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal[GRID_SIZE][GRID_SIZE]);
int checkMatch(char firstCard, char secondCard);
void playGame(char deck[]);

int main() {
    char deck[TOTAL_CARDS];
    generateDeck(deck, TOTAL_CARDS);
    shuffleDeck(deck, TOTAL_CARDS);
    playGame(deck);
    return 0;
}

void generateDeck(char deck[], int size) {
    char symbols[] = "ABCDEFGH"; // 8 pairs of symbols
    int index = 0;

    for (int i = 0; i < size / 2; i++) {
        deck[index++] = symbols[i];
        deck[index++] = symbols[i];
    }
}

void shuffleDeck(char deck[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (reveal[i][j]) {
                printf(" %c ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int checkMatch(char firstCard, char secondCard) {
    return firstCard == secondCard;
}

void playGame(char deck[]) {
    char grid[GRID_SIZE][GRID_SIZE];
    int reveal[GRID_SIZE][GRID_SIZE];
    int attempts = 0;
    int pairsFound = 0;

    // Initialize grid and reveal states
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = deck[i * GRID_SIZE + j];
            reveal[i][j] = 0; // All cards are hidden initially
        }
    }

    while (pairsFound < TOTAL_CARDS / 2 && attempts < MAX_ATTEMPTS) {
        displayGrid(grid, reveal);
        
        int firstRow, firstCol, secondRow, secondCol;
        printf("\nEnter the coordinates of the first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);

        // Check if entered coordinates are valid
        if (firstRow < 0 || firstRow >= GRID_SIZE || firstCol < 0 || firstCol >= GRID_SIZE ||
            secondRow < 0 || secondRow >= GRID_SIZE || secondCol < 0 || secondCol >= GRID_SIZE ||
            (firstRow == secondRow && firstCol == secondCol)) {
            printf("Invalid coordinates! Please try again.\n");
            continue;
        }

        reveal[firstRow][firstCol] = 1;
        reveal[secondRow][secondCol] = 1;

        displayGrid(grid, reveal);

        if (checkMatch(grid[firstRow][firstCol], grid[secondRow][secondCol])) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match! Try again.\n");
            // Reveal cards briefly (fake delay)
            printf("...Reverting cards...\n");
            reveal[firstRow][firstCol] = 0;
            reveal[secondRow][secondCol] = 0;
        }
        attempts++;
    }

    if (pairsFound == TOTAL_CARDS / 2) {
        printf("Congratulations! You've found all the pairs!\n");
    } else {
        printf("Game Over! You exceeded the maximum attempts.\n");
    }
}