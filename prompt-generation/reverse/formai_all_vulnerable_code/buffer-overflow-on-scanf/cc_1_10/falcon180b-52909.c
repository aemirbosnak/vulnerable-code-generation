//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 0

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file, int mode) {
    char ch;
    int key = 5; // Change this value for a different encryption key
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            if (mode == ENCRYPT) {
                ch = toupper(ch) + key;
            } else {
                ch = ch - key;
            }
        }
        fputc(ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open input and output files
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Ask user for encryption or decryption
    int choice;
    printf("Enter 1 to encrypt or 0 to decrypt: ");
    scanf("%d", &choice);

    // Call encryption function
    encrypt_file(input_file, output_file, choice);

    printf("File encryption/decryption completed successfully!\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}