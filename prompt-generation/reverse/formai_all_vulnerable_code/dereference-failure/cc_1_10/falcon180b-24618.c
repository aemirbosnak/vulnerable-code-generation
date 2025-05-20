//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 16
#define MAX_ROWS 100000
#define MAX_COLS 16

typedef struct {
    FILE *fp;
    char delimiter;
    int row;
    int col;
} CSVReader;

void *readCSV(void *arg) {
    CSVReader *reader = (CSVReader *) arg;
    char line[MAX_ROWS];
    char *token;
    int i;

    while (fgets(line, MAX_ROWS, reader->fp)!= NULL) {
        token = strtok(line, reader->delimiter);
        for (i = 0; i < MAX_COLS; i++) {
            if (token!= NULL) {
                printf("%c%d = %s\n", reader->delimiter, reader->col++, token);
            } else {
                break;
            }
            token = strtok(NULL, reader->delimiter);
        }
        reader->row++;
    }

    return NULL;
}

int main(int argc, char **argv) {
    int i, numThreads = 1;
    pthread_t threads[MAX_THREADS];
    CSVReader readers[MAX_THREADS];

    if (argc!= 4) {
        printf("Usage: %s <filename> <delimiter> <numThreads>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        readers[i].fp = fopen(argv[1], "r");
        if (readers[i].fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        readers[i].delimiter = argv[2][0];
        readers[i].row = 0;
        readers[i].col = 0;
    }

    if (numThreads > MAX_THREADS) {
        numThreads = MAX_THREADS;
    }

    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, readCSV, &readers[i]);
    }

    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        fclose(readers[i].fp);
    }

    return 0;
}