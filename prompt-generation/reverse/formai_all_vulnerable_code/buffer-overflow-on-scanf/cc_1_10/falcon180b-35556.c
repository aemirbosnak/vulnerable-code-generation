//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 100000000

pthread_t threads[MAX_THREADS];

typedef struct {
    char filename[100];
    int start_index;
    int end_index;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *file = fopen(data->filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", data->filename);
        return NULL;
    }

    char *buffer = (char *) malloc(MAX_FILE_SIZE);
    fseek(file, data->start_index, SEEK_SET);
    int bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);

    int i = 0;
    while (i < bytes_read) {
        if (buffer[i] == '\0') {
            printf("Deleted data found at position %d\n", i + data->start_index);
        }
        i++;
    }

    free(buffer);
    fclose(file);
    return NULL;
}

int main() {
    int num_files = 0;
    char filename[100];

    printf("Enter the number of files to recover data from: ");
    scanf("%d", &num_files);

    printf("Enter the filenames:\n");
    for (int i = 0; i < num_files; i++) {
        scanf("%s", filename);

        thread_data data;
        strcpy(data.filename, filename);
        data.start_index = 0;
        data.end_index = MAX_FILE_SIZE - 1;

        pthread_create(&threads[i], NULL, thread_func, (void *) &data);
    }

    for (int i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}