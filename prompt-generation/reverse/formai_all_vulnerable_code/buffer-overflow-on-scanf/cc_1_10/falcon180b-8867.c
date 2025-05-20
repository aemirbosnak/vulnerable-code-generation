//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_MSG_SIZE 1000

typedef struct {
    char msg[MAX_MSG_SIZE];
    int len;
    int id;
} thread_data;

void *encrypt_thread(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i, j, k;
    char ch;
    for (i = 0; i < data->len; i++) {
        ch = data->msg[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + 'A' - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }
        data->msg[i] = ch;
    }
    return NULL;
}

void *decrypt_thread(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i, j, k;
    char ch;
    for (i = 0; i < data->len; i++) {
        ch = data->msg[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        data->msg[i] = ch;
    }
    return NULL;
}

int main() {
    int i, len, id;
    char msg[MAX_MSG_SIZE];
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", msg);
    len = strlen(msg);
    for (i = 0; i < MAX_THREADS; i++) {
        data[i].len = len / MAX_THREADS;
        data[i].id = i + 1;
        strncpy(data[i].msg, msg, data[i].len);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, i % 2 == 0? encrypt_thread : decrypt_thread, &data[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Encrypted/Decrypted message: %s\n", msg);
    return 0;
}