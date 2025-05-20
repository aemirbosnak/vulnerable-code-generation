//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the input string
void encrypt(char *input, int key) {
    int length = strlen(input);
    char *output = malloc(length + 1);
    int i;

    // Encrypt each character in the input string
    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = 'A' + ((int)input[i] - 65 + key) % 26;
            } else {
                output[i] = 'a' + ((int)input[i] - 97 + key) % 26;
            }
        } else {
            output[i] = input[i];
        }
    }
    output[length] = '\0';

    // Print the encrypted string
    printf("Encrypted string: %s\n", output);

    // Free the memory allocated for the output string
    free(output);
}

// Function to decrypt the input string
void decrypt(char *input, int key) {
    int length = strlen(input);
    char *output = malloc(length + 1);
    int i;

    // Decrypt each character in the input string
    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = 'A' + ((int)input[i] - 65 - key + 26) % 26;
            } else {
                output[i] = 'a' + ((int)input[i] - 97 - key + 26) % 26;
            }
        } else {
            output[i] = input[i];
        }
    }
    output[length] = '\0';

    // Print the decrypted string
    printf("Decrypted string: %s\n", output);

    // Free the memory allocated for the output string
    free(output);
}

int main() {
    char input[100];
    int key;

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the input string
    encrypt(input, key);

    // Decrypt the encrypted string
    char *encrypted = malloc(strlen(input) + 1);
    strcpy(encrypted, input);
    decrypt(encrypted, key);

    // Free the memory allocated for the encrypted string
    free(encrypted);

    return 0;
}