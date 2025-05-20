//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 64
#define MAX_MESSAGE_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        char c = rand() % 26 + 'a';
        key[i] = toupper(c);
    }
    key[key_size] = '\0';
}

void caesar_encrypt(char *message, char *key, int key_size, char *ciphertext) {
    int message_size = strlen(message);
    int key_index = 0;

    for (int i = 0; i < message_size; i++) {
        char c = message[i];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + ((c - 'A' + key[key_index] - 'A') % 26);
            } else {
                c = 'a' + ((c - 'a' + key[key_index] - 'a') % 26);
            }
        }

        ciphertext[i] = c;
        key_index++;
        if (key_index >= key_size) {
            key_index = 0;
        }
    }

    ciphertext[message_size] = '\0';
}

void caesar_decrypt(char *ciphertext, char *key, int key_size, char *message) {
    int ciphertext_size = strlen(ciphertext);
    int key_index = 0;

    for (int i = 0; i < ciphertext_size; i++) {
        char c = ciphertext[i];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = 'A' + ((c - 'A' - key[key_index] + 26) % 26);
            } else {
                c = 'a' + ((c - 'a' - key[key_index] + 26) % 26);
            }
        }

        message[i] = c;
        key_index++;
        if (key_index >= key_size) {
            key_index = 0;
        }
    }

    message[ciphertext_size] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char ciphertext[MAX_MESSAGE_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    generate_key(key, rand() % MAX_KEY_SIZE + 1);

    caesar_encrypt(message, key, strlen(key), ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    printf("Enter the key used to encrypt the message: ");
    scanf("%s", key);

    caesar_decrypt(ciphertext, key, strlen(key), message);

    printf("Decrypted message: %s\n", message);

    return 0;
}