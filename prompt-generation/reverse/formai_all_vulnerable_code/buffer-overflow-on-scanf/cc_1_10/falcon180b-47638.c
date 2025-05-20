//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_INPUT_SIZE 100

typedef struct {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE * 2];
    int thread_id;
} ThreadData;

void *color_code_converter(void *data) {
    ThreadData *thread_data = (ThreadData *)data;

    for (int i = 0; i < strlen(thread_data->input); i++) {
        if (thread_data->input[i] == '1') {
            sprintf(thread_data->output + strlen(thread_data->output), "01");
        } else if (thread_data->input[i] == '0') {
            sprintf(thread_data->output + strlen(thread_data->output), "10");
        } else {
            sprintf(thread_data->output + strlen(thread_data->output), "00");
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    int num_threads = 0;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the input string:\n");
    scanf("%s", thread_data[0].input);

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, color_code_converter, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Output:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("%d: %s\n", i, thread_data[i].output);
    }

    return 0;
}