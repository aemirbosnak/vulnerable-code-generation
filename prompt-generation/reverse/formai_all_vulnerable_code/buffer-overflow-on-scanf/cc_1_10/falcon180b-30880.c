//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_THREADS 10

typedef struct {
    char filename[100];
    int file_size;
    int thread_id;
} FileInfo;

FileInfo files[MAX_FILES];
pthread_t threads[MAX_THREADS];
int num_files = 0;
int num_threads = 0;

void *backup_thread(void *arg);

int main() {
    int i, j, choice;

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter filename for file %d: ", i+1);
        scanf("%s", files[i].filename);
        printf("Enter filesize for file %s: ", files[i].filename);
        scanf("%d", &files[i].file_size);
    }

    printf("Enter the number of threads to use: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter thread id for thread %d: ", i+1);
        scanf("%d", &threads[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, backup_thread, (void *)i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Backup complete!\n");

    return 0;
}

void *backup_thread(void *arg) {
    int thread_id = *(int *)arg;
    int i, j;

    for (i = thread_id; i < num_files; i += num_threads) {
        for (j = 0; j < files[i].file_size; j++) {
            printf("Backing up file %s (%d bytes) on thread %d...\n", files[i].filename, files[i].file_size, thread_id);
        }
    }

    return NULL;
}