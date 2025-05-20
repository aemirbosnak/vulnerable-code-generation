//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int thread_id;
} thread_data_t;

void *read_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    FILE *fp = fopen(data->filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", data->filename);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        printf("Thread %d: %s", data->thread_id, buffer);
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    int num_threads = 0;
    char filename[100];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Enter the filename for thread %d: ", i+1);
        scanf("%s", filename);
        data[i].filename = strdup(filename);
        data[i].thread_id = i+1;

        pthread_create(&threads[i], NULL, read_thread, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}