//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of input file

// Function to calculate the checksum of a buffer
unsigned short calculateChecksum(unsigned char* buffer, int size) {
    unsigned short checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

// Function to read a file into a buffer
void readFile(char* filename, unsigned char* buffer) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    if (size > MAX_SIZE) {
        printf("Error: file '%s' is too large.\n", filename);
        exit(1);
    }
    fread(buffer, size, 1, file);
    fclose(file);
}

// Function to write a buffer to a file
void writeFile(char* filename, unsigned char* buffer, int size) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        exit(1);
    }
    fwrite(buffer, size, 1, file);
    fclose(file);
}

// Function to print the checksum as a hexadecimal string
void printChecksum(unsigned short checksum) {
    printf("Checksum: %04X\n", checksum);
}

int main() {
    char inputFile[256];
    char outputFile[256];

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    // Read input file into buffer
    unsigned char buffer[MAX_SIZE];
    readFile(inputFile, buffer);

    // Calculate checksum of buffer
    unsigned short checksum = calculateChecksum(buffer, strlen((char*)buffer));

    // Write buffer and checksum to output file
    unsigned char outputBuffer[MAX_SIZE + 2]; // +2 for checksum
    strcpy((char*)outputBuffer, (char*)buffer);
    sprintf((char*)outputBuffer + strlen((char*)buffer), "%04X", checksum);
    writeFile(outputFile, outputBuffer, strlen((char*)outputBuffer));

    return 0;
}