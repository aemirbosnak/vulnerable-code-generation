//FormAI DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to encrypt the given plain text using Caesar Cipher
void ceaser_encrypt(char* plaintext, int key) {
    int i;
    char ch;

    for(i = 0; i < strlen(plaintext); i++) {
        ch = plaintext[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            plaintext[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            plaintext[i] = ch;
        }
    }
}

// Function to decrypt the given cipher text using Caesar Cipher
void ceaser_decrypt(char* ciphertext, int key) {
    int i;
    char ch;

    for(i = 0; i < strlen(ciphertext); i++) {
        ch = ciphertext[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            ciphertext[i] = ch;
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            ciphertext[i] = ch;
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100];
    int key;

    // Get the plain text input from user
    printf("Enter the plain text: ");
    scanf("%[^\n]s", plaintext);

    // Get the key value from user
    printf("Enter the key (a positive integer): ");
    scanf("%d", &key);

    // Encrypt the plain text
    strcpy(ciphertext, plaintext);
    ceaser_encrypt(ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the cipher text
    ceaser_decrypt(ciphertext, key);
    printf("Decrypted text: %s", ciphertext);

    return 0;
}