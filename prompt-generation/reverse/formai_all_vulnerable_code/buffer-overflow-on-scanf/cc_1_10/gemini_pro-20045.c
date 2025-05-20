//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Retro-style ASCII art for program header
char *ascii_art =
    " _________________________________________________  \n"
    "|  ____________________    ____________________  | \n"
    "| |   __   __  ______   |  |  __   __  ______   | | \n"
    "| |  |  | |  | |      |  | | |  | |  | |      |  | | \n"
    "| |  |  | |  | |______|  | | |  | |  | |______|  | | \n"
    "| |  |  | |  |          | | |  | |  |          |  | | \n"
    "| |  |  | |  |          | | |  | |  |      ____  |  | | \n"
    "| |  |  |  ________    | | |  | |  |_____|_   \ |  | | \n"
    "| |  |  |  |        \  | | |  |  |   _______)  \|  | | \n"
    "| |  |  |  |_________/  | | |  | |  |          |  | | \n"
    "| |____________________|  | |__| |__|          |  | | \n"
    "|  ____________________|____________________|  | \n"
    "|_________________________________________________| \n";

// Function to encrypt a file using XOR cipher
void encrypt_file(FILE *input, FILE *output, char *key) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ *key, output);
        key++;
        if (*key == '\0') {
            key = key - strlen(key);
        }
    }
}

// Function to decrypt a file using XOR cipher
void decrypt_file(FILE *input, FILE *output, char *key) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ *key, output);
        key++;
        if (*key == '\0') {
            key = key - strlen(key);
        }
    }
}

// Main function
int main() {
    // Print ASCII art header
    printf("%s\n", ascii_art);

    // Variables
    char input_filename[100], output_filename[100], key[100];
    int choice;

    // Get user input
    printf("\nEnter the input filename: ");
    scanf("%s", input_filename);
    printf("Enter the output filename: ");
    scanf("%s", output_filename);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);
    printf("Choose an option:\n1. Encrypt file\n2. Decrypt file\n");
    scanf("%d", &choice);

    // Open input and output files
    FILE *input = fopen(input_filename, "rb");
    FILE *output = fopen(output_filename, "wb");

    // Perform encryption or decryption based on user choice
    switch (choice) {
        case 1:
            encrypt_file(input, output, key);
            break;
        case 2:
            decrypt_file(input, output, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    // Retro-style ending message
    printf("\nEncrypted/decrypted file: %s\n", output_filename);
    printf("May your secrets remain concealed!\n");

    return 0;
}