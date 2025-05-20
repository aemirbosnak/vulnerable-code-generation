//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom encryption key
#define ENCRYPTION_KEY 0x42

int main() {
    // Get the input file name from the user
    char input_file[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", input_file);

    // Get the output file name from the user
    char output_file[100];
    printf("Enter the name of the encrypted file: ");
    scanf("%s", output_file);

    // Open the input file for reading
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Read the input file character by character
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // XOR the character with the encryption key
        ch ^= ENCRYPTION_KEY;

        // Write the encrypted character to the output file
        fputc(ch, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");

    return EXIT_SUCCESS;
}