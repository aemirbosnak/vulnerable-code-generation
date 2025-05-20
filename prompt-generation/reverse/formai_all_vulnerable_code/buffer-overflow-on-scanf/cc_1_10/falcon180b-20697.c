//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY "MyEncryptionKey"

void encrypt(char *message, int key_size);
void decrypt(char *message, int key_size);

int main() {
    char message[100];
    int key_size = strlen(KEY);
    char choice;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);

    printf("Encrypt or Decrypt? (E/D): ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(message, key_size);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(message, key_size);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

void encrypt(char *message, int key_size) {
    int i, j;
    char key[key_size];
    strcpy(key, KEY);

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            for (j = 0; j < key_size; j++) {
                message[i] = message[i] + key[j] - 'A';
            }
        }
    }

    printf("Encrypted message: %s\n", message);
}

void decrypt(char *message, int key_size) {
    int i, j;
    char key[key_size];
    strcpy(key, KEY);

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            for (j = 0; j < key_size; j++) {
                message[i] = message[i] - key[j] + 'A';
            }
        }
    }

    printf("Decrypted message: %s\n", message);
}