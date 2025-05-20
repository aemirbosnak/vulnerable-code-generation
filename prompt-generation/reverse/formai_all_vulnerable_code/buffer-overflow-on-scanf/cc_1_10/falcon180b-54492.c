//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char source[MAX_FILES][100];
    char destination[MAX_FILES][100];
    int count;
} file_list;

void *copy_file(void *arg) {
    int i = *(int *) arg;
    char source[100], destination[100];
    strcpy(source, ((file_list *) arg)->source[i]);
    strcpy(destination, ((file_list *) arg)->destination[i]);

    FILE *fp_src, *fp_dest;
    fp_src = fopen(source, "rb");
    if (fp_src == NULL) {
        printf("Error: Could not open source file %s\n", source);
        exit(1);
    }

    fp_dest = fopen(destination, "wb");
    if (fp_dest == NULL) {
        printf("Error: Could not open destination file %s\n", destination);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, fp_src) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE, fp_dest);
    }

    fclose(fp_src);
    fclose(fp_dest);
}

int main() {
    int num_files;
    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    file_list fl;
    fl.count = num_files;

    printf("Enter the source and destination paths for each file:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %d:\n", i+1);
        printf("Source path: ");
        scanf("%s", fl.source[i]);
        printf("Destination path: ");
        scanf("%s", fl.destination[i]);
    }

    pthread_t threads[MAX_THREADS];
    int num_threads = num_files;
    if (num_files > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    for (int i = 0; i < num_threads; i++) {
        int index = i * (num_files / num_threads) + 1;
        pthread_create(&threads[i], NULL, copy_file, (void *) &index);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("File synchronization completed successfully.\n");
    return 0;
}