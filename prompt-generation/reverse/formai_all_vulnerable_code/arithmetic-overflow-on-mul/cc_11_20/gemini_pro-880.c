//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int x, y;
} point;

int width, height;
int **grid;
int **next;
pthread_mutex_t mutex;

void* thread_func(void *arg) {
    point *p = (point*)arg;
    int x = p->x, y = p->y;
    int neighbors = 0;

    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            if (i >= 0 && i < width && j >= 0 && j < height && !(i == x && j == y)) {
                neighbors += grid[i][j];
            }
        }
    }

    pthread_mutex_lock(&mutex);
    if (neighbors == 3) {
        next[x][y] = 1;
    } else if (neighbors == 2) {
        next[x][y] = grid[x][y];
    } else {
        next[x][y] = 0;
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    srand(time(NULL));

    printf("Enter width and height: ");
    scanf("%d %d", &width, &height);

    grid = (int**)malloc(width * sizeof(int*));
    next = (int**)malloc(width * sizeof(int*));
    for (int i = 0; i < width; i++) {
        grid[i] = (int*)malloc(height * sizeof(int));
        next[i] = (int*)malloc(height * sizeof(int));
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    pthread_t threads[width * height];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            point p = {i, j};
            pthread_create(&threads[i * height + j], NULL, thread_func, &p);
        }
    }

    for (int i = 0; i < width * height; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j] = next[i][j];
        }
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < width; i++) {
        free(grid[i]);
        free(next[i]);
    }
    free(grid);
    free(next);

    return 0;
}