//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

// Function to encrypt the file
void encrypt(FILE *input_file, FILE *output_file) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1] = {0};
    int i;

    while (fread(input_buffer, 1, BLOCK_SIZE, input_file) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            output_buffer[i] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(output_buffer, 1, BLOCK_SIZE, output_file);
    }
}

// Function to decrypt the file
void decrypt(FILE *input_file, FILE *output_file) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1] = {0};
    int i;

    while (fread(input_buffer, 1, BLOCK_SIZE, input_file) > 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            output_buffer[i] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(output_buffer, 1, BLOCK_SIZE, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char filename[100];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the input file for reading
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create the output file for writing
    output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Encrypt the file
    encrypt(input_file, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}