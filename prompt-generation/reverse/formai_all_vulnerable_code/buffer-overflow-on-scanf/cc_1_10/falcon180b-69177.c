//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *message, char *key, char *cipher) {
    int message_size = strlen(message);
    int key_size = strlen(key);
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + key[i % key_size] - 'a') % 26 + 'a';
        }
    }
    strcpy(cipher, message);
}

void decrypt(char *cipher, char *key, char *message) {
    int cipher_size = strlen(cipher);
    int key_size = strlen(key);
    for (int i = 0; i < cipher_size; i++) {
        if (isalpha(cipher[i])) {
            cipher[i] = (cipher[i] - 'a' - key[i % key_size] + 26) % 26 + 'a';
        }
    }
    strcpy(message, cipher);
}

int main() {
    char message[1000];
    char cipher[1000];
    char key[100];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    scanf("%[^\n]", key);
    generate_key(key, strlen(key));
    encrypt(message, key, cipher);
    printf("Encrypted message: %s\n", cipher);
    decrypt(cipher, key, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}