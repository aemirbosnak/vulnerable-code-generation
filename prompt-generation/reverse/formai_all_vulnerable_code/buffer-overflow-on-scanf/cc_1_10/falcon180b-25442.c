//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void encrypt(char* message, int key) {
    int length = strlen(message);
    char encrypted_message[MAX_LENGTH];
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = (char) ((int) message[i] + key - 65);
            } else {
                encrypted_message[j] = (char) ((int) message[i] + key - 97);
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

void decrypt(char* message, int key) {
    int length = strlen(message);
    char decrypted_message[MAX_LENGTH];
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[j] = (char) ((int) message[i] - key - 65 + 26) % 26 + 65;
            } else {
                decrypted_message[j] = (char) ((int) message[i] - key - 97 + 26) % 26 + 97;
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
    char message[MAX_LENGTH];
    int key, choice;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter the encryption/decryption key (0-25): ");
    scanf("%d", &key);
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}