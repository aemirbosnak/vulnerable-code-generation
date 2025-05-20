//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to encrypt the text using a basic Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a'; // Shift for lowercase characters
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A'; // Shift for uppercase characters
        }
        text[i] = ch; // Assign the modified character back to the text
    }
}

// Function to decrypt the text
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decrypt by applying the same logic with the inverse shift
}

// Function to read and process the input text file
void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(buffer, sizeof(char), MAX_LEN, file);
    buffer[bytes_read] = '\0'; // Null-terminate the string
    fclose(file);
}

// Function to write the encrypted text to an output file
void write_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", buffer); // Write the buffer to the file
    fclose(file);
}

int main() {
    char input_file[MAX_LEN];
    char output_file[MAX_LEN];
    char buffer[MAX_LEN];
    int shift;

    // User input for file names and shift value
    printf("Enter the input file name (with .txt): ");
    fgets(input_file, MAX_LEN, stdin);
    strtok(input_file, "\n"); // Remove newline character from the string

    printf("Enter the output file name (with .txt): ");
    fgets(output_file, MAX_LEN, stdin);
    strtok(output_file, "\n"); // Remove newline character from the string
    
    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Must be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    // Read the content from the input file
    read_file(input_file, buffer);
    printf("Original text:\n%s\n\n", buffer);

    // Encrypt the read text
    encrypt(buffer, shift);
    printf("Encrypted text:\n%s\n\n", buffer);

    // Write the encrypted text to the specified output file
    write_file(output_file, buffer);
    printf("Encrypted text has been written to %s\n", output_file);

    // Optionally decrypt the text and display it
    decrypt(buffer, shift);
    printf("Decrypted text:\n%s\n\n", buffer);

    return 0;
}