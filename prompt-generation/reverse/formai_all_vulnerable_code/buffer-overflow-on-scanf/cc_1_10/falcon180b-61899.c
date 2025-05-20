//Falcon-180B DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    char *message;
    char *key;
    char *ciphertext;
} thread_data;

void *encrypt_thread(void *arg) {
    thread_data *data = (thread_data *) arg;
    int message_len = strlen(data->message);
    int key_len = strlen(data->key);
    char *ciphertext = malloc(message_len + 1);
    int ciphertext_len = 0;
    int i, j;

    for (i = 0; i < message_len; i++) {
        if (isalpha(data->message[i])) {
            if (isupper(data->message[i])) {
                data->message[i] = 'A' + ((data->message[i] - 'A' + key_len) % 26);
            } else {
                data->message[i] = 'a' + ((data->message[i] - 'a' + key_len) % 26);
            }
        }
    }

    for (i = 0; i < message_len; i++) {
        ciphertext[i] = data->message[i];
        ciphertext_len++;
    }

    ciphertext[ciphertext_len] = '\0';

    strcpy(data->ciphertext, ciphertext);

    free(ciphertext);

    return NULL;
}

int main() {
    pthread_t thread_id;
    thread_data data;
    char message[100];
    char key[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%s", key);

    data.message = strdup(message);
    data.key = strdup(key);
    data.ciphertext = NULL;

    pthread_create(&thread_id, NULL, encrypt_thread, &data);

    pthread_join(thread_id, NULL);

    printf("Encrypted message: %s\n", data.ciphertext);

    free(data.message);
    free(data.key);
    free(data.ciphertext);

    return 0;
}