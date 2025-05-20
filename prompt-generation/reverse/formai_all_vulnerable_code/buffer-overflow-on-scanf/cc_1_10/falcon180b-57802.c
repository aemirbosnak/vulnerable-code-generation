//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 8

typedef struct {
    char plaintext[80];
    char ciphertext[120];
    int key;
    int thread_id;
} thread_data;

void *encrypt(void *param) {
    thread_data *data = (thread_data *) param;

    int i, j;
    char ciphertext[120];
    int key = data->key;

    for (i = 0, j = 0; i < strlen(data->plaintext); i++, j++) {
        if (j == key) {
            j = 0;
        }
        ciphertext[j] = data->plaintext[i];
    }

    strcpy(data->ciphertext, ciphertext);

    pthread_exit(0);
}

void *decrypt(void *param) {
    thread_data *data = (thread_data *) param;

    int i, j;
    char plaintext[80];
    int key = data->key;

    for (i = 0, j = 0; i < strlen(data->ciphertext); i++, j++) {
        if (j == key) {
            j = 0;
        }
        plaintext[j] = data->ciphertext[i];
    }

    strcpy(data->plaintext, plaintext);

    pthread_exit(0);
}

int main() {
    int i, j, num_threads;
    char plaintext[80], ciphertext[120];
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter thread key %d: ", i);
        scanf("%d", &data[i].key);
        strcpy(data[i].plaintext, plaintext);
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, encrypt, &data[i])!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread\n");
            exit(1);
        }
    }

    printf("Ciphertext: %s\n", data[0].ciphertext);

    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, decrypt, &data[i])!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread\n");
            exit(1);
        }
    }

    printf("Plaintext: %s\n", data[0].plaintext);

    return 0;
}