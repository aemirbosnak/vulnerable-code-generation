//Falcon-180B DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given string
void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = ((str[i] - 'A' + key) % 26) + 'A';
            } else {
                str[i] = ((str[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}

// Function to decrypt the given string
void decrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
            }
        }
    }
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}