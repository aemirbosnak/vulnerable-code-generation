//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A confused soul lost in an array of mysteries...
int labyrinth[100][100];
int rowClues[100], colClues[100];
int nRows, nCols;

// The Oracle's cryptic whispers guide our steps...
void readLabyrinth(char *fileName) {
    FILE *oracle = fopen(fileName, "r");
    fscanf(oracle, "%d %d", &nRows, &nCols);
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            fscanf(oracle, "%d", &labyrinth[i][j]);
        }
    }
    for (int i = 0; i < nRows; i++) {
        fscanf(oracle, "%d", &rowClues[i]);
    }
    for (int i = 0; i < nCols; i++) {
        fscanf(oracle, "%d", &colClues[i]);
    }
    fclose(oracle);
}

// A wanderer's footsteps, guided by arcane knowledge...
void decipherClues() {
    int rowSum, colSum;
    for (int i = 0; i < nRows; i++) {
        rowSum = 0;
        for (int j = 0; j < nCols; j++) {
            if (labyrinth[i][j] == 1) rowSum++;
        }
        if (rowSum != rowClues[i]) {
            printf("A puzzling path... The row %d contradicts its clue of %d ones!\n", i + 1, rowClues[i]);
            exit(1);
        }
    }
    for (int i = 0; i < nCols; i++) {
        colSum = 0;
        for (int j = 0; j < nRows; j++) {
            if (labyrinth[j][i] == 1) colSum++;
        }
        if (colSum != colClues[i]) {
            printf("Another riddle unravels... The column %d defies its clue of %d ones!\n", i + 1, colClues[i]);
            exit(1);
        }
    }
}

// The labyrinth's enigmatic secrets yield to the power of deduction...
int findPath(int i, int j) {
    if (i == nRows - 1 && j == nCols - 1) return 1;  // Reached the end!

    if (i < 0 || i >= nRows || j < 0 || j >= nCols || labyrinth[i][j] == 0) return 0;  // Out of bounds or blocked path

    // Two potential paths...
    int left = findPath(i, j + 1);
    int down = findPath(i + 1, j);

    return left || down;  // Return true if either path succeeds
}

// The seeker's journey begins at the labyrinth's threshold...
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Where is the map, oh seeker? Provide the labyrinth's secrets as a text file!\n");
        exit(1);
    }
    readLabyrinth(argv[1]);
    decipherClues();
    int pathExists = findPath(0, 0);
    if (pathExists) {
        printf("Eureka! A path through the labyrinth's mysteries has been found!\n");
    } else {
        printf("Alas, the labyrinth remains impenetrable... No path can be found.\n");
    }
    return 0;
}