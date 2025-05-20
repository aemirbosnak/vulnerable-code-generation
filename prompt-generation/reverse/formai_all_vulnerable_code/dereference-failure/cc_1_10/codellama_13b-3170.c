//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: rigorous
/*
 * File Encryptor Example Program
 *
 * Usage: ./file_encryptor [filename]
 *
 * This program will encrypt the contents of the file specified by the user.
 * The encryption algorithm used is a simple XOR cipher.
 *
 * The program will prompt the user for the encryption key and then encrypt
 * the contents of the file using the provided key.
 *
 * The encrypted contents will be stored in a new file with the same name
 * as the original file, but with a ".enc" extension appended to it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_file(char *filename, char *key);

int main(int argc, char *argv[]) {
    // Check if the user has provided a filename as a command line argument
    if (argc != 2) {
        printf("Usage: ./file_encryptor [filename]\n");
        return 1;
    }

    // Get the filename from the command line argument
    char *filename = argv[1];

    // Prompt the user for the encryption key
    char key[BUFFER_SIZE];
    printf("Enter encryption key: ");
    fgets(key, BUFFER_SIZE, stdin);

    // Encrypt the file contents
    encrypt_file(filename, key);

    return 0;
}

void encrypt_file(char *filename, char *key) {
    // Open the input file
    FILE *infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Error opening input file\n");
        return;
    }

    // Create a new output file with the same name as the input file,
    // but with a ".enc" extension appended to it
    char *outfilename = malloc(strlen(filename) + 5);
    sprintf(outfilename, "%s.enc", filename);
    FILE *outfile = fopen(outfilename, "w");
    if (outfile == NULL) {
        printf("Error opening output file\n");
        fclose(infile);
        return;
    }

    // Read the contents of the input file into a buffer
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, infile) != NULL) {
        // Encrypt the buffer using the XOR cipher
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= key[i % strlen(key)];
        }

        // Write the encrypted buffer to the output file
        fputs(buffer, outfile);
    }

    // Close the input and output files
    fclose(infile);
    fclose(outfile);
}