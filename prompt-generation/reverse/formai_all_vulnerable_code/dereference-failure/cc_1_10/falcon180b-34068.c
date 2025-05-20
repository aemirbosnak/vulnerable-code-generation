//Falcon-180B DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int a, b, c;
} CaesarCipher;

void generate_key(char* key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = 'A' + rand() % 26;
    }
    key[key_length] = '\0';
}

void caesar_encrypt(char* message, int message_length, CaesarCipher* cipher) {
    int i;
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A' - cipher->a) % 26) + cipher->a;
            } else {
                message[i] = 'a' + ((message[i] - 'a' - cipher->a) % 26) + cipher->a;
            }
        }
    }
}

void caesar_decrypt(char* message, int message_length, CaesarCipher* cipher) {
    int i;
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A' - cipher->a - 26) % 26) + 'A';
            } else {
                message[i] = 'a' + ((message[i] - 'a' - cipher->a - 26) % 26) + 'a';
            }
        }
    }
}

int main() {
    int key_length;
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    CaesarCipher cipher;

    printf("Enter message length (max %d): ", MAX_MESSAGE_LENGTH);
    scanf("%d", &key_length);

    printf("Enter message: ");
    scanf("%s", message);

    generate_key(key, key_length);

    printf("Key: %s\n", key);

    caesar_encrypt(message, strlen(message), &cipher);

    printf("Encrypted message: %s\n", message);

    caesar_decrypt(message, strlen(message), &cipher);

    printf("Decrypted message: %s\n", message);

    return 0;
}