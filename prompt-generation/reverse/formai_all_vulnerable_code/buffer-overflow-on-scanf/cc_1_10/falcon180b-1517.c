//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

// function to encrypt message using Caesar cipher
void encrypt(char* message, int key, char* encrypted_message) {
    int i = 0, j = 0;
    while (message[i]) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + key - 65) % 26 + 65;
            } else {
                encrypted_message[j] = (message[i] + key - 97) % 26 + 97;
            }
        } else {
            encrypted_message[j] = message[i];
        }
        i++;
        j++;
    }
    encrypted_message[j] = '\0';
}

// function to decrypt message using Caesar cipher
void decrypt(char* encrypted_message, int key, char* decrypted_message) {
    int i = 0, j = 0;
    while (encrypted_message[i]) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = (encrypted_message[i] - key - 65) % 26 + 65;
            } else {
                decrypted_message[j] = (encrypted_message[i] - key - 97) % 26 + 97;
            }
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
        i++;
        j++;
    }
    decrypted_message[j] = '\0';
}

// function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 65;
    }
    key[MAX_KEY_SIZE] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // generate key
    generate_key(key);

    // encrypt message
    encrypt(message, strlen(key), encrypted_message);

    // decrypt message
    decrypt(encrypted_message, strlen(key), decrypted_message);

    // print results
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}