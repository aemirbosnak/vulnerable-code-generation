//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BLOCK_SIZE 8
#define KEY_SIZE 16

typedef struct {
    char* data;
    int length;
} block_t;

void* encrypt_block(void* arg) {
    block_t* block = (block_t*) arg;
    char* key = "mysecretkey";
    char* result = malloc(block->length);

    for (int i = 0; i < block->length; i++) {
        result[i] = block->data[i] ^ key[i % KEY_SIZE];
    }

    printf("Thread %d encrypted block %d\n", pthread_self(), block->length);

    return result;
}

void* decrypt_block(void* arg) {
    block_t* block = (block_t*) arg;
    char* key = "mysecretkey";
    char* result = malloc(block->length);

    for (int i = 0; i < block->length; i++) {
        result[i] = block->data[i] ^ key[i % KEY_SIZE];
    }

    printf("Thread %d decrypted block %d\n", pthread_self(), block->length);

    return result;
}

int main() {
    block_t* blocks = malloc(sizeof(block_t) * 10);

    for (int i = 0; i < 10; i++) {
        blocks[i].data = malloc(BLOCK_SIZE);
        blocks[i].length = BLOCK_SIZE;

        for (int j = 0; j < BLOCK_SIZE; j++) {
            blocks[i].data[j] = 'A' + i * BLOCK_SIZE + j;
        }
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, encrypt_block, &blocks[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; i++) {
        free(blocks[i].data);
    }

    free(blocks);

    return 0;
}