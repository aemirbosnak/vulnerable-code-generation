//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_FILENAME_LENGTH = 256;
const int BUFFER_SIZE = 1024;

void encrypt(FILE* inputFile, FILE* outputFile, int key) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }
}

int main(int argc, char* argv[]) {
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    int key;

    printf("Enter input filename: ");
    fgets(inputFilename, MAX_FILENAME_LENGTH, stdin);
    inputFilename[strcspn(inputFilename, "\n")] = '\0'; // remove trailing newline character

    printf("Enter output filename: ");
    fgets(outputFilename, MAX_FILENAME_LENGTH, stdin);
    outputFilename[strcspn(outputFilename, "\n")] = '\0'; // remove trailing newline character

    printf("Enter encryption key: ");
    scanf("%d", &key);

    FILE* inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    encrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete.\n");

    return EXIT_SUCCESS;
}