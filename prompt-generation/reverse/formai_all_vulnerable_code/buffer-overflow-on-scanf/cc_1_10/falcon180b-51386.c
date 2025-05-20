//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int i, j, n;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    n = strlen(message);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            encrypted_message[j++] = (char) ((int) message[i] + (int) key[i % MAX_KEY_LENGTH]);
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j, n;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    n = strlen(encrypted_message);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = tolower(encrypted_message[i]);
            decrypted_message[j++] = (char) ((int) encrypted_message[i] - (int) key[i % MAX_KEY_LENGTH]);
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter a key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}