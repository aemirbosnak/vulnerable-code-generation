//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int i, j, key_index = 0;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = 'A' + (message[i] - 'A' + key[key_index] - 'A') % 26;
            } else {
                encrypted_message[i] = 'a' + (message[i] - 'a' + key[key_index] - 'a') % 26;
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int i, j, key_index = 0;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = 'A' + (encrypted_message[i] - 'A' - key[key_index] + 26) % 26;
            } else {
                decrypted_message[i] = 'a' + (encrypted_message[i] - 'a' - key[key_index] + 26) % 26;
            }
            key_index = (key_index + 1) % strlen(key);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%s", key);

    printf("Encrypted message: ");
    encrypt(message, key);

    printf("Decrypted message: ");
    decrypt(message, key);

    return 0;
}