//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024
#define MAX_THREADS 10

struct input_data {
    char input[MAX_INPUT_SIZE];
    int sanitized;
};

void *sanitize_input(void *arg) {
    struct input_data *data = (struct input_data *) arg;

    if (strlen(data->input) >= MAX_INPUT_SIZE) {
        strncpy(data->input, "Input too long", MAX_INPUT_SIZE);
        data->sanitized = 1;
    } else {
        data->sanitized = 0;
    }

    return NULL;
}

int main() {
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    struct input_data input_data[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Enter input for thread %d: ", i);
        scanf("%s", input_data[i].input);

        pthread_create(&threads[i], NULL, sanitize_input, &input_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);

        if (input_data[i].sanitized) {
            printf("Sanitized input for thread %d: %s\n", i, input_data[i].input);
        } else {
            printf("Unsanitized input for thread %d: %s\n", i, input_data[i].input);
        }
    }

    return 0;
}