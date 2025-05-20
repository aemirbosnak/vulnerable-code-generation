//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to encrypt a given message using a given key
void encrypt(char* message, const char* key, int key_len, int msg_len, char* encrypted_msg, int i) {
    // Base case
    if (i == msg_len) {
        encrypted_msg[i] = '\0';
        return;
    }

    // Recursive case
    encrypted_msg[i] = (message[i] + key[i % key_len]) % 128;

    // Recursively call the function with next character
    encrypt(message, key, key_len, msg_len, encrypted_msg, i + 1);
}

// Recursive function to decrypt a given message using a given key
void decrypt(char* encrypted_msg, const char* key, int key_len, int msg_len, char* decrypted_msg, int i) {
    // Base case
    if (i == msg_len) {
        decrypted_msg[i] = '\0';
        return;
    }

    // Recursive case
    decrypted_msg[i] = (encrypted_msg[i] - key[i % key_len] + 128) % 128;

    // Recursively call the function with next character
    decrypt(encrypted_msg, key, key_len, msg_len, decrypted_msg, i + 1);
}

int main() {
    char message[100], key[100], encrypted_msg[100], decrypted_msg[100];
    int key_len, msg_len;

    printf("Enter the message to be encrypted:");
    scanf("%s", message);

    printf("Enter the key:");
    scanf("%s", key);

    key_len = strlen(key);
    msg_len = strlen(message);

    encrypt(message, key, key_len, msg_len, encrypted_msg, 0);

    printf("Encrypted message: %s\n", encrypted_msg);

    decrypt(encrypted_msg, key, key_len, msg_len, decrypted_msg, 0);

    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}