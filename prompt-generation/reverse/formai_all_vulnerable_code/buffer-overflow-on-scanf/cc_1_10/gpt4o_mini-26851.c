//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT_AMOUNT 3
#define MAX_FILENAME_LENGTH 256

void encrypt_character(char* character) {
    // An introspective look into how a simple shift can obscure meaning.
    *character = *character + SHIFT_AMOUNT;
}

void decrypt_character(char* character) {
    // Reversing the encryption to unveil the original content.
    *character = *character - SHIFT_AMOUNT;
}

void process_file(const char* input_filename, const char* output_filename, int encrypt) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Failed to open input file");
        return;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Failed to open output file");
        fclose(input_file);
        return;
    }

    // The journey through the file begins.
    char character;
    while (fread(&character, sizeof(char), 1, input_file) == 1) {
        if (encrypt) {
            encrypt_character(&character);
        } else {
            decrypt_character(&character);
        }
        fwrite(&character, sizeof(char), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void ask_for_filename(const char* prompt, char* filename) {
    printf("%s", prompt);
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    
    // Remove trailing newline, a subtle yet important aspect of clarity.
    filename[strcspn(filename, "\n")] = 0;
}

int main() {
    printf("Welcome to the Introspective File Encryptor!\n");

    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];

    ask_for_filename("Enter the input filename: ", input_filename);
    ask_for_filename("Enter the output filename: ", output_filename);
    
    // Choices made, the path to encryption or decryption begins.
    int choice;
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nYour choice: ");
    scanf("%d", &choice);

    // An understanding of decisions - to encrypt or to decrypt.
    if (choice == 1) {
        process_file(input_filename, output_filename, 1);
        printf("File encrypted successfully!\n");
    } else if (choice == 2) {
        process_file(input_filename, output_filename, 0);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid choice! Exiting program.\n");
    }

    return 0;
}