//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a string using a simple Caesar cipher
char* encrypt(char* str, int shift) {
    int len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        result[i] = (char)(str[i] + shift - 'A');
    }
    result[len] = '\0';
    return result;
}

// Function to decrypt a string using the same Caesar cipher
char* decrypt(char* str, int shift) {
    int len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        result[i] = (char)(str[i] - shift + 'A');
    }
    result[len] = '\0';
    return result;
}

int main() {
    // Prompt the user for the string to encrypt
    printf("Enter a string to encrypt: ");
    char* input = (char*)malloc(1000 * sizeof(char));
    scanf("%s", input);

    // Prompt the user for the shift value (0-25)
    printf("Enter the shift value (0-25): ");
    int shift = 0;
    scanf("%d", &shift);

    // Encrypt the string and print the result
    char* encrypted = encrypt(input, shift);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the string and print the result
    char* decrypted = decrypt(encrypted, shift);
    printf("Decrypted string: %s\n", decrypted);

    // Free the dynamically allocated memory
    free(input);
    free(encrypted);
    free(decrypted);

    return 0;
}