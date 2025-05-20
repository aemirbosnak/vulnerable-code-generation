//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 32
#define MAX_INPUT_SIZE 1024

// Function to shift the characters in the key
void shift_key(char *key, int shift) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(key) - 1; i < j; i++, j--) {
        temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
}

// Function to encrypt the input using the key
void encrypt(char *input, char *key) {
    int i, j, k;
    char temp;
    for (i = 0, j = 0, k = strlen(input); i < k; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        temp = input[i];
        input[i] = key[j];
        key[j] = temp;
    }
}

// Function to decrypt the input using the key
void decrypt(char *input, char *key) {
    int i, j, k;
    char temp;
    for (i = 0, j = 0, k = strlen(input); i < k; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        temp = input[i];
        input[i] = key[j];
        key[j] = temp;
    }
}

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE], key[MAX_KEY_SIZE];
    int key_size, choice;

    // Get the input from the user
    printf("Enter the input: ");
    scanf("%s", input);

    // Get the key size from the user
    printf("Enter the key size (1-32): ");
    scanf("%d", &key_size);

    // Generate a random key
    generate_key(key);

    // Get the choice from the user
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    // Encrypt or decrypt the input based on the choice
    if (choice == 1) {
        encrypt(input, key);
        printf("Encrypted input: %s\n", input);
    } else if (choice == 2) {
        decrypt(input, key);
        printf("Decrypted input: %s\n", input);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}