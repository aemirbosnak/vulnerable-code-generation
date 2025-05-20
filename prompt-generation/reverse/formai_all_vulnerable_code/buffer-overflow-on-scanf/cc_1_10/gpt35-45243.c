//FormAI DATASET v1.0 Category: Image Editor ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *inFile, *outFile;

    char inFileName[50], outFileName[50];
    printf("Enter the input file name: ");
    scanf("%s", inFileName);

    inFile = fopen(inFileName, "rb");
    if (inFile == NULL) {
        printf("Error opening input file!");
        return 1;
    }

    printf("Enter the output file name: ");
    scanf("%s", outFileName);

    outFile = fopen(outFileName, "wb");
    if (outFile == NULL) {
        printf("Error opening output file!");
        return 1;
    }

    char header[54];
    int i;
    for (i = 0; i < 54; i++) {
        header[i] = getc(inFile);
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    int size = width * height * 3;
    char *data = malloc(size);

    fread(data, sizeof(char), size, inFile);

    // Modify data here

    fwrite(header, sizeof(char), 54, outFile);
    fwrite(data, sizeof(char), size, outFile);

    free(data);
    fclose(inFile);
    fclose(outFile);

    return 0;
}