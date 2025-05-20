//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_key(int key_size, char* key) {
    for (int i = 0; i < key_size; i++) {
        // generate a random key
        key[i] = rand() % 256;
    }
}

void encrypt(int key_size, char* key, char* message) {
    int message_size = strlen(message);
    int key_index = 0;
    for (int i = 0; i < message_size; i++) {
        // XOR each character with the key
        char encrypted_char = message[i] ^ key[key_index++ % key_size];
        message[i] = encrypted_char;
    }
}

void decrypt(int key_size, char* key, char* encrypted_message) {
    int encrypted_message_size = strlen(encrypted_message);
    int key_index = 0;
    for (int i = 0; i < encrypted_message_size; i++) {
        // XOR each character with the key
        char decrypted_char = encrypted_message[i] ^ key[key_index++ % key_size];
        encrypted_message[i] = decrypted_char;
    }
}

int main() {
    int key_size = 16;
    char key[key_size];
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];

    generate_key(key_size, key);
    printf("Key: ");
    for (int i = 0; i < key_size; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(key_size, key, message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(key_size, key, encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}