//Falcon-180B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to encrypt the given string
void encrypt(char *input, char *key) {
    int i, j, n = strlen(input);
    char output[MAX_LENGTH];

    // Initialize the matrix
    int matrix[26][26] = { 0 };

    // Fill the matrix with random numbers
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            matrix[i][j] = rand() % 26;
        }
    }

    // Encrypt the string
    for (i = 0; i < n; i++) {
        if (isalpha(input[i])) {
            int row = input[i] - 'a';
            int col = matrix[row][key[i] - 'a'] % 26;
            output[i] = (char) (col + 'a');
        } else {
            output[i] = input[i];
        }
    }

    // Print the encrypted string
    printf("Encrypted string: %s\n", output);
}

int main() {
    char input[MAX_LENGTH], key[MAX_LENGTH];

    // Get the input string from the user
    printf("Enter the string to be encrypted: ");
    scanf("%s", input);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the string
    encrypt(input, key);

    return 0;
}