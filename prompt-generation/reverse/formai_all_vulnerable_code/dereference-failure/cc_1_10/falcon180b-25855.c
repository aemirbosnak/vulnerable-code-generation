//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
} file_t;

void *scan_file(void *arg) {
    file_t *file = (file_t *) arg;
    char buffer[BUFFER_SIZE];
    int found_virus = 0;

    while (fgets(buffer, BUFFER_SIZE, file->file)!= NULL) {
        if (strstr(buffer, "virus")!= NULL) {
            printf("Virus found in %s\n", file->filename);
            found_virus = 1;
            break;
        }
    }

    if (!found_virus) {
        printf("%s is clean\n", file->filename);
    }

    fclose(file->file);
    free(file->filename);
    free(file);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    file_t files[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        files[i].filename = (char *) malloc(20);
        sprintf(files[i].filename, "file_%d.txt", i);
        files[i].file = fopen(files[i].filename, "w");
        if (files[i].file == NULL) {
            printf("Error creating file %s\n", files[i].filename);
            exit(1);
        }

        pthread_create(&threads[i], NULL, scan_file, &files[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}