//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024
#define NUM_THREADS 4

typedef struct {
    char *input;
    char *output;
    int start;
    int end;
    int key;
} ThreadData;

void *encrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->start; i < data->end; i++) {
        data->output[i] = data->input[i] + data->key;
    }
    return NULL;
}

void *decrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->start; i < data->end; i++) {
        data->output[i] = data->input[i] - data->key;
    }
    return NULL;
}

void create_threads(char *input, char *output, int length, int key, int is_encrypt) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int segment_length = length / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].input = input;
        thread_data[i].output = output;
        thread_data[i].key = key;
        thread_data[i].start = i * segment_length;
        if (i == NUM_THREADS - 1) {
            thread_data[i].end = length; // Handle remainder on last thread
        } else {
            thread_data[i].end = (i + 1) * segment_length;
        }

        if (is_encrypt) {
            pthread_create(&threads[i], NULL, encrypt, (void *)&thread_data[i]);
        } else {
            pthread_create(&threads[i], NULL, decrypt, (void *)&thread_data[i]);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH];
    int key;
    char choice;

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("Enter encryption key (integer): ");
    scanf("%d", &key);
    getchar(); // To consume the newline character after scanf

    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    choice = getchar();

    int length = strlen(input);
    if (choice == 'e') {
        create_threads(input, output, length, key, 1);
        output[length] = '\0'; // Null-terminate the encrypted string
        printf("Encrypted string: %s\n", output);
    } else if (choice == 'd') {
        create_threads(input, output, length, key, 0);
        output[length] = '\0'; // Null-terminate the decrypted string
        printf("Decrypted string: %s\n", output);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}