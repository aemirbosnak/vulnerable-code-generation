//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input string using Caesar Cipher
void encrypt(char* input, int key) {
    int i = 0;
    char output[strlen(input)];
    while (input[i]) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = (input[i] + key - 65) % 26 + 65;
            } else {
                output[i] = (input[i] + key - 97) % 26 + 97;
            }
        } else {
            output[i] = input[i];
        }
        i++;
    }
    printf("Encrypted string: %s\n", output);
}

// Function to decrypt the input string using Caesar Cipher
void decrypt(char* input, int key) {
    int i = 0;
    char output[strlen(input)];
    while (input[i]) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = (input[i] - key - 65) % 26 + 65;
            } else {
                output[i] = (input[i] - key - 97) % 26 + 97;
            }
        } else {
            output[i] = input[i];
        }
        i++;
    }
    printf("Decrypted string: %s\n", output);
}

// Function to generate a random key
int generateKey() {
    int key = rand() % 26 + 1;
    return key;
}

int main() {
    char input[100];
    int key;

    // Take input string from user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Generate a random key
    key = generateKey();

    // Encrypt the input string using Caesar Cipher
    encrypt(input, key);

    // Decrypt the encrypted string using Caesar Cipher
    decrypt(input, key);

    return 0;
}