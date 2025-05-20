//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Encrypt a single character using the Caesar cipher
char encrypt(char c) {
    int index = strchr(key, c) - key;
    return key[(index + 3) % 26];
}

// Encrypt a string using the Caesar cipher
char *encrypt_string(char *s) {
    char *encrypted = malloc(strlen(s) + 1);
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        encrypted[i] = encrypt(s[i]);
    }
    encrypted[i] = '\0';
    return encrypted;
}

// Decrypt a single character using the Caesar cipher
char decrypt(char c) {
    int index = strchr(key, c) - key;
    return key[(index - 3) % 26];
}

// Decrypt a string using the Caesar cipher
char *decrypt_string(char *s) {
    char *decrypted = malloc(strlen(s) + 1);
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        decrypted[i] = decrypt(s[i]);
    }
    decrypted[i] = '\0';
    return decrypted;
}

// Get a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random key
char *generate_key(int length) {
    char *key = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        key[i] = key[get_random_number(0, 25)];
    }
    key[i] = '\0';
    return key;
}

// Print a string in a box
void print_in_box(char *s) {
    int length = strlen(s);
    printf("+");
    for (int i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");
    printf("| %s |\n", s);
    printf("+");
    for (int i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

// Get a string from the user
char *get_string(char *prompt) {
    char *s = malloc(100);
    printf("%s", prompt);
    scanf("%s", s);
    return s;
}

// Main function
int main() {
    // Get the plaintext from the user
    char *plaintext = get_string("Enter the plaintext: ");

    // Encrypt the plaintext
    char *ciphertext = encrypt_string(plaintext);

    // Print the ciphertext
    print_in_box(ciphertext);

    // Decrypt the ciphertext
    char *decryptedtext = decrypt_string(ciphertext);

    // Print the decrypted text
    print_in_box(decryptedtext);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}