//Falcon-180B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int shift;
} CaesarCipher;

void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void caesar_encrypt(char* message, int message_size, CaesarCipher* cipher) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + cipher->shift) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + cipher->shift) % 26 + 'a';
            }
        }
    }
}

void caesar_decrypt(char* message, int message_size, CaesarCipher* cipher) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - cipher->shift + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - cipher->shift + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    CaesarCipher cipher;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(cipher.key, MAX_KEY_SIZE);
    cipher.key_size = strlen(cipher.key);
    cipher.shift = rand() % 26;

    caesar_encrypt(message, strlen(message), &cipher);

    printf("Encrypted message: %s\n", message);

    caesar_decrypt(message, strlen(message), &cipher);

    printf("Decrypted message: %s\n", message);

    return 0;
}