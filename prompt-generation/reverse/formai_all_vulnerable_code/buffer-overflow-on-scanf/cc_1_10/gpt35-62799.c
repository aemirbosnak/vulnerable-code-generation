//FormAI DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing recovered data
typedef struct {
    char name[30];
    int size;
    char *data;
} RecoveryData;

// Function to open file 
FILE* openFile(char* fileName, char* mode) {
    FILE* filePtr = fopen(fileName, mode);
    if (filePtr == NULL) {
        perror("Error opening file!");
        exit(EXIT_FAILURE);
    }
    return filePtr;
}

// Function to read file size
int getFileSize(FILE* filePtr) {
    int size;
    fseek(filePtr, 0, SEEK_END);
    size = ftell(filePtr);
    rewind(filePtr);
    return size;
}

// Function to recover data from file
RecoveryData* recoverData(char* fileName) {
    FILE* filePtr = openFile(fileName, "rb");
    int size = getFileSize(filePtr);
    char* buffer = (char*) malloc(sizeof(char) * size);
    fread(buffer, sizeof(char), size, filePtr);
    fclose(filePtr);

    RecoveryData* data = (RecoveryData*) malloc(sizeof(RecoveryData));
    strcpy(data->name, fileName);
    data->size = size;
    data->data = buffer;
    return data;
}

int main() {
    char fileName[30];
    printf("Please enter file name:");
    scanf("%s", fileName);

    RecoveryData* recoveredData = recoverData(fileName);

    printf("File Name: %s\n", recoveredData->name);
    printf("File Size: %d\n", recoveredData->size);
    printf("File Data: %s\n", recoveredData->data);

    free(recoveredData->data);
    free(recoveredData);

    return 0;
}