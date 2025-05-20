//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, char *key) {
    int len = strlen(message);
    int keylen = strlen(key);
    int i, j, k;
    char encrypted[len];
    for (i = 0, j = 0; i < len; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            char kc = tolower(key[j % keylen]);
            c = (((c - 97) + (kc - 97)) % 26) + 97;
            encrypted[i] = c;
            j++;
        } else {
            encrypted[i] = c;
        }
    }
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *message, char *key) {
    int len = strlen(message);
    int keylen = strlen(key);
    int i, j, k;
    char decrypted[len];
    for (i = 0, j = 0; i < len; i++) {
        char c = message[i];
        if (isalpha(c)) {
            char kc = tolower(key[j % keylen]);
            int diff = (c - 97 - (kc - 97)) % 26;
            if (diff < 0) {
                diff += 26;
            }
            c = (c - 97 - diff) % 26 + 97;
            decrypted[i] = c;
            j++;
        } else {
            decrypted[i] = c;
        }
    }
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100], key[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    printf("Enter decryption key: ");
    scanf("%s", key);
    decrypt(message, key);
    return 0;
}