//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 16

// Function to convert a string to uppercase
void toUpper(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to encrypt a file
void encryptFile(FILE* inputFile, FILE* outputFile) {
    char buffer[1024];
    int bytesRead;

    // Read the input file in chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        // Convert the buffer to uppercase
        toUpper(buffer);

        // XOR the buffer with the key
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ KEY[i % KEY_LENGTH];
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, 1, bytesRead, outputFile);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    encryptFile(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption completed successfully.\n");

    return 0;
}