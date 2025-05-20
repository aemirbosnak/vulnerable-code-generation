//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform bitwise XOR operation on two integers
int xor(int a, int b) {
    return a ^ b;
}

// Function to read input file and store its contents in a buffer
void readInputFile(FILE *inputFile, char *buffer) {
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    rewind(inputFile);
    fread(buffer, sizeof(char), fileSize, inputFile);
}

// Function to write output file with hidden message
void writeOutputFile(FILE *outputFile, char *buffer, int messageSize) {
    int i = 0;
    while (i < messageSize) {
        fwrite(&buffer[i], sizeof(char), 1, outputFile);
        i++;
    }
}

// Function to hide message in image using steganography
void hideMessage(char *inputFile, char *outputFile, char *message) {
    FILE *input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    int messageSize = strlen(message);
    char *buffer = malloc(messageSize + 1);
    strcpy(buffer, message);

    int imageSize = 0;
    char *imageBuffer = NULL;

    while (fgetc(input)!= EOF) {
        imageBuffer = realloc(imageBuffer, imageSize + sizeof(char));
        imageBuffer[imageSize++] = fgetc(input);
    }

    int i = 0;
    while (i < messageSize) {
        imageBuffer[i * 2] ^= buffer[i];
        i++;
    }

    fwrite(imageBuffer, sizeof(char), imageSize, output);

    free(buffer);
    free(imageBuffer);

    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file message\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *message = argv[3];

    hideMessage(inputFile, outputFile, message);

    printf("Message hidden successfully.\n");

    return 0;
}