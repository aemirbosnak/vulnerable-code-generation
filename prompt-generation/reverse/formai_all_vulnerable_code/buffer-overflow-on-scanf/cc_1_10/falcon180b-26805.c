//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
} CaesarCipher;

CaesarCipher create_caesar_cipher(char* key) {
    CaesarCipher cipher;
    strncpy(cipher.key, key, MAX_KEY_LENGTH);
    cipher.key_length = strlen(cipher.key);
    cipher.shift = 0;
    return cipher;
}

char encrypt_char(char c, CaesarCipher cipher) {
    if (c >= 'a' && c <= 'z') {
        c = 'a' + ((c - 'a' + cipher.shift) % 26);
        if (c > 'z') {
            c = 'a' + (c - 'z' - 1);
        }
    } else if (c >= 'A' && c <= 'Z') {
        c = 'A' + ((c - 'A' + cipher.shift) % 26);
        if (c > 'Z') {
            c = 'A' + (c - 'Z' - 1);
        }
    }
    return c;
}

void encrypt_message(char* message, int message_length, CaesarCipher cipher) {
    for (int i = 0; i < message_length; i++) {
        message[i] = encrypt_char(message[i], cipher);
    }
}

void decrypt_message(char* message, int message_length, CaesarCipher cipher) {
    for (int i = 0; i < message_length; i++) {
        message[i] = encrypt_char(message[i], cipher);
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    CaesarCipher cipher = create_caesar_cipher(key);

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    int message_length = strlen(message);

    encrypt_message(message, message_length, cipher);

    printf("Encrypted message: %s\n", message);

    decrypt_message(message, message_length, cipher);

    printf("Decrypted message: %s\n", message);

    return 0;
}