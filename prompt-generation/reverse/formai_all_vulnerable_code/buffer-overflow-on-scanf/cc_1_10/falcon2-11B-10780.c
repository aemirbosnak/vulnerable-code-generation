//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_ROWS 5
#define MAX_COLS 5

struct lane {
    int cars[MAX_ROWS][MAX_COLS];
    int carsCount;
};

void readLanes(struct lane *lane, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &lane->cars[i][j]);
        }
    }
}

void printLane(struct lane *lane, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", lane->cars[i][j]);
        }
        printf("\n");
    }
}

void moveCars(struct lane *lane, int rows, int cols) {
    int i, j, carsCount;
    carsCount = lane->carsCount;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (lane->cars[i][j] > 0) {
                if (lane->cars[i][j] >= carsCount) {
                    lane->cars[i][j] -= carsCount;
                    carsCount = 0;
                }
                else {
                    carsCount -= lane->cars[i][j];
                }
            }
        }
    }
    lane->carsCount = carsCount;
}

void main() {
    struct lane lane1;
    int rows = MAX_ROWS, cols = MAX_COLS;
    readLanes(&lane1, rows, cols);
    printLane(&lane1, rows, cols);
    for (int i = 0; i < 100; i++) {
        moveCars(&lane1, rows, cols);
        printf("\n");
        printLane(&lane1, rows, cols);
    }
}