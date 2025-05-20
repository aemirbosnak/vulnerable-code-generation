//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
    int id;
} ThreadData;

void *convertRow(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int row = data->row;
    int col = data->col;
    int id = data->id;

    char *imageData = (char *) malloc(MAX_ROWS * MAX_COLS * sizeof(char));
    FILE *fp = fopen("image.bmp", "rb");
    fseek(fp, 54, SEEK_SET);
    fread(imageData, MAX_ROWS * MAX_COLS, sizeof(char), fp);
    fclose(fp);

    int asciiValue = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (i >= row && j >= col && i < row + MAX_ROWS / MAX_THREADS && j < col + MAX_COLS / MAX_THREADS) {
                asciiValue = imageData[(i - row) * MAX_COLS + (j - col)] / 16;
            }
            printf("%c", asciiValue + 33);
        }
        printf("\n");
    }

    free(imageData);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    int rows = MAX_ROWS / MAX_THREADS;
    int cols = MAX_COLS / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].row = i * rows;
        data[i].col = i * cols;
        data[i].id = i;
        pthread_create(&threads[i], NULL, convertRow, &data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}