//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 100
#define MAX_THREADS 10

typedef struct {
    char input[MAX_INPUT_LENGTH];
    bool is_sanitized;
} InputData;

void *sanitize_input(void *data) {
    InputData *input_data = data;
    char *sanitized_input = malloc(MAX_INPUT_LENGTH);
    int sanitized_input_length = 0;

    for (int i = 0; i < strlen(input_data->input); i++) {
        if (isalnum(input_data->input[i])) {
            sanitized_input[sanitized_input_length++] = input_data->input[i];
        }
    }
    sanitized_input[sanitized_input_length] = '\0';

    strcpy(input_data->input, sanitized_input);
    input_data->is_sanitized = true;

    free(sanitized_input);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    InputData input_data[MAX_THREADS];
    char input[MAX_INPUT_LENGTH];

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Enter input #%d: ", i + 1);
        scanf("%s", input);
        strcpy(input_data[i].input, input);
        input_data[i].is_sanitized = false;

        pthread_create(&threads[i], NULL, sanitize_input, &input_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Sanitized input #%d: %s\n", i + 1, input_data[i].input);
    }

    return 0;
}