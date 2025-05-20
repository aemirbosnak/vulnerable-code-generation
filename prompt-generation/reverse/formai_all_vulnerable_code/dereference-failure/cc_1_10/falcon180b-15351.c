//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define NUM_THREADS 4

struct thread_data {
    char *filename;
    FILE *file;
    int thread_id;
};

void *scan_file(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), data->file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (isalpha(buffer[i])) {
                printf("Possible virus detected in file %s at line %d\n", data->filename, i + 1);
                break;
            }
        }
    }

    fclose(data->file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *filenames[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt"};
    FILE *files[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        files[i] = fopen(filenames[i], "r");
        if (files[i] == NULL) {
            printf("Error opening file %s\n", filenames[i]);
            exit(1);
        }

        thread_data[i].filename = filenames[i];
        thread_data[i].file = files[i];
        thread_data[i].thread_id = i;

        pthread_create(&threads[i], NULL, scan_file, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}