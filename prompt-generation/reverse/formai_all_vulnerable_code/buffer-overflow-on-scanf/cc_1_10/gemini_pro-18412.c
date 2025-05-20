//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function using XOR cipher
unsigned char encryptByte(unsigned char byte, unsigned char key) {
    return byte ^ key;
}

// Encrypt a file using the XOR cipher
void encryptFile(char *inputFilename, char *outputFilename, unsigned char key) {
    // Open the input and output files
    FILE *inputFile = fopen(inputFilename, "rb");
    FILE *outputFile = fopen(outputFilename, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        exit(1);
    }

    // Read the input file and encrypt the contents
    unsigned char buffer[BUFSIZ];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFSIZ, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] = encryptByte(buffer[i], key);
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully!\n");
}

// Decrypt a file using the XOR cipher
void decryptFile(char *inputFilename, char *outputFilename, unsigned char key) {
    // Open the input and output files
    FILE *inputFile = fopen(inputFilename, "rb");
    FILE *outputFile = fopen(outputFilename, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        exit(1);
    }

    // Read the input file and decrypt the contents
    unsigned char buffer[BUFSIZ];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFSIZ, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] = encryptByte(buffer[i], key);
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File decrypted successfully!\n");
}

// Get the key from the user
unsigned char getKey() {
    unsigned char key;
    printf("Enter the encryption key (a single character): ");
    scanf(" %c", &key);
    return key;
}

// Print the usage information
void printUsage() {
    printf("Usage: file_encryptor [encrypt|decrypt] input_file output_file\n");
    printf("Example: file_encryptor encrypt myfile.txt encrypted.txt\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    // Get the encryption/decryption mode
    char *mode = argv[1];

    // Get the input and output filenames
    char *inputFilename = argv[2];
    char *outputFilename = argv[3];

    // Get the encryption key
    unsigned char key = getKey();

    // Encrypt or decrypt the file
    if (strcmp(mode, "encrypt") == 0) {
        encryptFile(inputFilename, outputFilename, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decryptFile(inputFilename, outputFilename, key);
    } else {
        printUsage();
        return 1;
    }

    return 0;
}