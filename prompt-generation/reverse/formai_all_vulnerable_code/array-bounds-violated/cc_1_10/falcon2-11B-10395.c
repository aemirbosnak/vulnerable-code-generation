//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt_message(char *message, char *key) {
    int i, j;
    char encrypted[strlen(message) + 1];
    for (i = 0, j = 0; i < strlen(message); i++) {
        encrypted[j] = message[i];
        j++;
    }
    encrypted[j] = '\0';
    for (i = 0, j = 0; i < KEY_SIZE; i++) {
        encrypted[j] = encrypted[j + 1];
        j++;
    }
    for (i = 0; i < KEY_SIZE; i++) {
        encrypted[j] = key[i];
        j++;
    }
    for (i = 0; i < strlen(message); i++) {
        encrypted[j] = message[i];
        j++;
    }
    printf("%s\n", encrypted);
}

void decrypt_message(char *encrypted_message, char *key) {
    int i, j;
    char decrypted[strlen(encrypted_message) + 1];
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        decrypted[j] = encrypted_message[i];
        j++;
    }
    decrypted[j] = '\0';
    for (i = 0, j = 0; i < KEY_SIZE; i++) {
        decrypted[j] = decrypted[j + 1];
        j++;
    }
    for (i = 0; i < KEY_SIZE; i++) {
        decrypted[j] = key[i];
        j++;
    }
    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted[j] = encrypted_message[i];
        j++;
    }
    printf("%s\n", decrypted);
}

int main() {
    char message[100];
    char key[KEY_SIZE];
    generate_key(key);
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);
    encrypt_message(message, key);
    decrypt_message(message, key);
    return 0;
}