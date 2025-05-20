//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key
#define KEY "Peace"

// Encrypt a single character
char encrypt(char c) {
    return c ^ KEY[0];
}

// Encrypt a string
char *encrypt_string(char *str) {
    char *encrypted_str = malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        encrypted_str[i] = encrypt(str[i]);
    }
    encrypted_str[strlen(str)] = '\0';
    return encrypted_str;
}

// Decrypt a single character
char decrypt(char c) {
    return c ^ KEY[0];
}

// Decrypt a string
char *decrypt_string(char *str) {
    char *decrypted_str = malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        decrypted_str[i] = decrypt(str[i]);
    }
    decrypted_str[strlen(str)] = '\0';
    return decrypted_str;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter the string you want to encrypt: ");
    scanf("%s", str);

    // Encrypt the string
    char *encrypted_str = encrypt_string(str);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted_str);

    // Decrypt the string
    char *decrypted_str = decrypt_string(encrypted_str);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted_str);

    // Free the allocated memory
    free(encrypted_str);
    free(decrypted_str);

    return 0;
}