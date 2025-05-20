//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <key> <input> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *keyFile = fopen(argv[1], "rb");
    if (keyFile == NULL) {
        fprintf(stderr, "Error opening key file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[2], "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[3], "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    int keySize;
    if (fscanf(keyFile, "%d", &keySize) != 1) {
        fprintf(stderr, "Error reading key size from file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *key = malloc(keySize);
    if (fread(key, 1, keySize, keyFile) != keySize) {
        fprintf(stderr, "Error reading key from file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    fclose(keyFile);

    int inputSize;
    if (fseek(inputFile, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error seeking to end of input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }
    if ((inputSize = ftell(inputFile)) == -1) {
        fprintf(stderr, "Error getting size of input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }
    if (fseek(inputFile, 0, SEEK_SET) != 0) {
        fprintf(stderr, "Error seeking to start of input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    char *input = malloc(inputSize);
    if (fread(input, 1, inputSize, inputFile) != inputSize) {
        fprintf(stderr, "Error reading input from file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    fclose(inputFile);

    for (int i = 0; i < inputSize; i++) {
        input[i] ^= key[i % keySize];
    }

    if (fwrite(input, 1, inputSize, outputFile) != inputSize) {
        fprintf(stderr, "Error writing output to file: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    fclose(outputFile);

    return EXIT_SUCCESS;
}