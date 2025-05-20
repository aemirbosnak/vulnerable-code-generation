//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_THREADS 4

typedef struct {
    int start_row;
    int end_row;
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    FILE *fp = fopen("data.csv", "r");
    char line[1024];
    int count = 0;

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    if (data->start_row == 0) {
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s", line);
            count++;
            if (count == MAX_ROWS) {
                break;
            }
        }
    } else {
        fseek(fp, (long) (data->start_row - 1) * sizeof(line), SEEK_SET);
        while (fgets(line, sizeof(line), fp)!= NULL) {
            printf("%s", line);
            count++;
            if (count == (data->end_row - data->start_row + 1)) {
                break;
            }
        }
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];
    int i, rows, cols, start_row, end_row;
    FILE *fp;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d,%d", &rows, &cols);
    fclose(fp);

    start_row = 0;
    end_row = rows / MAX_THREADS;

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].start_row = start_row;
        data[i].end_row = (i == MAX_THREADS - 1)? rows : end_row;
        pthread_create(&threads[i], NULL, thread_func, (void *) &data[i]);
        start_row = data[i].end_row + 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}