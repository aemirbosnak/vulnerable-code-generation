//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// function to generate a random key
void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = 'A' + (rand() % 26);
    }
    key[i] = '\0';
}

// function to encrypt the message
void encrypt(char *message, char *key, int key_size, char *encrypted_message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        encrypted_message[i] = ((message[i] - 'A') + (key[i % key_size] - 'A')) % 26 + 'A';
    }
    encrypted_message[i] = '\0';
}

// function to decrypt the message
void decrypt(char *encrypted_message, char *key, int key_size, char *decrypted_message) {
    int i, x;
    for (i = 0; encrypted_message[i] != '\0'; i++) {
        x = (encrypted_message[i] - 'A') - (key[i % key_size] - 'A');
        if (x < 0)
            x += 26;
        decrypted_message[i] = x % 26 + 'A';
    }
    decrypted_message[i] = '\0';
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // define variables
    char message[100], key[100], encrypted_message[100], decrypted_message[100];
    int key_size;

    // get the input message from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    message[strlen(message) - 1] = '\0';

    // get the key size from the user
    printf("Enter the key size: ");
    scanf("%d", &key_size);
    getchar();

    // generate the key
    generate_key(key, key_size);

    // encrypt the message
    encrypt(message, key, key_size, encrypted_message);

    // print the encrypted message and key
    printf("Encrypted Message: %s\n", encrypted_message);
    printf("Key: %s\n", key);

    // decrypt the message
    decrypt(encrypted_message, key, key_size, decrypted_message);

    // print the decrypted message
    printf("Decrypted Message: %s\n", decrypted_message);

    return 0;
}