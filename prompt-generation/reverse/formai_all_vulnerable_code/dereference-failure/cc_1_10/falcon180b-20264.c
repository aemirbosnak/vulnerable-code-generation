//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

typedef struct {
    char path[MAX_PATH];
    int fd;
} file_t;

typedef struct {
    char src_path[MAX_PATH];
    char dest_path[MAX_PATH];
} sync_t;

void *sync_thread(void *arg) {
    sync_t *sync = (sync_t *) arg;

    FILE *src_file = fopen(sync->src_path, "r");
    if (!src_file) {
        fprintf(stderr, "Error opening source file: %s\n", sync->src_path);
        exit(1);
    }

    FILE *dest_file = fopen(sync->dest_path, "w");
    if (!dest_file) {
        fprintf(stderr, "Error opening destination file: %s\n", sync->dest_path);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, src_file)!= NULL) {
        fputs(buffer, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s [source_file] [destination_file]\n", argv[0]);
        exit(1);
    }

    sync_t sync;
    strcpy(sync.src_path, argv[1]);
    strcpy(sync.dest_path, argv[2]);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, sync_thread, &sync);

    pthread_join(thread_id, NULL);

    return 0;
}