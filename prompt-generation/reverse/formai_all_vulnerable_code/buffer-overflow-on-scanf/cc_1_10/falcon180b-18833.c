//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZE 16
#define MAX_KEY 1000
#define MAX_MESSAGE 1000

struct Key {
    int size;
    int *key;
};

struct Message {
    int size;
    char *message;
};

void generateRandomKey(int size, int *key) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void generateRandomMessage(int size, char *message) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        message[i] = rand() % 26 + 'A';
    }
}

void encrypt(int key[SIZE], char message[MAX_MESSAGE]) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key[i % SIZE];
        if (message[i] > 'Z') {
            message[i] = message[i] - 26;
        }
    }
}

void decrypt(int key[SIZE], char message[MAX_MESSAGE]) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] - key[i % SIZE];
        if (message[i] < 'A') {
            message[i] = message[i] + 26;
        }
    }
}

int main() {
    struct Key key;
    struct Message message;

    printf("Enter the size of the key: ");
    scanf("%d", &key.size);

    if (key.size > MAX_KEY) {
        printf("Invalid key size.\n");
        return 0;
    }

    key.key = (int *)malloc(key.size * sizeof(int));

    generateRandomKey(key.size, key.key);

    printf("Enter the message to be encrypted: ");
    scanf("%s", message.message);

    if (strlen(message.message) > MAX_MESSAGE) {
        printf("Invalid message size.\n");
        return 0;
    }

    encrypt(key.key, message.message);

    printf("Encrypted message: %s\n", message.message);

    decrypt(key.key, message.message);

    printf("Decrypted message: %s\n", message.message);

    free(key.key);

    return 0;
}