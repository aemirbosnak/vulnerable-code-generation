//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key[i % key_size];
    }
}

void decrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] - key[i % key_size];
    }
}

int main() {
    srand(time(NULL));

    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    int key_size;
    printf("Enter the key size (between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);

    generate_key(key, key_size);

    encrypt(message, key, key_size);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, key_size);

    printf("Decrypted message: %s\n", message);

    return 0;
}