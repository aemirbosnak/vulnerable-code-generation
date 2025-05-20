//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a watermark to a file
void addWatermark(char* fileName, char* watermark) {
    FILE *file;
    file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    int watermarkLength = strlen(watermark);
    int fileLength = 0;
    char* fileContent = NULL;
    char* newContent = NULL;
    int newContentLength = 0;
    int i;

    // Get the length of the file content
    fileLength = ftell(file);
    rewind(file);

    // Allocate memory for file content
    fileContent = (char*)malloc(fileLength + 1);
    if (fileContent == NULL) {
        printf("Error allocating memory\n");
        return;
    }

    // Read the file content
    fread(fileContent, fileLength, 1, file);

    // Add the watermark to the file content
    newContent = (char*)malloc(fileLength + watermarkLength + 1);
    if (newContent == NULL) {
        printf("Error allocating memory\n");
        return;
    }
    for (i = 0; i < fileLength; i++) {
        newContent[i] = fileContent[i];
        if (i >= watermarkLength) {
            newContent[i] = watermark[i - watermarkLength];
        }
    }
    newContent[fileLength] = '\0';

    // Write the new content to the file
    fseek(file, 0, SEEK_SET);
    fwrite(newContent, fileLength + watermarkLength, 1, file);
    fclose(file);
}

int main() {
    char* fileName = "sample.txt";
    char* watermark = "SherlockHolmes";
    addWatermark(fileName, watermark);
    printf("Watermark added successfully\n");
    return 0;
}