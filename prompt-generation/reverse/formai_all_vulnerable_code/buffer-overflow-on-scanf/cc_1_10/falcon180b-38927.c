//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int i, j, key_index = 0;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = 'A' + ((message[i] - 'A' + key[key_index] - 'A') % 26);
            } else {
                encrypted_message[i] = 'a' + ((message[i] - 'a' + key[key_index] - 'a') % 26);
            }
        } else {
            encrypted_message[i] = message[i];
        }

        if (++key_index >= strlen(key)) {
            key_index = 0;
        }
    }

    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int i, j, key_index = 0;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = 'A' + ((message[i] - 'A' - key[key_index] + 26) % 26);
            } else {
                decrypted_message[i] = 'a' + ((message[i] - 'a' - key[key_index] + 26) % 26);
            }
        } else {
            decrypted_message[i] = message[i];
        }

        if (++key_index >= strlen(key)) {
            key_index = 0;
        }
    }

    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}