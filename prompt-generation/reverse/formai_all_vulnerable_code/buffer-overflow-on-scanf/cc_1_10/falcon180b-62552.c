//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024
#define MAX_CIPHER_LENGTH (MAX_MESSAGE_LENGTH + 5)

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    int rounds;
} cyberpunk_cipher_t;

void cyberpunk_cipher_init(cyberpunk_cipher_t *cipher, const char *key, int rounds) {
    strncpy(cipher->key, key, MAX_KEY_LENGTH);
    cipher->key_length = strlen(cipher->key);
    cipher->rounds = rounds;
}

void cyberpunk_cipher_encrypt(cyberpunk_cipher_t *cipher, char *message, char *ciphertext) {
    int message_length = strlen(message);
    int ciphertext_length = message_length + 5;
    int i, j, k, index;

    for (i = 0; i < cipher->rounds; i++) {
        for (j = 0; j < message_length; j++) {
            index = (j * cipher->key_length) % ciphertext_length;
            k = (j * cipher->key_length) % cipher->key_length;
            ciphertext[index] = message[j] ^ cipher->key[k];
        }
    }
}

void cyberpunk_cipher_decrypt(cyberpunk_cipher_t *cipher, char *ciphertext, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int message_length = ciphertext_length - 5;
    int i, j, k, index;

    for (i = 0; i < cipher->rounds; i++) {
        for (j = 0; j < message_length; j++) {
            index = (j * cipher->key_length) % ciphertext_length;
            k = (j * cipher->key_length) % cipher->key_length;
            message[j] = ciphertext[index] ^ cipher->key[k];
        }
    }
}

int main() {
    cyberpunk_cipher_t cipher;
    char message[MAX_MESSAGE_LENGTH];
    char ciphertext[MAX_CIPHER_LENGTH];
    int rounds;

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter key: ");
    fgets(cipher.key, MAX_KEY_LENGTH, stdin);
    cipher.key_length = strlen(cipher.key);

    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    cyberpunk_cipher_init(&cipher, cipher.key, rounds);

    cyberpunk_cipher_encrypt(&cipher, message, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    cyberpunk_cipher_decrypt(&cipher, ciphertext, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}