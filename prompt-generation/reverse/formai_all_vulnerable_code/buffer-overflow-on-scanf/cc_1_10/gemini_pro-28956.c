//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to encrypt a string using a Caesar cipher with a given shift value
char* encrypt_caesar(char* str, int shift) {
    // Base case: If the string is empty, return the empty string
    if (*str == '\0') {
        return str;
    }

    // Encrypt the current character
    char encrypted_char = *str + shift;

    // Recursively encrypt the remaining string
    char* encrypted_rest = encrypt_caesar(str + 1, shift);

    // Create a new string to store the encrypted result
    char* encrypted_str = malloc(strlen(str) + 1);

    // Copy the encrypted characters into the new string
    encrypted_str[0] = encrypted_char;
    strcpy(encrypted_str + 1, encrypted_rest);

    // Free the memory allocated for the recursively encrypted string
    free(encrypted_rest);

    // Return the encrypted string
    return encrypted_str;
}

// Recursive function to decrypt a string using a Caesar cipher with a given shift value
char* decrypt_caesar(char* str, int shift) {
    // Base case: If the string is empty, return the empty string
    if (*str == '\0') {
        return str;
    }

    // Decrypt the current character
    char decrypted_char = *str - shift;

    // Recursively decrypt the remaining string
    char* decrypted_rest = decrypt_caesar(str + 1, shift);

    // Create a new string to store the decrypted result
    char* decrypted_str = malloc(strlen(str) + 1);

    // Copy the decrypted characters into the new string
    decrypted_str[0] = decrypted_char;
    strcpy(decrypted_str + 1, decrypted_rest);

    // Free the memory allocated for the recursively decrypted string
    free(decrypted_rest);

    // Return the decrypted string
    return decrypted_str;
}

int main() {
    // Get the input string from the user
    char* str = malloc(100);
    printf("Enter the string to encrypt: ");
    scanf("%s", str);

    // Get the shift value from the user
    int shift;
    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Encrypt the string using the recursive Caesar cipher function
    char* encrypted_str = encrypt_caesar(str, shift);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted_str);

    // Decrypt the encrypted string using the recursive Caesar cipher function
    char* decrypted_str = decrypt_caesar(encrypted_str, shift);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted_str);

    // Free the memory allocated for the strings
    free(str);
    free(encrypted_str);
    free(decrypted_str);

    return 0;
}