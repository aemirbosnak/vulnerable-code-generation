//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void encrypt(char* message, int key) {
    int i, j;
    char* new_message = malloc(MAX_LENGTH * sizeof(char));
    memset(new_message, 0, MAX_LENGTH);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            } else {
                new_message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            new_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", new_message);
}

void decrypt(char* message, int key) {
    int i, j;
    char* new_message = malloc(MAX_LENGTH * sizeof(char));
    memset(new_message, 0, MAX_LENGTH);

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                new_message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
        } else {
            new_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", new_message);
}

int main() {
    char* message;
    int key, choice;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}