//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define BLOCK_SIZE 256
#define NUM_THREADS 4

typedef struct {
    char *plaintext;
    char *ciphertext;
    int blockIndex;
    int shift;
} ThreadData;

void *encrypt_block(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *plaintext = data->plaintext;
    char *ciphertext = data->ciphertext;
    int start_idx = data->blockIndex * BLOCK_SIZE;
    int end_idx = start_idx + BLOCK_SIZE;

    for (int i = start_idx; i < end_idx && plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + data->shift) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + data->shift) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters are not changed
        }
    }
    ciphertext[end_idx] = '\0'; // Null-terminate the ciphertext
    return NULL;
}

void encrypt_text(const char *plaintext, char *ciphertext, int shift) {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].plaintext = (char *)plaintext;
        threadData[i].ciphertext = ciphertext;
        threadData[i].blockIndex = i;
        threadData[i].shift = shift;

        pthread_create(&threads[i], NULL, encrypt_block, (void *)&threadData[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char plaintext[MAX_TEXT_LENGTH];
    char ciphertext[MAX_TEXT_LENGTH];
    int shift;

    printf("Enter plaintext (max 1024 characters): ");
    fgets(plaintext, MAX_TEXT_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    printf("Enter shift value for Caesar cipher: ");
    scanf("%d", &shift);
    
    // Normalize the shift value to be within 0-25
    shift = (shift % 26 + 26) % 26;

    // Initialize ciphertext
    memset(ciphertext, 0, sizeof(ciphertext));
    
    encrypt_text(plaintext, ciphertext, shift);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    return 0;
}