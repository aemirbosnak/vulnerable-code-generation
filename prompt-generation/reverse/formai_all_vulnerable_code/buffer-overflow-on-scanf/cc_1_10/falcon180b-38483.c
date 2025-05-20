//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 1000
#define BUFFER_SIZE 1024

struct file_info {
    char source_path[512];
    char dest_path[512];
    int file_size;
    int is_synced;
};

void *sync_files(void *arg) {
    struct file_info *file_info = (struct file_info *) arg;
    FILE *source_file, *dest_file;
    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    source_file = fopen(file_info->source_path, "rb");
    if (source_file == NULL) {
        printf("Error opening source file: %s\n", file_info->source_path);
        exit(1);
    }

    dest_file = fopen(file_info->dest_path, "wb");
    if (dest_file == NULL) {
        printf("Error opening destination file: %s\n", file_info->dest_path);
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", file_info->dest_path);
            exit(1);
        }
    }

    fclose(source_file);
    fclose(dest_file);

    file_info->is_synced = 1;

    return NULL;
}

int main() {
    int num_files, i;
    struct file_info files[MAX_FILES];
    pthread_t threads[MAX_FILES];

    printf("Enter number of files to synchronize: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter source path for file %d: ", i+1);
        scanf("%s", files[i].source_path);

        printf("Enter destination path for file %d: ", i+1);
        scanf("%s", files[i].dest_path);

        files[i].file_size = 0;
        files[i].is_synced = 0;
    }

    for (i = 0; i < num_files; i++) {
        pthread_create(&threads[i], NULL, sync_files, (void *) &files[i]);
    }

    for (i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All files have been synchronized.\n");

    return 0;
}