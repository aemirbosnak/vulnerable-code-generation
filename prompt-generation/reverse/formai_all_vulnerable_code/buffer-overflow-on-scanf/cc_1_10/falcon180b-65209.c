//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 100000

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct thread_data {
    int thread_id;
    char *file_name;
    int file_size;
};

void *backup_thread(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    FILE *fp;
    char *buffer = (char *) malloc(data->file_size);

    fp = fopen(data->file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", data->file_name);
        exit(1);
    }

    fread(buffer, 1, data->file_size, fp);
    fclose(fp);

    pthread_mutex_lock(&mutex);
    printf("Thread %d backed up file %s of size %d bytes\n", data->thread_id, data->file_name, data->file_size);
    pthread_mutex_unlock(&mutex);

    free(buffer);
    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    // Initialize random seed
    srand(time(NULL));

    // Get number of threads from user
    printf("Enter number of threads (max %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // Fill thread data array
    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        data[i].file_name = (char *) malloc(20);
        sprintf(data[i].file_name, "file_%d.txt", i + 1);
        data[i].file_size = rand() % MAX_FILE_SIZE + 1;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, backup_thread, &data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}