//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

typedef struct {
    char filename[128];
    int size;
    char data[MAX_DATA_SIZE];
} FileData;

int main() {
    FILE *file;
    FileData fileData;
    int fileSize;

    // Ask user for input file name
    printf("Enter input file name: ");
    scanf("%s", fileData.filename);

    // Open input file
    file = fopen(fileData.filename, "rb");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file data
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);
    fread(fileData.data, fileSize, 1, file);
    fclose(file);

    // Ask user for output file name
    printf("Enter output file name: ");
    scanf("%s", fileData.filename);

    // Open output file
    file = fopen(fileData.filename, "wb");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write output file data
    fwrite(fileData.data, fileSize, 1, file);
    fclose(file);

    printf("Data recovery successful!\n");
    return 0;
}