//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1000

char input_buffer[BUFFER_SIZE];
int input_index = 0;

void *process_input(void *arg) {
    char *output_buffer = malloc(BUFFER_SIZE);
    int output_index = 0;

    while (input_index < BUFFER_SIZE) {
        char c = input_buffer[input_index];
        if (isalpha(c)) {
            c = toupper(c);
            strncat(output_buffer, &c, 1);
            output_index++;
        }
        input_index++;
    }

    printf("Thread %d processed input and generated output: %s\n", *(int *)arg, output_buffer);
    free(output_buffer);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while (scanf("%c", &input_buffer[input_index])!= EOF) {
        input_index++;

        if (thread_count < MAX_THREADS && input_index >= BUFFER_SIZE) {
            pthread_create(&threads[thread_count], NULL, process_input, &thread_count);
            thread_count++;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}