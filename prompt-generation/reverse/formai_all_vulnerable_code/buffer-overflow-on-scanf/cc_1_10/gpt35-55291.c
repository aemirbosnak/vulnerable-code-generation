//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration
void encrypt_file(char *, char *);

int main() {
    char input_file[100];
    char output_file[100];

    // Get user input for file names
    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Call encrypt_file function
    encrypt_file(input_file, output_file);

    return 0;
}

void encrypt_file(char *input_file, char *output_file) {
    FILE *input, *output;
    char key = 'K'; // Encryption key

    input = fopen(input_file, "rb");
    output = fopen(output_file, "wb");

    if (input == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    if (output == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Read input file and encrypt data
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key; // XOR operator used for encryption
        fputc(ch, output);
    }

    printf("File encryption successful!\n");

    // Close file pointers
    fclose(input);
    fclose(output);
}