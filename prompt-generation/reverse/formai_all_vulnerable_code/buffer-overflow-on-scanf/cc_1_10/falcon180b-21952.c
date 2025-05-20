//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000
#define ALPHABET_SIZE 26

char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

void generate_key(char key[], int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = alphabet[rand() % ALPHABET_SIZE];
    }
}

void encrypt(char message[], char key[], int key_size, char encrypted_message[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        encrypted_message[j] = message[i] ^ key[i % key_size];
        j++;
    }
    encrypted_message[j] = '\0';
}

void decrypt(char encrypted_message[], char key[], int key_size, char message[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        message[j] = encrypted_message[i] ^ key[i % key_size];
        j++;
    }
    message[j] = '\0';
}

int main() {
    char message[SIZE], encrypted_message[SIZE], key[SIZE];
    int key_size;
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the key size: ");
    scanf("%d", &key_size);
    generate_key(key, key_size);
    encrypt(message, key, key_size, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Enter the key: ");
    scanf("%s", key);
    decrypt(encrypted_message, key, key_size, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}