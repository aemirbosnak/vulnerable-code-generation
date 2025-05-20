//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to perform encryption using a provided key
void encrypt(char *message, char *key) {
    int i, j;
    int msg_len = strlen(message);
    int key_len = strlen(key);
    char encrypted[MAX_LEN];

    for (i = 0, j = 0; i < msg_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        encrypted[i] = (message[i] + key[j]) % 26 + 'A';
    }
    encrypted[i] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

// Function to perform decryption using a provided key
void decrypt(char *message, char *key) {
    int i, j;
    int msg_len = strlen(message);
    int key_len = strlen(key);
    char decrypted[MAX_LEN];

    for (i = 0, j = 0; i < msg_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        decrypted[i] = (message[i] - key[j] + 26) % 26 + 'A';
    }
    decrypted[i] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[MAX_LEN], key[MAX_LEN];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%s", key);

    printf("Original message: %s\n", message);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}