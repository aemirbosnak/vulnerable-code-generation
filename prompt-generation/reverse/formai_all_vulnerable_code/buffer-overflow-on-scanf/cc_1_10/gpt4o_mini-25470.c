//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISCS 64 // Avoiding over-configuration for paranoia!

// Function prototypes
void moveDisc(int n, char source, char target, char auxiliary);
void validateMove(int n, int maxDiscs);
void logMove(int disc, char source, char target);
void printStackState(int n, char tower);
void printHanoiState();

// Tower structure representing each stack of discs
typedef struct Tower {
    int discs[MAX_DISCS];
    int top;
} Tower;

Tower sourceTower, targetTower, auxiliaryTower;
int totalDiscs = 0;

int main() {
    printf("Welcome to the Tower of Hanoi!\n");

    // Input number of discs
    printf("Enter the number of discs (1 to %d): ", MAX_DISCS);
    if (scanf("%d", &totalDiscs) != 1 || totalDiscs < 1 || totalDiscs > MAX_DISCS) {
        fprintf(stderr, "Invalid input! Please enter a valid number of discs.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize towers
    sourceTower.top = -1;
    targetTower.top = -1;
    auxiliaryTower.top = -1;

    // Populate the source tower
    for (int i = totalDiscs; i > 0; i--) {
        sourceTower.discs[++sourceTower.top] = i;
    }

    // Print initial state
    printHanoiState();

    // Solve the Tower of Hanoi
    moveDisc(totalDiscs, 'A', 'C', 'B');

    // Final state confirmation
    printHanoiState();

    return 0;
}

void moveDisc(int n, char source, char target, char auxiliary) {
    // Paranoid checks to avoid logical inconsistencies
    if (n < 1) return;

    validateMove(n, totalDiscs);
    
    moveDisc(n - 1, source, auxiliary, target);

    // Perform the actual move
    int disc = sourceTower.discs[sourceTower.top--]; // Pop from source
    targetTower.discs[++targetTower.top] = disc; // Push to target

    // Logging the move
    logMove(disc, source, target);
    
    // Print tower state
    printHanoiState();

    moveDisc(n - 1, auxiliary, target, source);
}

void validateMove(int n, int maxDiscs) {
    if (n > maxDiscs) {
        fprintf(stderr, "Error: Attempting to move more discs than available!\n");
        exit(EXIT_FAILURE);
    }
}

void logMove(int disc, char source, char target) {
    printf("Moving disc %d from %c to %c\n", disc, source, target);
}

void printStackState(int n, char tower) {
    Tower *currentTower = (tower == 'A') ? &sourceTower : (tower == 'B') ? &auxiliaryTower : &targetTower;
    
    printf("Tower %c: ", tower);
    for (int i = currentTower->top; i >= 0; i--) {
        printf("%d ", currentTower->discs[i]);
    }
    printf("\n");
}

void printHanoiState() {
    printf("\nCurrent State of Towers:\n");
    printStackState(totalDiscs, 'A');
    printStackState(totalDiscs, 'B');
    printStackState(totalDiscs, 'C');
    printf("\n");
}