//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

char input_buffer[BUFFER_SIZE];
char output_buffer[BUFFER_SIZE];

void *encrypt_thread(void *arg) {
    char *input = (char *) arg;
    strcpy(input_buffer, input);

    for (int i = 0; i < strlen(input_buffer); i++) {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'z') {
            input_buffer[i] = input_buffer[i] + 13;
        } else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'Z') {
            input_buffer[i] = input_buffer[i] - 13;
        }
    }

    strcpy(output_buffer, input_buffer);

    return output_buffer;
}

void *decrypt_thread(void *arg) {
    char *input = (char *) arg;
    strcpy(input_buffer, input);

    for (int i = 0; i < strlen(input_buffer); i++) {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'z') {
            input_buffer[i] = input_buffer[i] - 13;
        } else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'Z') {
            input_buffer[i] = input_buffer[i] + 13;
        }
    }

    strcpy(output_buffer, input_buffer);

    return output_buffer;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char input[BUFFER_SIZE];

    printf("Enter input string: ");
    scanf("%s", input);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, encrypt_thread, input);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encrypted string: %s\n", output_buffer);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, decrypt_thread, input_buffer);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Decrypted string: %s\n", output_buffer);

    return 0;
}