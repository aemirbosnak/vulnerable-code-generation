//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    char *input;
    char *output;
    int start;
    int end;
    int shift;
} thread_data;

void *encrypt(void *arg) {
    thread_data *data = (thread_data *)arg;
    for (int i = data->start; i < data->end; i++) {
        if (data->input[i] >= 'a' && data->input[i] <= 'z') {
            data->output[i] = (data->input[i] - 'a' + data->shift) % 26 + 'a';
        } else if (data->input[i] >= 'A' && data->input[i] <= 'Z') {
            data->output[i] = (data->input[i] - 'A' + data->shift) % 26 + 'A';
        } else {
            data->output[i] = data->input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    return NULL;
}

void perform_encryption(char *input, char *output, int shift, int num_threads) {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    int len = strlen(input);
    int chunk_size = len / num_threads;

    for (int i = 0; i < num_threads; i++) {
        data[i].input = input;
        data[i].output = output;
        data[i].shift = shift;
        data[i].start = i * chunk_size;
        data[i].end = (i == num_threads - 1) ? len : data[i].start + chunk_size;

        pthread_create(&threads[i], NULL, encrypt, (void *)&data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Invalid shift value. It should be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    printf("Encrypting with %d threads...\n", MAX_THREADS);
    perform_encryption(input, output, shift, MAX_THREADS);
    
    output[strlen(input)] = '\0'; // Null-terminate the output string
    printf("Encrypted string: %s\n", output);

    return EXIT_SUCCESS;
}