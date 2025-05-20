//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ROWS 10
#define NUM_COLS 10

int map[NUM_ROWS][NUM_COLS];
int startRow, startCol, endRow, endCol;
int path[NUM_ROWS][NUM_COLS];

void* pathfinding(void* arg) {
    int row = *(int*)arg;
    int col = 0;
    int pathIndex = 0;
    path[row][col] = 1;
    while(col < NUM_COLS - 1) {
        if(map[row][col] == 0 && map[row][col + 1] == 0) {
            col++;
            path[row][col] = 1;
        } else {
            path[row][col] = 0;
            col -= 2;
        }
        pathIndex++;
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLS; j++) {
            map[i][j] = rand() % 2;
        }
    }
    printf("Enter starting coordinates (in format row,col): ");
    scanf("%d,%d", &startRow, &startCol);
    printf("Enter ending coordinates (in format row,col): ");
    scanf("%d,%d", &endRow, &endCol);
    pthread_t threads[NUM_THREADS];
    int rowsPerThread = NUM_ROWS / NUM_THREADS;
    for(int i = 0; i < NUM_THREADS; i++) {
        int startRowT = i * rowsPerThread;
        int endRowT = (i == NUM_THREADS - 1)? NUM_ROWS - 1 : (i + 1) * rowsPerThread - 1;
        int* rowArgs[NUM_COLS];
        for(int j = 0; j < NUM_COLS; j++) {
            rowArgs[j] = &startRowT;
        }
        pthread_create(&threads[i], NULL, pathfinding, rowArgs);
    }
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Path:\n");
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLS; j++) {
            if(path[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    return 0;
}