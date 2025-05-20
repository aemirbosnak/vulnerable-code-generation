//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long! ");
        return;
    }

    int i, j;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = ((message[i] + key[j % key_length] - 'A' + 26) % 26) + 'A';
            } else {
                encrypted_message[j] = ((message[i] + key[j % key_length] - 'a' + 26) % 26) + 'a';
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long! ");
        return;
    }

    int i, j;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[j] = ((message[i] - key[j % key_length] + 26) % 26) + 'A';
            } else {
                decrypted_message[j] = ((message[i] - key[j % key_length] + 26) % 26) + 'a';
            }
            j++;
        } else {
            decrypted_message[j] = message[i];
            j++;
        }
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}