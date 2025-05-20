//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 64
#define MAX_MESSAGE_SIZE 1024

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size;
    int i, j;
    char encrypted_message[MAX_MESSAGE_SIZE];

    // Get input message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Get input key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Get key size from user
    printf("Enter key size (between 1 and 64): ");
    scanf("%d", &key_size);

    // Convert key to uppercase
    for (i = 0; i < key_size; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt message using key
    for (i = 0; i < strlen(message); i++) {
        message[i] = toupper(message[i]);
        if (isalpha(message[i])) {
            j = (int)message[i] + (int)key[i % key_size];
            if (isalpha(j)) {
                encrypted_message[i] = (char)j;
            } else {
                encrypted_message[i] = message[i];
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}