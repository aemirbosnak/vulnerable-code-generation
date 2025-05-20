//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_WATERMARK_SIZE 100

// Function to embed watermark into the file using Least Significant Bit (LSB) technique
void embedWatermark(char* inputFile, char* outputFile, char* watermark) {
    FILE *inFile, *outFile;
    char watermarkBit[MAX_WATERMARK_SIZE], c;
    int watermarkIndex = 0;

    // Open the input file
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // Open the output file
    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        printf("Error: Unable to create output file\n");
        exit(1);
    }

    // Copy the header information from input file to output file
    while ((c = fgetc(inFile)) != '@') {
        fputc(c, outFile);
    }
    fputc('@', outFile);

    // Embed the watermark bits into each byte of data
    while ((c = fgetc(inFile)) != EOF) {
        // Get the next bit of watermark
        sprintf(watermarkBit, "%d", watermark[watermarkIndex++ % strlen(watermark)] - '0');

        // Modify the least significant bit of data byte with the watermark bit
        if (watermarkBit[0] == '1') {
            c |= 0x01;
        } else {
            c &= 0xFE;
        }

        fputc(c, outFile);
    }

    // Close the files
    fclose(inFile);
    fclose(outFile);

    printf("Watermark has been embedded successfully!\n");
}

// Function to extract watermark from the file using LSB technique
void extractWatermark(char* inputFile) {
    FILE *inFile;
    char watermarkBit[MAX_WATERMARK_SIZE], c;
    int watermarkIndex = 0, count = 0;

    // Open the input file
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // Search for the watermark in each byte of data
    while ((c = fgetc(inFile)) != EOF) {
        count++;
        // Ignore header information
        if (c == '@') {
            continue;
        }
        // Extract the least significant bit of data byte
        if (count % 8 == 0) { // Skip the parity bit
            sprintf(watermarkBit + watermarkIndex, "%d", (c & 0x01));
            watermarkIndex++;
        }
        if (watermarkIndex == MAX_WATERMARK_SIZE - 1) {
            break;
        }
    }

    // Close the file
    fclose(inFile);

    printf("Extracted Watermark: %s\n", watermarkBit);
}

int main() {
    char inputFile[MAX_FILE_NAME_SIZE], outputFile[MAX_FILE_NAME_SIZE], watermark[MAX_WATERMARK_SIZE];

    // Get the input file name
    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    // Get the output file name
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    // Get the watermark to be embedded
    printf("Enter the watermark to be embedded (0s and 1s only): ");
    scanf("%s", watermark);

    // Embed the watermark into the file
    embedWatermark(inputFile, outputFile, watermark);

    // Extract the watermark from the file
    extractWatermark(outputFile);

    return 0;
}