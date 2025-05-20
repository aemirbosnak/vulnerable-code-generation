//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MSG_SIZE 1024

// Key generation function
void generate_key(char* key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size] = '\0';
}

// Encryption function
void encrypt(char* msg, char* key, int size, char* encrypted_msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            encrypted_msg[i] = (msg[i] + key[i % size] - 'a' + 26) % 26 + 'a';
        } else {
            encrypted_msg[i] = msg[i];
        }
    }
    encrypted_msg[strlen(msg)] = '\0';
}

// Decryption function
void decrypt(char* encrypted_msg, char* key, int size, char* decrypted_msg) {
    for (int i = 0; i < strlen(encrypted_msg); i++) {
        if (isalpha(encrypted_msg[i])) {
            decrypted_msg[i] = (encrypted_msg[i] - key[i % size] + 'a' - 1) % 26 + 'a';
        } else {
            decrypted_msg[i] = encrypted_msg[i];
        }
    }
    decrypted_msg[strlen(encrypted_msg)] = '\0';
}

// Main function
int main() {
    srand(time(NULL));
    char key[MAX_KEY_SIZE];
    generate_key(key, MAX_KEY_SIZE);

    char msg[MAX_MSG_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", msg);

    char encrypted_msg[MAX_MSG_SIZE];
    encrypt(msg, key, MAX_KEY_SIZE, encrypted_msg);

    printf("Encrypted message: %s\n", encrypted_msg);

    char decrypted_msg[MAX_MSG_SIZE];
    decrypt(encrypted_msg, key, MAX_KEY_SIZE, decrypted_msg);

    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}