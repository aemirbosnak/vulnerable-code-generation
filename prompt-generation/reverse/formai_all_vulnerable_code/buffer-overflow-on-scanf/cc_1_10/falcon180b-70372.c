//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_THREADS 10
#define MAX_OUTPUT_LENGTH 2048

typedef struct {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int output_length;
} input_data;

void *sanitize_input(void *arg) {
    input_data *data = arg;

    int i, j;
    for (i = 0, j = 0; i < strlen(data->input); i++) {
        if (isalnum(data->input[i])) {
            data->output[j++] = data->input[i];
        }
    }

    data->output_length = j;

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    input_data data[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        printf("Enter input for thread %d: ", i);
        scanf("%s", data[i].input);

        pthread_create(&threads[i], NULL, sanitize_input, &data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);

        printf("Sanitized input for thread %d: %s\n", i, data[i].output);
        printf("Output length for thread %d: %d\n", i, data[i].output_length);
    }

    return 0;
}