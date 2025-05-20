//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char key[MAX_LENGTH];
char message[MAX_LENGTH];
char encrypted[MAX_LENGTH];

void encrypt(char *msg, char *k) {
    int msg_len = strlen(msg);
    int key_len = strlen(k);

    // find the difference in lengths and append key to match
    int len_diff = msg_len - key_len;
    if (len_diff > 0) {
        for (int i = 0; i < len_diff; i++) {
            k[key_len + i] = k[i];
        }
    }

    for (int i = 0; i < msg_len; i++) {
        encrypted[i] = msg[i] ^ k[i]; // bitwise XOR operation
    }
    encrypted[msg_len] = '\0';
}

int main() {
    printf("Enter a message to encrypt (max length %d): ", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter an encryption key (max length %d): ", MAX_LENGTH);
    fgets(key, MAX_LENGTH, stdin);

    // remove newline characters from input
    int msg_len = strlen(message);
    if (message[msg_len-1] == '\n') {
        message[msg_len-1] = '\0';
    }
    int key_len = strlen(key);
    if (key[key_len-1] == '\n') {
        key[key_len-1] = '\0';
    }

    encrypt(message, key);

    printf("Original message: %s\nEncrypted message: %s\n", message, encrypted);

    return 0;
}