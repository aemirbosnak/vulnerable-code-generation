//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

void init_key(char key[], int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char message[], char key[], int key_size, char ciphertext[]) {
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            ciphertext[j] = (message[i] + key[j % key_size] - 'a' + 26) % 26 + 'a';
            j++;
        } else {
            ciphertext[j] = message[i];
            j++;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char ciphertext[], char key[], int key_size, char message[]) {
    int i, j, k;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            message[j] = (ciphertext[i] - key[j % key_size] + 26) % 26 + 'a';
            j++;
        } else {
            message[j] = ciphertext[i];
            j++;
        }
    }
    message[j] = '\0';
}

int main() {
    char message[SIZE];
    char key[26];
    char ciphertext[SIZE];
    int key_size;

    printf("Enter the message to be encrypted: ");
    fgets(message, SIZE, stdin);

    printf("Enter the key to be used for encryption: ");
    scanf("%s", key);

    key_size = strlen(key);
    init_key(key, key_size);

    encrypt(message, key, key_size, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, key_size, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}