//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char input[MAX_BUFFER_SIZE];
    int input_size;
    char output[MAX_BUFFER_SIZE];
    int output_size;
} ThreadArgs;

void *compress(void *arg) {
    ThreadArgs *t = (ThreadArgs *) arg;
    char *input = t->input;
    int input_size = t->input_size;
    char *output = t->output;
    int output_size = t->output_size;

    int i, j, count;
    char prev, curr;
    count = 1;
    prev = input[0];

    for (i = 1, j = 0; i < input_size; i++) {
        curr = input[i];
        if (curr == prev) {
            count++;
        } else {
            output[j++] = prev;
            sprintf(&output[j], "%d", count);
            j += strlen(&output[j]);
            count = 1;
        }
        prev = curr;
    }

    output[j++] = prev;
    sprintf(&output[j], "%d", count);
    j += strlen(&output[j]);
    t->output_size = j;

    pthread_exit(NULL);
}

int main() {
    char input[MAX_BUFFER_SIZE];
    int input_size;
    char output[MAX_BUFFER_SIZE];
    int output_size;
    pthread_t tid;
    ThreadArgs t;

    printf("Enter string to compress:\n");
    fgets(input, MAX_BUFFER_SIZE, stdin);
    input_size = strlen(input) - 1;
    input[input_size] = '\0';

    t = (ThreadArgs) {
        .input = input,
        .input_size = input_size,
        .output = output,
        .output_size = output_size
    };

    if (pthread_create(&tid, NULL, compress, &t) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", output);

    return 0;
}