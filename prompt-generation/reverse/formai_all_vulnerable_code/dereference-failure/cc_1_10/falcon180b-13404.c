//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 1024 // size of the buffer
#define KEY_SIZE 16 // size of the encryption key

void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a'; // generate a random lowercase letter
    }
    key[KEY_SIZE] = '\0'; // terminate the string
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] + key[key_index];
        key_index = (key_index + 1) % KEY_SIZE;
    }
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        message[i] = message[i] - key[key_index];
        key_index = (key_index + 1) % KEY_SIZE;
    }
}

int main() {
    char message[SIZE];
    char key[KEY_SIZE];
    generate_key(key); // generate a random encryption key

    printf("Enter a message to encrypt: ");
    fgets(message, SIZE, stdin); // read the message from the user

    encrypt(message, key); // encrypt the message using the key

    printf("Encrypted message: %s\n", message);

    decrypt(message, key); // decrypt the message using the key

    printf("Decrypted message: %s\n", message);

    return 0;
}