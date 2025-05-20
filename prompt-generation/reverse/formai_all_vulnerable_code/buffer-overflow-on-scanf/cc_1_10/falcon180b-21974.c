//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_INPUT_SIZE 100

typedef struct {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE * 2 + 1];
    int thread_id;
} thread_data_t;

void *convert_thread(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j;

    for (i = 0, j = 0; i < strlen(data->input) && j < MAX_INPUT_SIZE * 2; i++) {
        if (isxdigit(data->input[i])) {
            sprintf(&data->output[j], "%02x", (int) data->input[i]);
            j += 2;
        }
    }

    data->output[j] = '\0';

    pthread_exit(0);
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter input for thread %d: ", i);
        scanf("%s", data[i].input);
    }

    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i;
        pthread_create(&threads[i], NULL, convert_thread, &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_threads; i++) {
        printf("Output for thread %d: %s\n", i, data[i].output);
    }

    return 0;
}