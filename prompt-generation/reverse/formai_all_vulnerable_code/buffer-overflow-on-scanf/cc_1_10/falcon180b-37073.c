//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY "secretkey"
#define KEY_LENGTH 8

void encrypt(char *message) {
    int i, j, k;
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + 'a' - 'A';
        }
    }
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            j = message[i] - 'a';
            k = key[i % KEY_LENGTH] - 'a';
            message[i] = (j + k) % 26 + 'a';
        }
    }
}

void decrypt(char *message) {
    int i, j, k;
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - 'a' + 'A';
        }
    }
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            j = message[i] - 'A';
            k = key[i % KEY_LENGTH] - 'a';
            message[i] = (j - k + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[100], choice;
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%c", &choice);
    switch (choice) {
        case '1':
            encrypt(message);
            printf("Encrypted message: %s\n", message);
            break;
        case '2':
            decrypt(message);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}