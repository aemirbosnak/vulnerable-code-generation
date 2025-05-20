//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) (((int) message[i] + key - 65) % 26 + 65);
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) (((int) message[i] - 65 - key) % 26 + 65);
        }
    }
}

// Function to print the encrypted/decrypted message
void print_message(char* message) {
    for (int i = 0; message[i]!= '\0'; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    char message[1000];
    int key;

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: ");
    print_message(message);

    decrypt(message, key);
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}