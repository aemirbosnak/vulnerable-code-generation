//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
} caesar_cipher_t;

void generate_random_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void caesar_encrypt(char* message, caesar_cipher_t* cipher) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int index = c - 'a';
            if (index >= 0 && index < 26) {
                c = (index + cipher->shift) % 26 + 'a';
            }
            message[i] = c;
        }
    }
}

void caesar_decrypt(char* message, caesar_cipher_t* cipher) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int index = c - 'a';
            if (index >= 0 && index < 26) {
                c = (index - cipher->shift + 26) % 26 + 'a';
            }
            message[i] = c;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    caesar_cipher_t cipher;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_random_key(cipher.key);
    cipher.key_length = strlen(cipher.key);
    cipher.shift = rand() % 26;

    caesar_encrypt(message, &cipher);
    printf("Encrypted message: %s\n", message);

    caesar_decrypt(message, &cipher);
    printf("Decrypted message: %s\n", message);

    return 0;
}