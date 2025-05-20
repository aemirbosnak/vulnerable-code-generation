//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character
char encrypt(char ch, int key) {
    return (ch + key) % 26 + 'A';
}

// Function to decrypt a character
char decrypt(char ch, int key) {
    return (ch - key) % 26 + 'A';
}

// Function to encrypt a string
char *encrypt_string(char *str, int key) {
    int len = strlen(str);
    char *encrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = encrypt(str[i], key);
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Function to decrypt a string
char *decrypt_string(char *str, int key) {
    int len = strlen(str);
    char *decrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        decrypted[i] = decrypt(str[i], key);
    }
    decrypted[len] = '\0';
    return decrypted;
}

// Main function
int main() {
    // Get the plaintext and key from the user
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the plaintext
    char *encrypted = encrypt_string(plaintext, key);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted);

    // Decrypt the encrypted text
    char *decrypted = decrypt_string(encrypted, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}