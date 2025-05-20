//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

void encrypt(char *message, char *key) {
    int i, j, k;
    char encrypted_message[strlen(message)];

    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = ((int) message[i] + (int) key[j % KEY_LENGTH]) % 26 + 'A';
        } else {
            encrypted_message[j] = message[i];
        }
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j, k;
    char decrypted_message[strlen(encrypted_message)];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = ((int) encrypted_message[i] - (int) key[j % KEY_LENGTH] + 26) % 26 + 'A';
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100], key[KEY_LENGTH];
    int i;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key (16 characters): ");
    fgets(key, KEY_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}