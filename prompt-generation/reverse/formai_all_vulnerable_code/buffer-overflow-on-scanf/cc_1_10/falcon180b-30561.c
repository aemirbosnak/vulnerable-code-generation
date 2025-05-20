//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 25
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt(char *message, char *key) {
    int i, j, k;
    char encrypted_message[MAX_MESSAGE_LENGTH + 1];

    encrypted_message[0] = '\0';

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }

    i = 0;
    j = 0;
    while (message[i]!= '\0') {
        k = 0;
        while (key[j]!= '\0' && k < strlen(key)) {
            if (isalpha(message[i])) {
                if (isalpha(key[j])) {
                    encrypted_message[k] = (message[i] - key[j] + 26) % 26 + 'a';
                } else {
                    encrypted_message[k] = message[i];
                }
            } else {
                encrypted_message[k] = message[i];
            }
            j++;
            k++;
        }
        i++;
        j = 0;
    }

    encrypted_message[k - 1] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j, k;
    char decrypted_message[MAX_MESSAGE_LENGTH + 1];

    decrypted_message[0] = '\0';

    i = 0;
    j = 0;
    while (encrypted_message[i]!= '\0') {
        k = 0;
        while (key[j]!= '\0' && k < strlen(key)) {
            if (isalpha(encrypted_message[i])) {
                if (isalpha(key[j])) {
                    decrypted_message[k] = (encrypted_message[i] - key[j] + 26) % 26 + 'A';
                } else {
                    decrypted_message[k] = encrypted_message[i];
                }
            } else {
                decrypted_message[k] = encrypted_message[i];
            }
            j++;
            k++;
        }
        i++;
        j = 0;
    }

    decrypted_message[k - 1] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH + 1];
    char key[MAX_KEY_LENGTH + 1];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%s", key);

    generate_key(key);

    encrypt(message, key);

    decrypt(message, key);

    return 0;
}