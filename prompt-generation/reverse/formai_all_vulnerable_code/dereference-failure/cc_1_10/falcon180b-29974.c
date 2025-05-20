//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct {
    char *filename;
    char *buffer;
    int size;
    int id;
} file_t;

void *thread_func(void *arg) {
    file_t *file = (file_t *) arg;
    FILE *fp = fopen(file->filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", file->filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);
    file->buffer = (char *) malloc(file->size + 1);
    if (file->buffer == NULL) {
        printf("Error: Cannot allocate memory for file %s\n", file->filename);
        exit(1);
    }
    fread(file->buffer, file->size, 1, fp);
    fclose(fp);
    printf("Thread %d has synchronized file %s\n", file->id, file->filename);
    pthread_exit(0);
}

int main() {
    int i, num_files;
    char filename[MAX_FILE_SIZE];
    file_t *files = (file_t *) malloc(MAX_THREADS * sizeof(file_t));
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i + 1);
        scanf("%s", filename);
        files[i].filename = strdup(filename);
        files[i].buffer = NULL;
        files[i].size = 0;
        files[i].id = i + 1;
    }

    for (i = 0; i < num_files; i++) {
        pthread_create(&threads[i], NULL, thread_func, &files[i]);
    }

    for (i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_files; i++) {
        free(files[i].filename);
        free(files[i].buffer);
    }
    free(files);

    return 0;
}