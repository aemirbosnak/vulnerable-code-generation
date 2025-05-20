//Falcon-180B DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_BLOCK_LEN 100
#define BLOCK_SIZE 8

int main() {
    char key[MAX_KEY_LEN];
    char message[MAX_BLOCK_LEN];
    char encrypted_message[MAX_BLOCK_LEN];
    int i, j;

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_BLOCK_LEN, stdin);

    // Remove newline character from key and message
    key[strcspn(key, "\n")] = '\0';
    message[strcspn(message, "\n")] = '\0';

    // Pad key to multiple of block size
    int key_len = strlen(key);
    if (key_len % BLOCK_SIZE) {
        key_len += BLOCK_SIZE - key_len % BLOCK_SIZE;
    }

    // Generate encryption matrix
    int matrix[MAX_KEY_LEN][MAX_KEY_LEN];
    for (i = 0; i < key_len; i++) {
        for (j = 0; j < key_len; j++) {
            matrix[i][j] = key[i] + j;
        }
    }

    // Encrypt message
    int message_len = strlen(message);
    for (i = 0; i < message_len; i += BLOCK_SIZE) {
        int block_len = (message_len - i > BLOCK_SIZE)? BLOCK_SIZE : message_len - i;
        for (j = 0; j < block_len; j++) {
            char c = tolower(message[i + j]);
            if (c >= 'a' && c <= 'z') {
                c = (c - 'a' + matrix[i % key_len][j % key_len]) % 26 + 'a';
            }
            encrypted_message[i + j] = c;
        }
    }

    encrypted_message[message_len] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}