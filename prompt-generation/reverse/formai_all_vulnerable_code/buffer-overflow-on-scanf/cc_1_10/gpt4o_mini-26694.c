//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024 // Maximum length for the content

// Function to shift characters for Caesar cipher
char shift_char(char ch, int shift) {
    // Only shift alphabetic characters
    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' + shift + 26) % 26; // Wrap around for lowercase
    } else if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' + shift + 26) % 26; // Wrap around for uppercase
    }
    return ch; // Non-alphabetic characters remain unchanged
}

// Function to encrypt or decrypt a file
void process_file(const char *input_filename, const char *output_filename, int shift) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (!input_file || !output_file) {
        fprintf(stderr, "Oops! Could not open the file. Please check the file names.\n");
        exit(1);
    }
    
    char line[MAX_LEN];
    while (fgets(line, sizeof(line), input_file)) {
        for (int i = 0; line[i]; i++) {
            line[i] = shift_char(line[i], shift);
        }
        fprintf(output_file, "%s", line);
    }
    
    fclose(input_file);
    fclose(output_file);
    printf("Yay! The file was processed! 🎉✨\n");
}

int main() {
    printf("Welcome to the Happy File Encryptor! 😊✍️\n");
    printf("Let's secure your files with some joyful encryption!\n");

    char input_filename[100];
    char output_filename[100];
    int shift;

    // User input for filenames and shift value
    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%99s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%99s", output_filename);
    printf("Enter the shift value for encryption (positive for encrypt, negative for decrypt): ");
    scanf("%d", &shift);

    // Process the file according to the user's input
    process_file(input_filename, output_filename, shift);
    printf("Great job! Your file has been safely processed! 📁💖\n");
    printf("Remember to keep your shifted values safe, just like you would a secret! 🤫✨\n");
    
    return 0;
}