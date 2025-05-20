//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(const char *plaintext, char *ciphertext, int shift) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabet characters remain unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null-terminate the string
}

void decrypt(const char *ciphertext, char *plaintext, int shift) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Non-alphabet characters remain unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null-terminate the string
}

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fread(buffer, sizeof(char), MAX_LENGTH, file);
    fclose(file);
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fputs(content, file);
    fclose(file);
}

int main() {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char decryptedtext[MAX_LENGTH];
    int shift;

    // Read text from file
    printf("Enter the filename to read from: ");
    char input_filename[100];
    scanf("%s", input_filename);
    read_file(input_filename, plaintext);

    // Get the shift value for encryption
    printf("Enter the shift value for encryption (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Shift value must be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext, shift);
    printf("Encrypted text: %s\n", ciphertext);

    // Write the encrypted text to a file
    char output_filename[100];
    printf("Enter the filename to write encrypted text to: ");
    scanf("%s", output_filename);
    write_file(output_filename, ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, decryptedtext, shift);
    printf("Decrypted text: %s\n", decryptedtext);

    // Optionally write decrypted text to a file
    char decrypted_filename[100];
    printf("Enter the filename to write decrypted text to (enter 'none' to skip): ");
    scanf("%s", decrypted_filename);
    if (strcmp(decrypted_filename, "none") != 0) {
        write_file(decrypted_filename, decryptedtext);
    }

    return EXIT_SUCCESS;
}