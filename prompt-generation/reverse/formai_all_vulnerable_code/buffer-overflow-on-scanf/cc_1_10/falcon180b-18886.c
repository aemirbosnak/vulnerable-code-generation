//Falcon-180B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY "Thou shalt not pass!"

// Function to encrypt the message
void encrypt(char* message) {
    int length = strlen(message);
    int key_length = strlen(KEY);

    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            // Encrypt uppercase letters
            if (isupper(c)) {
                c = (c + KEY[i % key_length] - 'A' + 'Z') % 26 + 'A';
            }
            // Encrypt lowercase letters
            else {
                c = (c + KEY[i % key_length] - 'a' + 'z') % 26 + 'a';
            }
        }
        printf("%c", c);
    }
}

// Function to decrypt the message
void decrypt(char* message) {
    int length = strlen(message);
    int key_length = strlen(KEY);

    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            // Decrypt uppercase letters
            if (isupper(c)) {
                c = (c - KEY[i % key_length] - 'A' + 26) % 26 + 'A';
            }
            // Decrypt lowercase letters
            else {
                c = (c - KEY[i % key_length] - 'a' + 26) % 26 + 'a';
            }
        }
        printf("%c", c);
    }
}

// Main function
int main() {
    char message[1000];
    printf("Enter your message: ");
    scanf("%s", message);

    printf("Encrypted message:\n");
    encrypt(message);
    printf("\n");

    printf("Decrypted message:\n");
    decrypt(message);
    printf("\n");

    return 0;
}