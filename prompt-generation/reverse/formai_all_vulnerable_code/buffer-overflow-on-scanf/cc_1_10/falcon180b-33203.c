//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_INPUT_SIZE 4096

// Function to convert a string to uppercase
void strtoupper(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    int i = 0;
    while (i < MAX_KEY_SIZE) {
        key[i] = rand() % 26 + 'A';
        i++;
    }
    key[i] = '\0';
}

// Function to encrypt the input using the key
void encrypt(char* input, char* key) {
    int i = 0;
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                input[i] = 'A' + (input[i] - 'A' + toupper(key[i % strlen(key)]) - 'A') % 26;
            } else {
                input[i] = 'A' + (input[i] - 'a' + toupper(key[i % strlen(key)]) - 'A') % 26;
            }
        }
        i++;
    }
}

// Function to decrypt the input using the key
void decrypt(char* input, char* key) {
    int i = 0;
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                input[i] = 'A' + (input[i] - 'A' - toupper(key[i % strlen(key)]) + 26) % 26;
            } else {
                input[i] = 'A' + (input[i] - 'a' - toupper(key[i % strlen(key)]) + 26) % 26;
            }
        }
        i++;
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char key[MAX_KEY_SIZE];

    // Get user input
    printf("Enter plaintext: ");
    scanf("%s", input);

    // Generate key
    generate_key(key);

    // Encrypt input
    encrypt(input, key);

    // Print encrypted text
    printf("Encrypted text: %s\n", input);

    // Decrypt input
    decrypt(input, key);

    // Print decrypted text
    printf("Decrypted text: %s\n", input);

    return 0;
}