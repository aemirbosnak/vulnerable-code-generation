//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_KEY_LENGTH 64
#define MAX_MSG_LENGTH 1024

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

// Function to encrypt a message
void encrypt(char* msg, char* key) {
    int i, j, k, n;
    n = strlen(msg);
    for (i = 0; i < n; i++) {
        if (isalpha(msg[i])) {
            msg[i] = msg[i] + key[i % strlen(key)];
        }
    }
}

// Function to decrypt a message
void decrypt(char* msg, char* key) {
    int i, j, k, n;
    n = strlen(msg);
    for (i = 0; i < n; i++) {
        if (isalpha(msg[i])) {
            msg[i] = msg[i] - key[i % strlen(key)];
        }
    }
}

int main() {
    srand(time(NULL));
    char key[MAX_KEY_LENGTH];
    generate_key(key);
    printf("Key: %s\n", key);

    char msg[MAX_MSG_LENGTH];
    printf("Enter message to encrypt: ");
    scanf("%s", msg);

    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);

    return 0;
}