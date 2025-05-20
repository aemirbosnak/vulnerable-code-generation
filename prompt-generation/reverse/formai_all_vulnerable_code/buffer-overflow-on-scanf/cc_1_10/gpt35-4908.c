//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

// Function to get bit value of int at a given position
int getBitValue(int num, int pos) {
    return ((num & (1 << pos)) != 0);
}

// Function to set bit value of int at a given position
void setBitValue(int *num, int pos, int bit) {
    if (bit == 0) {
        *num &= ~(1 << pos);
    } else {
        *num |= (1 << pos);
    }
}

// Function to get secret message length
int getSecretMessageLength(char *secretMessage) {
    int length = 0;
    while (*(secretMessage + length) != '\0') {
        length++;
    }
    return length;
}

// Function to hide secret message in image
void hideSecretMessageInImage(FILE *imageFile, FILE *outputFile, char *secretMessage) {
    // Get secret message length
    int secretMessageLength = getSecretMessageLength(secretMessage);
    if (secretMessageLength > MAX_FILE_SIZE) {
        printf("Error: Maximum secret message size exceeded\n");
        exit(1);
    }

    // Read image file header
    unsigned char imageHeader[54];
    fread(imageHeader, sizeof(unsigned char), 54, imageFile);

    // Write image file header to output file
    fwrite(imageHeader, sizeof(unsigned char), 54, outputFile);

    // Read image data
    unsigned char imageData[MAX_FILE_SIZE];
    int imageDataSize = fread(imageData, sizeof(unsigned char), MAX_FILE_SIZE, imageFile);

    // Initialize variables
    int currentBit = 0;
    int secretMessageIndex = 0;
    int messageBitValue = 0;
    
    // Loop through image data and hide secret message
    for (int i = 0; i < imageDataSize; i++) {
        // Get bit value at current bit position
        messageBitValue = getBitValue(*(secretMessage + secretMessageIndex), currentBit);
        
        // Set least significant bit of image data byte to message bit value
        setBitValue((int *) &imageData[i], 0, messageBitValue);

        // Increment current bit position
        currentBit++;

        // If all bits of current byte have been used, move to next byte
        if (currentBit == 8) {
            currentBit = 0;
            secretMessageIndex++;
        }

        // If end of secret message has been reached, break loop
        if (secretMessageIndex >= secretMessageLength) {
            break;
        }
    }

    // Write modified image data to output file
    fwrite(imageData, sizeof(unsigned char), imageDataSize, outputFile);
}

// Function to extract secret message from image
void extractSecretMessageFromImage(FILE *imageFile, char *secretMessage) {
    // Read image file header
    unsigned char imageHeader[54];
    fread(imageHeader, sizeof(unsigned char), 54, imageFile);

    // Read image data
    unsigned char imageData[MAX_FILE_SIZE];
    int imageDataSize = fread(imageData, sizeof(unsigned char), MAX_FILE_SIZE, imageFile);

    // Initialize variables
    int currentBit = 0;
    int secretMessageIndex = 0;
    int messageBitValue = 0;
    char currentChar = 0;
    
    // Loop through image data and extract secret message
    for (int i = 0; i < imageDataSize; i++) {
        // Get least significant bit of current byte
        messageBitValue = getBitValue(imageData[i], 0);

        // Set bit value of current bit position in current char
        setBitValue((int *) &currentChar, currentBit, messageBitValue);

        // Increment current bit position
        currentBit++;

        // If all bits of current byte have been used, add current char to secret message and move to next char
        if (currentBit == 8) {
            currentBit = 0;
            *(secretMessage + secretMessageIndex) = currentChar;
            secretMessageIndex++;
            currentChar = 0;
        }

        // If end of secret message has been reached, break loop
        if (currentChar == '\0') {
            break;
        }
    }
}

// Main function
int main() {
    // Get input file name
    char inputFile[100];
    printf("Enter input file name (with extension): ");
    scanf("%s", inputFile);

    // Open input file
    FILE *imageFile = fopen(inputFile, "rb");
    if (!imageFile) {
        printf("Error: Input file could not be opened\n");
        exit(1);
    }

    // Get output file name
    char outputFile[100];
    printf("Enter output file name (with extension): ");
    scanf("%s", outputFile);

    // Get operation mode (hide / extract)
    int mode;
    printf("Select operation mode (0 to hide message, 1 to extract message): ");
    scanf("%d", &mode);

    // Perform operation based on mode
    if (mode == 0) {
        // Get secret message to hide
        char secretMessage[MAX_FILE_SIZE];
        printf("Enter secret message to hide in image: ");
        scanf(" %[^\n]s", secretMessage);

        // Open output file
        FILE *outputFile = fopen(outputFile, "wb");
        if (!outputFile) {
            fclose(imageFile);
            printf("Error: Output file could not be opened\n");
            exit(1);
        }

        // Hide secret message in image
        hideSecretMessageInImage(imageFile, outputFile, secretMessage);

        // Close files
        fclose(imageFile);
        fclose(outputFile);

        // Print success message
        printf("Secret message successfully hidden in image\n");
    } else if (mode == 1) {
        // Open output file
        FILE *outputFile = fopen(outputFile, "w");
        if (!outputFile) {
            fclose(imageFile);
            printf("Error: Output file could not be opened\n");
            exit(1);
        }

        // Extract secret message from image
        char secretMessage[MAX_FILE_SIZE];
        extractSecretMessageFromImage(imageFile, secretMessage);

        // Write secret message to file
        fprintf(outputFile, "%s", secretMessage);

        // Close files
        fclose(imageFile);
        fclose(outputFile);

        // Print success message
        printf("Secret message successfully extracted from image\n");
    } else {
        // Close file and print error message
        fclose(imageFile);
        printf("Error: Invalid mode selected\n");
        exit(1);
    }

    return 0;
}