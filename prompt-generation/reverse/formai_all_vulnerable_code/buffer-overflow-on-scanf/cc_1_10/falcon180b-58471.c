//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_STRING_LENGTH 1000
#define ENCRYPT 1
#define DECRYPT 0

void generate_key(char* key, int key_length) {
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = alphanum[rand() % strlen(alphanum)];
    }
    key[key_length] = '\0';
}

void encrypt_string(char* plaintext, char* key, int mode, char* ciphertext) {
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int ciphertext_length = plaintext_length + 1;
    ciphertext[ciphertext_length - 1] = '\0';

    int index = 0;
    for (int i = 0; i < plaintext_length; i++) {
        if (mode == ENCRYPT) {
            ciphertext[i] = plaintext[i] ^ key[index % key_length];
        } else {
            ciphertext[i] = plaintext[i] ^ key[index % key_length];
        }
        index++;
    }
}

void decrypt_string(char* ciphertext, char* key, int mode, char* plaintext) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    int plaintext_length = ciphertext_length - 1;
    plaintext[plaintext_length] = '\0';

    int index = 0;
    for (int i = 0; i < ciphertext_length; i++) {
        if (mode == DECRYPT) {
            plaintext[i] = ciphertext[i] ^ key[index % key_length];
        } else {
            plaintext[i] = ciphertext[i] ^ key[index % key_length];
        }
        index++;
    }
}

int main() {
    char plaintext[MAX_STRING_LENGTH];
    char ciphertext[MAX_STRING_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter plaintext: ");
    fgets(plaintext, MAX_STRING_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    generate_key(key, strlen(key));

    int mode;
    printf("Enter mode (encrypt/decrypt): ");
    scanf("%d", &mode);

    if (mode == ENCRYPT) {
        encrypt_string(plaintext, key, mode, ciphertext);
        printf("Ciphertext: %s\n", ciphertext);
    } else {
        decrypt_string(plaintext, key, mode, ciphertext);
        printf("Plaintext: %s\n", ciphertext);
    }

    return 0;
}