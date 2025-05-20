//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void encrypt(char *message, int key) {
    int message_length = strlen(message);
    char encrypted_message[MAX_SIZE];
    int encrypted_length = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[encrypted_length] = (message[i] + key - 65) % 26 + 65;
            } else {
                encrypted_message[encrypted_length] = (message[i] + key - 97) % 26 + 97;
            }
            encrypted_length++;
        } else {
            encrypted_message[encrypted_length] = message[i];
            encrypted_length++;
        }
    }

    encrypted_message[encrypted_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, int key) {
    int encrypted_length = strlen(encrypted_message);
    char decrypted_message[MAX_SIZE];
    int decrypted_length = 0;

    for (int i = 0; i < encrypted_length; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[decrypted_length] = (encrypted_message[i] - key - 65) % 26 + 65;
            } else {
                decrypted_message[decrypted_length] = (encrypted_message[i] - key - 97) % 26 + 97;
            }
            decrypted_length++;
        } else {
            decrypted_message[decrypted_length] = encrypted_message[i];
            decrypted_length++;
        }
    }

    decrypted_message[decrypted_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_SIZE];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(encrypted_message, key);

    return 0;
}