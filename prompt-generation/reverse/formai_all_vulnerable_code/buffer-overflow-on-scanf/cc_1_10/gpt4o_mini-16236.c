//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void initializeMagicSquare(int **magicSquare, int size);
void fillMagicSquare(int **magicSquare, int row, int col, int value, int size);
void displayMagicSquare(int **magicSquare, int size);
int allocateMemory(int ***magicSquare, int size);
void deallocateMemory(int **magicSquare, int size);

int main() {
    int size;
    printf("Enter an odd integer size for the magic square: ");
    scanf("%d", &size);

    if(size % 2 == 0 || size < 1) {
        printf("Please enter a valid odd integer greater than 0.\n");
        return 1;
    }

    int **magicSquare;

    if (allocateMemory(&magicSquare, size) != 0) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    initializeMagicSquare(magicSquare, size);
    fillMagicSquare(magicSquare, 0, size / 2, 1, size);
    displayMagicSquare(magicSquare, size);

    deallocateMemory(magicSquare, size);
    return 0;
}

int allocateMemory(int ***magicSquare, int size) {
    *magicSquare = (int **)malloc(size * sizeof(int *));
    if (*magicSquare == NULL) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        (*magicSquare)[i] = (int *)malloc(size * sizeof(int));
        if ((*magicSquare)[i] == NULL) {
            return -1;
        }
    }
    return 0;
}

void deallocateMemory(int **magicSquare, int size) {
    for (int i = 0; i < size; i++) {
        free(magicSquare[i]);
    }
    free(magicSquare);
}

void initializeMagicSquare(int **magicSquare, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            magicSquare[i][j] = 0;
        }
    }
}

void fillMagicSquare(int **magicSquare, int row, int col, int value, int size) {
    if (value > size * size) {
        return; // Base case: all values have been placed
    }

    magicSquare[row][col] = value; // Place the current value

    int newRow = (row - 1 + size) % size; // Move up
    int newCol = (col + 1) % size;         // Move right

    if (magicSquare[newRow][newCol] != 0) { // If the position is already filled
        newRow = (row + 1) % size; // Move down instead
        newCol = col;               // Stay in the same column
    }

    fillMagicSquare(magicSquare, newRow, newCol, value + 1, size); // Recursive call for the next value
}

void displayMagicSquare(int **magicSquare, int size) {
    printf("The generated magic square of size %d is:\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}