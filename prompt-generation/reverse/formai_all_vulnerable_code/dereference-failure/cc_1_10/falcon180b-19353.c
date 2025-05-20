//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_THREADS 4

typedef struct {
    FILE *fp;
    int row;
    int col;
    char delimiter;
} ThreadData;

void *read_csv_row(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), data->fp)!= NULL) {
        token = strtok(line, data->delimiter);
        while (token!= NULL) {
            printf("%d:%s\n", data->row, token);
            data->col++;
            if (data->col == MAX_COLS) {
                data->col = 0;
                data->row++;
            }
            token = strtok(NULL, data->delimiter);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    ThreadData threads[MAX_THREADS];
    pthread_t thread_id[MAX_THREADS];
    int i, j;

    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        threads[i].fp = fp;
        threads[i].row = 0;
        threads[i].col = 0;
        threads[i].delimiter = argv[2][0];

        pthread_create(&thread_id[i], NULL, read_csv_row, &threads[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    fclose(fp);

    return 0;
}