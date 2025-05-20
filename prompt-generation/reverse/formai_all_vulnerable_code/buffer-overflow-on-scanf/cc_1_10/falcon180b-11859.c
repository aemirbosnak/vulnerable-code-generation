//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

void generate_key(char *key, int key_length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_length] = '\0';
}

void encrypt(char *message, char *key) {
    int key_index = 0;
    char encrypted_message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = key[key_index] + (message[i] - 'A') % 26;
            } else {
                encrypted_message[i] = key[key_index] + (message[i] - 'a') % 26;
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
    strcpy(message, encrypted_message);
}

void decrypt(char *message, char *key) {
    int key_index = 0;
    char decrypted_message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = (message[i] - key[key_index] - 65) % 26 + 'A';
            } else {
                decrypted_message[i] = (message[i] - key[key_index] - 97) % 26 + 'a';
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            decrypted_message[i] = message[i];
        }
    }
    decrypted_message[strlen(message)] = '\0';
    strcpy(message, decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    generate_key(key, strlen(key));
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}