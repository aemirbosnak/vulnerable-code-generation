//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#define MAX_ROWS 100
#define MAX_COLS 1000

typedef struct {
    char delimiter;
    FILE *fp;
    int num_threads;
    pthread_t threads[MAX_ROWS];
} CSVReader;

void *read_csv_row(void *arg) {
    int row = *(int *) arg;
    CSVReader *reader = (CSVReader *) arg;

    char buffer[MAX_COLS];
    char *token = NULL;
    int cols = 0;

    rewind(reader->fp);
    for (int i = 0; i < row; i++) {
        fgets(buffer, MAX_COLS, reader->fp);
    }

    fgets(buffer, MAX_COLS, reader->fp);
    token = strtok(buffer, reader->delimiter);

    while (token!= NULL) {
        printf("%s ", token);
        cols++;
        token = strtok(NULL, reader->delimiter);
    }

    printf("\n");

    pthread_exit(NULL);
}

CSVReader *create_csv_reader(FILE *fp, char delimiter, int num_threads) {
    CSVReader *reader = (CSVReader *) malloc(sizeof(CSVReader));

    reader->delimiter = delimiter;
    reader->fp = fp;
    reader->num_threads = num_threads;

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&reader->threads[i], NULL, read_csv_row, (void *) &i);
    }

    return reader;
}

void destroy_csv_reader(CSVReader *reader) {
    for (int i = 0; i < reader->num_threads; i++) {
        pthread_join(reader->threads[i], NULL);
    }

    fclose(reader->fp);
    free(reader);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    CSVReader *reader = create_csv_reader(fp, ',', 4);

    fclose(fp);

    sleep(5);

    destroy_csv_reader(reader);

    return 0;
}