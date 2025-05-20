//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
} ThreadData;

void *convertRow(void *arg) {
    char *image = (char *) arg;
    int row = ((ThreadData *) arg)->row;
    int colStart = row * MAX_COLS;
    int colEnd = (row + 1) * MAX_COLS - 1;
    int col;

    for (col = colStart; col <= colEnd; col++) {
        int pixel = image[col];
        if (pixel == 0) {
            printf(" ");
        } else {
            printf("#");
        }
    }
    printf("\n");

    return NULL;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    char *image;
    int width, height, i, j, ret;
    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    width = ftell(fp) / 3;
    height = MAX_ROWS;
    rewind(fp);

    image = (char *) malloc(width * height * 3);
    if (image == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ret = fread(&image[i * width * 3 + j * 3], 1, 3, fp);
            if (ret!= 3) {
                printf("Error reading file.\n");
                exit(1);
            }
        }
    }

    fclose(fp);

    for (i = 0; i < height; i++) {
        data[i].row = i;
        pthread_create(&threads[i], NULL, convertRow, (void *) &data[i]);
    }

    for (i = 0; i < height; i++) {
        pthread_join(threads[i], NULL);
    }

    free(image);

    return 0;
}