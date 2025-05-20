//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

void generate_key(char* key, int key_length) {
    srand(time(0));

    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }

    key[key_length] = '\0';
}

void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        message[i] = (message[i] + key[i % MAX_KEY_LENGTH]) % 26 + 'A';
    }
}

void decrypt_message(char* message, char* key) {
    int message_length = strlen(message);

    for (int i = 0; i < message_length; i++) {
        message[i] = (message[i] - key[i % MAX_KEY_LENGTH] + 26) % 26 + 'A';
    }
}

int main() {
    char key[MAX_KEY_LENGTH] = "";
    char message[MAX_MESSAGE_LENGTH] = "";

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt_message(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}