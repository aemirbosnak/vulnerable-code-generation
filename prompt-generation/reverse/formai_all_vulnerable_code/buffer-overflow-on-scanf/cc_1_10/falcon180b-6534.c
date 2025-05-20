//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char* key) {
    int i;
    for(i=0; i<MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int i, j;
    for(i=0, j=0; i<strlen(message); i++) {
        encrypted_message[j++] = message[i] ^ key[i % MAX_KEY_LENGTH];
    }
    encrypted_message[j] = '\0';
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i, j;
    for(i=0, j=0; i<strlen(encrypted_message); i++) {
        decrypted_message[j++] = encrypted_message[i] ^ key[i % MAX_KEY_LENGTH];
    }
    decrypted_message[j] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int choice;

    printf("Welcome to the futuristic cryptography program!\n");
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &choice);
    if(choice < 1 || choice > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }

    generate_key(key);

    printf("Encrypting message...\n");
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    printf("Decrypting message...\n");
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}