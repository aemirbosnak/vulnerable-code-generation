//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to encrypt the message
void encrypt(char *message, int key) {
    char *new_message = malloc(MAX_LENGTH * sizeof(char));
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[j] = (((int) message[i] - 65 + key) % 26) + 65;
            } else {
                new_message[j] = (((int) message[i] - 97 + key) % 26) + 97;
            }
        } else {
            new_message[j] = message[i];
        }
    }
    new_message[j] = '\0';
    printf("Encrypted message: %s\n", new_message);
    free(new_message);
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    char *new_message = malloc(MAX_LENGTH * sizeof(char));
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                k = (((int) message[i] - 65 - key + 26) % 26) + 65;
            } else {
                k = (((int) message[i] - 97 - key + 26) % 26) + 97;
            }
            new_message[j] = k;
        } else {
            new_message[j] = message[i];
        }
    }
    new_message[j] = '\0';
    printf("Decrypted message: %s\n", new_message);
    free(new_message);
}

int main() {
    char *message;
    int key, choice;

    printf("Enter a message: ");
    scanf("%s", message);
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("Encrypt or Decrypt? (1/2)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}