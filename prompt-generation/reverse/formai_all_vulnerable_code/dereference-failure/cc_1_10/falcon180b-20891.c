//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MSG_SIZE 64
#define KEY_SIZE 16

char *msg;
char *key;
char *encrypted_msg;

void * encrypt_thread(void *arg) {
    int thread_id = *(int *) arg;
    int start_pos = thread_id * MSG_SIZE / NUM_THREADS;
    int end_pos = (thread_id + 1) * MSG_SIZE / NUM_THREADS;

    for (int i = start_pos; i < end_pos; i++) {
        encrypted_msg[i] = msg[i] ^ key[i % KEY_SIZE];
    }

    pthread_exit(0);
}

void * decrypt_thread(void *arg) {
    int thread_id = *(int *) arg;
    int start_pos = thread_id * MSG_SIZE / NUM_THREADS;
    int end_pos = (thread_id + 1) * MSG_SIZE / NUM_THREADS;

    for (int i = start_pos; i < end_pos; i++) {
        msg[i] = encrypted_msg[i] ^ key[i % KEY_SIZE];
    }

    pthread_exit(0);
}

int main() {
    msg = (char *) malloc(MSG_SIZE);
    key = (char *) malloc(KEY_SIZE);
    encrypted_msg = (char *) malloc(MSG_SIZE);

    strcpy(msg, "Hello, world!");
    strcpy(key, "secret_key");

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, encrypt_thread, (void *) &i);
        pthread_create(&threads[i], NULL, decrypt_thread, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encrypted message: %s\n", encrypted_msg);
    printf("Decrypted message: %s\n", msg);

    free(msg);
    free(key);
    free(encrypted_msg);

    return 0;
}