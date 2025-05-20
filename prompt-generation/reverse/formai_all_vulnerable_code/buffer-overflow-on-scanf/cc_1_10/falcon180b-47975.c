//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void encrypt(char* message, int key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];
    encrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (char) ((message[i] - 'a' + key) % 26 + 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (char) ((message[i] - 'A' + key) % 26 + 'A');
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, int key) {
    int message_length = strlen(message);
    char decrypted_message[message_length + 1];
    decrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted_message[i] = (char) ((message[i] - 'a' - key + 26) % 26 + 'a');
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_message[i] = (char) ((message[i] - 'A' - key + 26) % 26 + 'A');
        } else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[BUFFER_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Enter the decryption key: ");
    scanf("%d", &key);

    decrypt(message, key);

    return 0;
}