//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 //Size of the grid

int grid[SIZE][SIZE]; //2D integer array to represent the grid

int findRoot(int root[], int i) {
    while (root[i] != i) {
        i = root[i];
    }
    return i;
}

void unionNodes(int root[], int i, int j) {
    int rootI = findRoot(root, i);
    int rootJ = findRoot(root, j);
    root[rootJ] = rootI;
}

bool isConnected(int root[], int p, int q) {
    return (findRoot(root, p) == findRoot(root, q));
}

int percolates() {
    //Initialise an array to track roots
    int root[SIZE*SIZE+1];
    for (int i = 0; i < SIZE*SIZE+1; i++) {
        root[i] = i; //Each element starts with its own root
    }
    //Set bottom row to be connected to virtual root (index 0)
    for (int j = SIZE*(SIZE-1)+1; j < SIZE*SIZE+1; j++) {
        unionNodes(root, 0, j);
    }
    //Generate random positions to open nodes
    srand(time(NULL));
    int openPos[SIZE*SIZE];
    for (int i = 0; i < SIZE*SIZE; i++) {
        openPos[i] = i+1;
    }
    for (int i = 0; i < SIZE*SIZE; i++) {
        int j = rand()%(SIZE*SIZE-i)+i;
        int temp = openPos[i];
        openPos[i] = openPos[j];
        openPos[j] = temp;
    }
    //Open nodes until top row is connected to virtual root
    for (int i = 0; i < SIZE*SIZE; i++) {
        int row = (openPos[i]-1)/SIZE+1;
        int col = (openPos[i]-1)%SIZE+1;
        int idx = openPos[i];
        grid[row][col] = 1;
        if (row == 1) { //Connect top row to virtual root
            unionNodes(root, 0, idx);
        }
        if (row > 1 && grid[row-1][col] == 1) { //Connect adjacent nodes
            unionNodes(root, idx, idx-SIZE);
        }
        if (row < SIZE && grid[row+1][col] == 1) {
            unionNodes(root, idx, idx+SIZE);
        }
        if (col > 1 && grid[row][col-1] == 1) {
            unionNodes(root, idx, idx-1);
        }
        if (col < SIZE && grid[row][col+1] == 1) {
            unionNodes(root, idx, idx+1);
        }
        if (isConnected(root, 0, idx)) { //Percolation occurs
            return i+1;
        }
    }
    return -1; //Percolation does not occur
}

int main() {
    int numTrials = 10000;
    int numPercolate = 0;
    for (int i = 0; i < numTrials; i++) {
        //Reset grid for each trial
        for (int row = 1; row <= SIZE; row++) {
            for (int col = 1; col <= SIZE; col++) {
                grid[row][col] = 0;
            }
        }
        int steps = percolates();
        if (steps != -1) {
            numPercolate++;
        }
    }
    printf("Probability of percolation: %.2f%%\n", (float)numPercolate/numTrials*100);
    return 0;
}