//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Function to calculate the size of file
int getFileSize(FILE* file) {
    int size = 0;

    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        rewind(file);
    }

    return size;
}

// Function to read the data from file
int* readData(FILE* file, int size) {
    int* data = (int*) malloc(size * sizeof(int));

    if (file != NULL && data != NULL) {
        for (int i = 0; i < size; i++) {
            fscanf(file, "%d", &data[i]);
        }
    }

    return data;
}

// Function to write the data to file
void writeData(FILE* file, int* data, int size) {
    if (file != NULL && data != NULL) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%d ", data[i]);
        }
    }
}

// Function to embed the watermark
void embedWatermark(int* data, int size, int watermark[], int watermarkSize) {
    int delta = size / watermarkSize;

    for (int i = 0; i < watermarkSize; i++) {
        int index = i * delta;
        data[index] = watermark[i];
    }
}

// Function to extract the watermark
void extractWatermark(int* data, int size, int watermark[], int watermarkSize) {
    int delta = size / watermarkSize;

    for (int i = 0; i < watermarkSize; i++) {
        int index = i * delta;
        watermark[i] = data[index];
    }
}

int main() {
    FILE* inputFile;
    FILE* outputFile;
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";
    int watermark[] = {1, 0, 1, 0, 1};
    int watermarkSize = sizeof(watermark) / sizeof(watermark[0]);

    // Open the input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open the file %s.\n", inputFileName);
        return 1;
    }

    // Get the file size
    int size = getFileSize(inputFile);

    // Allocate memory to store the data
    int* data = readData(inputFile, size);

    // Close the input file
    fclose(inputFile);

    // Embed the watermark
    embedWatermark(data, size, watermark, watermarkSize);

    // Open the output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open the file %s.\n", outputFileName);
        return 1;
    }

    // Write the data to the output file
    writeData(outputFile, data, size);

    // Close the output file
    fclose(outputFile);

    // Extract the watermark
    int extractedWatermark[watermarkSize];
    extractWatermark(data, size, extractedWatermark, watermarkSize);

    // Print the extracted watermark
    printf("Extracted Watermark: ");
    for (int i = 0; i < watermarkSize; i++) {
        printf("%d ", extractedWatermark[i]);
    }
    printf("\n");

    // Free the memory
    free(data);

    return 0;
}