//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000

// Function to generate a random key
void generate_key(char key[MAX_STRING_LENGTH]) {
    const char alphanumeric[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int key_length = rand() % (MAX_STRING_LENGTH - 1) + 1;

    for (int i = 0; i < key_length; i++) {
        key[i] = alphanumeric[rand() % strlen(alphanumeric)];
    }

    key[key_length] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char message[MAX_STRING_LENGTH], char key[MAX_STRING_LENGTH]) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key[i % key_length];
    }
}

// Function to decrypt the message using the key
void decrypt(char message[MAX_STRING_LENGTH], char key[MAX_STRING_LENGTH]) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key[i % key_length];
    }
}

int main() {
    srand(time(NULL));

    char message[MAX_STRING_LENGTH];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    char key[MAX_STRING_LENGTH];
    generate_key(key);

    printf("Key: %s\n", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}