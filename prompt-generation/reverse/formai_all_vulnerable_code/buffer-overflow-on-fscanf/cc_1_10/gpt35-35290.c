//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MAZE_SIZE 100
#define MAX_THREAD_COUNT 4

int maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
int n, m, start_row, start_col, end_row, end_col, success;

pthread_t threads[MAX_THREAD_COUNT];
int thread_count = 0;

void readFile(FILE *fp) {
    fscanf(fp, "%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fscanf(fp, "%d", &maze[i][j]);
        }
    }
}

void printMaze() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void *findRoute(void *args) {
    int currentRow = *((int *)(&args));
    int nextRow;
    int nextCol;
    int nextDist;

    while (!success) {
        if (currentRow > n) {
            pthread_exit(NULL);
        }

        for (int j = 1; j <= m; j++) {
            if (maze[currentRow][j] == 1) {
                nextRow = currentRow + 1;
                nextCol = j;

                if (maze[nextRow][nextCol] == 9) {
                    success = 1;
                    pthread_exit(NULL);
                }

                if (maze[nextRow][nextCol] == 0) {
                    maze[nextRow][nextCol] = currentRow;
                    nextDist = currentRow + 1;
                    findRoute(&nextDist);
                    maze[nextRow][nextCol] = 0;
                }
            }
        }

        currentRow += thread_count;
    }
}

void start() {
    for (int i = 0; i < thread_count; i++) {
        pthread_create(&(threads[i]), NULL, findRoute, (void *)(i + 1));
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    if (success) {
        printf("Route found\n");
    } else {
        printf("Route not found\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./maze_solver file_path [thread_count]\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    readFile(fp);
    fclose(fp);

    if (argc == 3) {
        thread_count = atoi(argv[2]);
    } else {
        thread_count = 1;
    }

    printMaze();
    start();

    return 0;
}