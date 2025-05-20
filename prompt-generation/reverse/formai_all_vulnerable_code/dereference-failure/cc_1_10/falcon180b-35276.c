//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUF_SIZE 1024

pthread_mutex_t mutex;
char buffer[BUF_SIZE];
int read_pos = 0;
int write_pos = 0;
int finished = 0;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    char *filename = "thread_output_file_" + thread_id;
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Thread %d: Error opening file.\n", thread_id);
        exit(1);
    }

    pthread_mutex_lock(&mutex);
    while (finished == 0) {
        if (read_pos == write_pos) {
            pthread_mutex_unlock(&mutex);
            usleep(10);
            pthread_mutex_lock(&mutex);
        } else {
            fwrite(buffer + read_pos, 1, write_pos - read_pos, fp);
            read_pos = write_pos;
        }
    }
    pthread_mutex_unlock(&mutex);

    fclose(fp);
    printf("Thread %d: Finished writing to file.\n", thread_id);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    FILE *fp = fopen("input_file", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(fp))!= EOF) {
        pthread_mutex_lock(&mutex);
        if (write_pos == BUF_SIZE) {
            write_pos = 0;
        }
        buffer[write_pos++] = c;
        pthread_mutex_unlock(&mutex);
    }

    fclose(fp);
    finished = 1;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}