//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILES 10
#define MAX_THREADS 5

struct file {
    char name[50];
    char path[100];
};

struct thread_data {
    int thread_id;
    struct file files[MAX_FILES];
};

void *backup_thread(void *arg) {
    struct thread_data *thread_data = (struct thread_data *) arg;
    int i;

    for (i = 0; i < MAX_FILES; i++) {
        if (thread_data->files[i].name[0]!= '\0') {
            printf("Thread %d backing up file %s\n", thread_data->thread_id, thread_data->files[i].name);
        }
    }

    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i + 1;
    }

    for (i = 0; i < MAX_FILES; i++) {
        printf("Enter file name and path for thread %d: ", i + 1);
        scanf("%s %s", thread_data[0].files[i].name, thread_data[0].files[i].path);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, backup_thread, (void *)&thread_data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}