//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_FILE_SIZE 1024

typedef struct {
    char filename[100];
    char metadata[MAX_FILE_SIZE];
} file_metadata_t;

void *extract_metadata(void *arg) {
    file_metadata_t *file_data = (file_metadata_t *) arg;
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen(file_data->filename, "r");
    if (fp == NULL) {
        printf("Error: File %s not found\n", file_data->filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (count < MAX_FILE_SIZE - 1) {
            file_data->metadata[count] = ch;
            count++;
        }
    }

    fclose(fp);
    file_data->metadata[count] = '\0';

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    file_metadata_t files[MAX_THREADS];
    int i, j;

    printf("Enter filenames (up to %d):\n", MAX_THREADS);
    for (i = 0; i < MAX_THREADS; i++) {
        scanf("%s", files[i].filename);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, extract_metadata, (void *) &files[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Metadata extraction complete\n");

    for (i = 0; i < MAX_THREADS; i++) {
        printf("Filename: %s\n", files[i].filename);
        printf("Metadata: %s\n", files[i].metadata);
        printf("\n");
    }

    return 0;
}