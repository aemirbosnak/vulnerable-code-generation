//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, n;
    char temp;
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = tolower(plaintext[i]);
            }
            n = (int) plaintext[i] - 97;
            temp = (char) (n + (int) key[j % KEY_LENGTH]);
            if (temp > 122) {
                temp = 96 + (temp % 122);
            }
            ciphertext[i] = temp;
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, n;
    char temp;
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            n = (int) ciphertext[i] - 97;
            temp = (char) (n - (int) key[j % KEY_LENGTH]);
            if (temp < 97) {
                temp = 122 + (temp % 122);
            }
            plaintext[i] = temp;
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[KEY_LENGTH];
    int i;

    generate_key(key);
    printf("Key: %s\n", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);
    printf("Decrypted: %s\n", plaintext);

    return 0;
}