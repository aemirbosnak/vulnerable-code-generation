//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char* message, char* key, char* encrypted) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int index = message[i] - 'A';
            int key_index = rand() % KEY_SIZE;
            int new_index = (index + key[key_index] - 'A') % 26;
            encrypted[i] = new_index + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }
}

void decrypt(char* encrypted, char* key, char* message) {
    for (int i = 0; i < strlen(encrypted); i++) {
        if (isalpha(encrypted[i])) {
            int index = encrypted[i] - 'A';
            int key_index = rand() % KEY_SIZE;
            int new_index = (index - key[key_index] + 26) % 26;
            message[i] = new_index + 'A';
        } else {
            message[i] = encrypted[i];
        }
    }
}

int main() {
    char message[1000], key[KEY_SIZE], encrypted[1000], decrypted[1000];
    generate_key(key);
    printf("Message: ");
    scanf("%s", message);
    encrypt(message, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);
    decrypt(encrypted, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}