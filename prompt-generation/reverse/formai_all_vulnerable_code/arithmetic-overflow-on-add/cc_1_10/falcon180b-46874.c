//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            } else {
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}

void decrypt(char* message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
        }
    }
}

int main() {
    char message[100];
    int key, choice;
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter the key (1-25): ");
    scanf("%d", &key);
    printf("Enter 1 for encryption and 2 for decryption: ");
    scanf("%d", &choice);
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}