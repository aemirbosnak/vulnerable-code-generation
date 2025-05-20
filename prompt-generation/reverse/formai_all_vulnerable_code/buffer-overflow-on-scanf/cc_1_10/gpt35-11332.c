//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_MESSAGE_LENGTH 1000
#define NUM_THREADS 2

char message[MAX_MESSAGE_LENGTH];
int message_length = 0;
int key = 3;
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void *encryption_thread(void *arg) {
    int i;
    char encrypted_message[MAX_MESSAGE_LENGTH];
    memset(encrypted_message, 0, sizeof(encrypted_message));

    for (i = 0; i < message_length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            int index = (strchr(alphabet, message[i]) - alphabet + key) % 26;
            encrypted_message[i] = alphabet[index];
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
    return NULL;
}

void *decryption_thread(void *arg) {
    int i;
    char decrypted_message[MAX_MESSAGE_LENGTH];
    memset(decrypted_message, 0, sizeof(decrypted_message));

    for (i = 0; i < message_length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            int index = (strchr(alphabet, message[i]) - alphabet - key + 26) % 26;
            decrypted_message[i] = alphabet[index];
        } else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);
    message[message_length - 1] = '\0'; // remove newline character

    printf("Enter key value: ");
    scanf("%d", &key);

    for (i = 0; i < NUM_THREADS; i++) {
        if (i == 0) {
            pthread_create(&threads[i], NULL, encryption_thread, NULL);
        } else {
            pthread_create(&threads[i], NULL, decryption_thread, NULL);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}