//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a digital watermark
void createWatermark(char* inputFile, char* outputFile, char* watermark) {
    FILE *fp = fopen(inputFile, "rb");
    FILE *fw = fopen(outputFile, "wb");

    // Read the input file
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Read the watermark
    int watermarkLength = strlen(watermark);

    // Find the location to insert the watermark
    long watermarkOffset = (size * 100) / watermarkLength;

    // Write the watermark to the output file
    fseek(fp, watermarkOffset, SEEK_SET);
    fwrite(watermark, 1, watermarkLength, fw);

    // Write the rest of the input file to the output file
    fseek(fp, 0, SEEK_SET);
    fwrite(fp, 1, size, fw);

    // Close the files
    fclose(fp);
    fclose(fw);
}

int main() {
    char inputFile[100];
    char outputFile[100];
    char watermark[100];

    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    printf("Enter the watermark: ");
    scanf("%s", watermark);

    createWatermark(inputFile, outputFile, watermark);

    printf("Digital watermarking completed successfully!\n");

    return 0;
}