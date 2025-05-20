//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from a file and store it in an array
void readData(FILE *file, int *data, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &data[i]);
    }
}

// Function to write data from an array to a file
void writeData(FILE *file, int *data, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        fprintf(file, "%d\n", data[i]);
    }
}

int main() {
    // Open the input file
    FILE *inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read data from the input file
    int size = 100; // Example size, can be changed
    int *data = (int*)malloc(size * sizeof(int));
    readData(inputFile, data, size);
    fclose(inputFile);

    // Open the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write data to the output file
    writeData(outputFile, data, size);
    fclose(outputFile);

    // Free the allocated memory
    free(data);

    return 0;
}