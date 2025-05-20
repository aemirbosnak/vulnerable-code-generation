//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65; // Encrypt uppercase letters
            } else {
                message[i] = (message[i] + key - 97) % 26 + 97; // Encrypt lowercase letters
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key - 65) % 26 + 65; // Decrypt uppercase letters
            } else {
                message[i] = (message[i] - key - 97) % 26 + 97; // Decrypt lowercase letters
            }
        }
    }
}

int main() {
    char message[100], key;
    printf("Enter a message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("\nEncrypted message: %s", message);

    // Decrypt the message
    decrypt(message, key);
    printf("\nDecrypted message: %s", message);

    return 0;
}