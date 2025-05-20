//GPT-4o-mini DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10

void displayGrid(char grid[SIZE][SIZE]) {
    printf("Here's how the grid looks like:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void initializeGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Fill the grid with water ("~")
            grid[i][j] = '~';
        }
    }
}

void placeShip(char grid[SIZE][SIZE]) {
    int shipRow, shipCol;
    
    // Place a funny ship (represented by "S") at a random location
    shipRow = rand() % SIZE;
    shipCol = rand() % SIZE;
    grid[shipRow][shipCol] = 'S';
    printf("A ship has been placed somewhere in the sea, but don't worry, it's only here to party!\n");
}

int playerTurn(char grid[SIZE][SIZE]) {
    int guessRow, guessCol;
    printf("Time to sink this party ship! Enter your guess (row and col from 0 to %d): ", SIZE-1);
    scanf("%d %d", &guessRow, &guessCol);
    
    if (guessRow < 0 || guessRow >= SIZE || guessCol < 0 || guessCol >= SIZE) {
        printf("Whoa there! That's out of the water zone! Try again.\n");
        return -1; // Invalid guess
    }

    if (grid[guessRow][guessCol] == 'S') {
        printf("Bingo! You hit the ship! Let's throw a party!\n");
        grid[guessRow][guessCol] = 'X'; // Mark hit
        return 1; // Hit
    } else if (grid[guessRow][guessCol] == 'X') {
        printf("Oops, you hit a spot you've already claimed. This party is getting crowded!\n");
        return 0; // Already hit
    } else {
        printf("Splash! You missed! But hey, the water's lovely!\n");
        grid[guessRow][guessCol] = 'O'; // Mark miss
        return 0; // Miss
    }
}

int main() {
    char grid[SIZE][SIZE];
    int hitCount = 0;
    int maxHits = 1; // We only placed one ship
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Amazing Sea Battle Game! Ready to sink some ships?\n");
    initializeGrid(grid);
    placeShip(grid);

    while (hitCount < maxHits) {
        displayGrid(grid);
        
        int result = playerTurn(grid);
        if (result == 1) {
            hitCount++;
        }
    }

    printf("Congratulations! You've successfully sunk the ship! Time for a beach party 🎉\n");
    printf("Thanks for playing, and remember: Don't forget your sunscreen next time!\n");

    return 0;
}