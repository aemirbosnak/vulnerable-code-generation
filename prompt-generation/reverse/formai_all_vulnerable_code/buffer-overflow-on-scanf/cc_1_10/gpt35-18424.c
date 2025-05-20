//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define KEY_LEN 16
#define PLAINTEXT_LEN 1024

char key[KEY_LEN];
char plaintext[PLAINTEXT_LEN];
char ciphertext[PLAINTEXT_LEN];

pthread_mutex_t lock;

void *encrypt(void *args) {
    int tid = *(int *)args;
    int start = (PLAINTEXT_LEN/2) * tid;
    int end = start + (PLAINTEXT_LEN/2);

    for(int i=start; i<end; i++) {
        ciphertext[i] = plaintext[i] ^ key[i%(KEY_LEN-1)];
    }

    pthread_mutex_lock(&lock);
    printf("Thread %d: Encrypted text - %s\n", tid, ciphertext);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    printf("Enter the key (must be %d characters long): ", KEY_LEN-1);
    scanf("%s", key);

    printf("Enter the plaintext: ");
    fflush(stdin);
    fgets(plaintext, PLAINTEXT_LEN, stdin);
    strtok(plaintext, "\n");

    pthread_t threads[2];
    int tids[2] = {0, 1};
    pthread_create(&threads[0], NULL, encrypt, &tids[0]);
    pthread_create(&threads[1], NULL, encrypt, &tids[1]);

    for(int i=0; i<2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}