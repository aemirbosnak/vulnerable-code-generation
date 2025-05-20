//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000

int thread_count = 0;
char *line = NULL;

typedef struct ThreadData {
    int thread_id;
    char *line;
} ThreadData;

void *thread_func(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    int thread_id = thread_data->thread_id;
    char *line = thread_data->line;

    printf("Thread %d processing line: %s\n", thread_id, line);

    // Perform parsing operations on the line here

    pthread_exit(NULL);
}

int main() {
    FILE *file = fopen("input_file.txt", "r");
    ThreadData thread_data[MAX_THREADS];

    if (file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        thread_count++;
        thread_data[thread_count - 1].thread_id = thread_count;
        thread_data[thread_count - 1].line = line;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, (void *) &thread_data[thread_count - 1]);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(thread_data[i].thread_id, NULL);
    }

    return 0;
}