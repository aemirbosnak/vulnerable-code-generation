//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_PLAINTEXT_LENGTH 1000
#define MAX_CIPHERTEXT_LENGTH (MAX_PLAINTEXT_LENGTH + 1)

typedef struct {
    char key[MAX_KEY_LENGTH];
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char ciphertext[MAX_CIPHERTEXT_LENGTH];
} Cryptogram;

void generate_key(Cryptogram *cryptogram) {
    char *key = cryptogram->key;
    int key_length = strlen(key);

    if (key_length >= MAX_KEY_LENGTH) {
        printf("Error: Key length is too long.\n");
        exit(1);
    }

    for (int i = 0; i < key_length; i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key must only contain letters.\n");
            exit(1);
        }
    }
}

void encrypt(Cryptogram *cryptogram) {
    char *key = cryptogram->key;
    char *plaintext = cryptogram->plaintext;
    char *ciphertext = cryptogram->ciphertext;
    int plaintext_length = strlen(plaintext);

    for (int i = 0; i < plaintext_length; i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            c = (c - 'a' + (int)key[i % strlen(key)]) % 26 + 'a';
        }
        ciphertext[i] = c;
    }
    ciphertext[plaintext_length] = '\0';
}

void decrypt(Cryptogram *cryptogram) {
    char *key = cryptogram->key;
    char *ciphertext = cryptogram->ciphertext;
    char *plaintext = cryptogram->plaintext;
    int ciphertext_length = strlen(ciphertext);

    for (int i = 0; i < ciphertext_length; i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            c = (c - 'a' - (int)key[i % strlen(key)]) % 26 + 'a';
        }
        plaintext[i] = c;
    }
    plaintext[ciphertext_length] = '\0';
}

int main() {
    Cryptogram cryptogram;

    printf("Enter a key (letters only, max %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", cryptogram.key);
    generate_key(&cryptogram);

    printf("Enter plaintext (letters only, max %d characters): ", MAX_PLAINTEXT_LENGTH);
    scanf("%s", cryptogram.plaintext);

    encrypt(&cryptogram);
    printf("Ciphertext: %s\n", cryptogram.ciphertext);

    decrypt(&cryptogram);
    printf("Plaintext: %s\n", cryptogram.plaintext);

    return 0;
}