//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char input_file[256];
    char output_file[256];
} thread_data;

void *recovery_thread(void *arg) {
    thread_data *data = (thread_data *) arg;

    FILE *input_file = fopen(data->input_file, "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", data->input_file);
        exit(1);
    }

    FILE *output_file = fopen(data->output_file, "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", data->output_file);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Recovery thread %d completed.\n", data->id);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    int num_threads = 0;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Enter input file path for thread %d: ", i+1);
        scanf("%s", data[i].input_file);

        printf("Enter output file path for thread %d: ", i+1);
        scanf("%s", data[i].output_file);

        pthread_create(&threads[i], NULL, recovery_thread, (void *)&data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}