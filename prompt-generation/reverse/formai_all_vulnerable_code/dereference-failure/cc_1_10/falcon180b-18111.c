//Falcon-180B DATASET v1.0 Category: File handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_LINE_LEN 1024

FILE *fp;
char filename[50] = "example.txt";
char *line = NULL;
size_t len = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *read_file(void *arg) {
    int thread_num = *((int *) arg);
    char thread_name[10];
    sprintf(thread_name, "Thread %d", thread_num + 1);
    pthread_setname_np(pthread_self(), thread_name);

    while (1) {
        pthread_mutex_lock(&mutex);
        if (line == NULL) {
            line = malloc(MAX_LINE_LEN);
            if (line == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }
            if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
                printf("Thread %s has finished reading.\n", thread_name);
                pthread_exit(NULL);
            }
        }
        pthread_mutex_unlock(&mutex);

        if (strlen(line) > 0) {
            printf("Thread %s: %s", thread_name, line);
        }
        sleep(1);
    }
}

int main() {
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, read_file, &i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}