//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256

// Function to calculate the hash of a string
int hash(char* str) {
    int sum = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        sum += tolower(str[i]);
    }

    return sum % SIZE;
}

// Function to encrypt a string
void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
            str[i] = (str[i] - 'a' + key) % 26 + 'a';
        }
    }
}

// Function to decrypt a string
void decrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
            str[i] = (str[i] - 'a' - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char input[1000];
    char key[100];

    // Get the input string from the user
    printf("Enter the string to encrypt/decrypt: ");
    scanf("%[^\n]", input);

    // Get the encryption/decryption key from the user
    printf("Enter the key: ");
    scanf("%[^\n]", key);

    // Calculate the hash of the input string
    int hash_val = hash(input);

    // Encrypt the input string using the key
    encrypt(input, hash_val);

    // Print the encrypted string
    printf("Encrypted string: %s\n", input);

    // Decrypt the encrypted string using the key
    decrypt(input, hash_val);

    // Print the decrypted string
    printf("Decrypted string: %s\n", input);

    return 0;
}