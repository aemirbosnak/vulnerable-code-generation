//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 100

void encrypt(char* message, char* key) {
    int i, j, k;
    char encrypted_message[MAX_MESSAGE_SIZE];

    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (message[i] + key[j % MAX_KEY_SIZE]) % 26 + 65;
            } else {
                encrypted_message[j] = (message[i] + key[j % MAX_KEY_SIZE]) % 26 + 97;
            }
        } else {
            encrypted_message[j] = message[i];
        }
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int i, j, k;
    char decrypted_message[MAX_MESSAGE_SIZE];

    for (i = 0, j = 0; i < strlen(encrypted_message); i++, j++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = ((encrypted_message[i] - key[j % MAX_KEY_SIZE]) % 26) + 65;
            } else {
                decrypted_message[j] = ((encrypted_message[i] - key[j % MAX_KEY_SIZE]) % 26) + 97;
            }
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}