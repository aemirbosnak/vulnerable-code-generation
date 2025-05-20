//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Function declarations
void encrypt(char plainText[], unsigned int key);
void decrypt(char cipherText[], unsigned int key);

int main() {
    // User input for key and plain text
    unsigned int key;
    char plainText[1000];
    printf("Enter a key (between 1-25): ");
    scanf("%u", &key);
    getchar(); // to consume the newline character after scanf
    printf("Enter a plain text to encrypt: ");
    fgets(plainText, 1000, stdin);
    plainText[strcspn(plainText, "\n")] = 0; // to remove the trailing new line character

    // Encrypt the plain text
    encrypt(plainText, key);
    printf("Encrypted text: %s\n", plainText);

    // Decrypt the cipher text created in the previous step
    decrypt(plainText, key);
    printf("Decrypted text: %s\n", plainText);

    return 0;
}

/*
Encrypts the plain text using the key provided. Uses the caesar cipher algorithm.
Encryption formula: C = (P + K) % 26; where C = Cipher, P = Plain, K = Key
*/
void encrypt(char plainText[], unsigned int key) {
    for(int i=0; plainText[i]!='\0'; i++) {
        if(isalpha(plainText[i])) {
            if(isupper(plainText[i])) {
                plainText[i] = (plainText[i] + key - 'A') % 26 + 'A';
            } else {
                plainText[i] = (plainText[i] + key - 'a') % 26 + 'a';
            }
        }
    }
}

/*
Decrypts the cipher text using the key provided. Uses the caesar cipher algorithm.
Decryption formula: P = (C - K + 26) % 26; where C = Cipher, P = Plain, K = Key
*/
void decrypt(char cipherText[], unsigned int key) {
    for(int i=0; cipherText[i]!='\0'; i++) {
        if(isalpha(cipherText[i])) {
            if(isupper(cipherText[i])) {
                cipherText[i] = (cipherText[i] - key - 'A' + 26) % 26 + 'A';
            } else {
                cipherText[i] = (cipherText[i] - key - 'a' + 26) % 26 + 'a';
            }
        }
    }
}