//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to move disks from source to destination using auxiliary
void moveDisks(int n, char source, char destination, char auxiliary, int **moves, int *moveCount) {
    if (n == 1) {
        // Record move
        moves[*moveCount][0] = 1; // Move disk
        moves[*moveCount][1] = source; // From Source
        moves[*moveCount][2] = destination; // To Destination
        (*moveCount)++;
        printf("Move Disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisks(n - 1, source, auxiliary, destination, moves, moveCount);
    moves[*moveCount][0] = n; // Move disk
    moves[*moveCount][1] = source; // From Source
    moves[*moveCount][2] = destination; // To Destination
    (*moveCount)++;
    printf("Move Disk %d from %c to %c\n", n, source, destination);
    moveDisks(n - 1, auxiliary, destination, source, moves, moveCount);
}

// Function to create a 2D array for moves
int** createMovesArray(int n, int *rowCount) {
    *rowCount = (1 << n) - 1; // 2^n - 1
    int **array = malloc(*rowCount * sizeof(int*));
    for (int i = 0; i < *rowCount; i++) {
        array[i] = malloc(3 * sizeof(int)); // Each move has 3 elements
    }
    return array;
}

// Function to free the moves array
void freeMovesArray(int **array, int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks (greater than 0): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be greater than 0. Exiting.\n");
        return -1;
    }

    int movesCount = 0; // To count the number of moves
    int **moves = createMovesArray(n, &movesCount);

    // Start the Tower of Hanoi process
    moveDisks(n, 'A', 'C', 'B', moves, &movesCount);

    // Display all moves (just for reference)
    printf("\nAll Moves Recorded:\n");
    for (int i = 0; i < movesCount; i++) {
        printf("Move Disk %d from %c to %c\n", moves[i][0], moves[i][1], moves[i][2]);
    }

    // Free the allocated moves array memory
    freeMovesArray(moves, movesCount);
    
    return 0;
}