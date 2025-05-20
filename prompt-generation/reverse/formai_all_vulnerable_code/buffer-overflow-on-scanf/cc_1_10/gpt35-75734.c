//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr;
    char fileName[20], data[100];

    printf("Enter the name of the file you wish to create: ");
    scanf("%s", fileName);

    // Create a new file
    filePtr = fopen(fileName, "w");

    // Check if file was created successfully
    if (filePtr == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter some text to write to the file (max 100 characters): ");
    scanf(" %[^\n]", data);

    // Write data to file
    fputs(data, filePtr);

    printf("File created and data written successfully.\n");

    // Close the file
    fclose(filePtr);

    // Open the file in read mode
    filePtr = fopen(fileName, "r");

    // Check if file was opened successfully
    if (filePtr == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    // Read data from file and print to console
    printf("Data in file: ");
    while (fgets(data, sizeof(data), filePtr) != NULL) {
        printf("%s", data);
    }

    // Close the file
    fclose(filePtr);

    return 0;
}