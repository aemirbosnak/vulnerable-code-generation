//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void grayscale(char* filename) {
    FILE* fp = fopen(filename, "rb+");
    unsigned char header[54], colorTable[1024];

    if (fp == NULL) {
        printf("\nError: File cannot be opened.");
        exit(0);
    }

    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    if (bitDepth <= 8) {
        fread(colorTable, sizeof(unsigned char), 1024, fp);
    }

    int size = width * height;
    unsigned char buffer[size][3];
    fread(buffer, sizeof(unsigned char), size * 3, fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int grayscale = 0.299 * buffer[i][j * 3] + 0.587 * buffer[i][j * 3 + 1] + 0.114 * buffer[i][j * 3 + 2];
            buffer[i][j * 3] = grayscale;
            buffer[i][j * 3 + 1] = grayscale;
            buffer[i][j * 3 + 2] = grayscale;
        }
    }

    fseek(fp, 0L, SEEK_SET);
    fwrite(header, sizeof(unsigned char), 54, fp);

    if (bitDepth <= 8) {
        fwrite(colorTable, sizeof(unsigned char), 1024, fp);
    }

    fwrite(buffer, sizeof(unsigned char), size * 3, fp);
    fclose(fp);
}

void flip(char* filename) {
    FILE* fp = fopen(filename, "rb+");
    unsigned char header[54], colorTable[1024];

    if (fp == NULL) {
        printf("\nError: File cannot be opened.");
        exit(0);
    }

    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    if (bitDepth <= 8) {
        fread(colorTable, sizeof(unsigned char), 1024, fp);
    }

    int rowSize = ((bitDepth * width + 31) / 32) * 4;
    unsigned char buffer[rowSize];
    int offset = rowSize * (height - 1);

    for (int i = 0; i < height / 2; i++) {
        fseek(fp, i * rowSize, SEEK_CUR);
        fread(buffer, sizeof(unsigned char), rowSize, fp);

        fseek(fp, offset - i * rowSize, SEEK_CUR);
        fread(colorTable, sizeof(unsigned char), rowSize, fp);

        fseek(fp, i * rowSize, SEEK_CUR);
        fwrite(colorTable, sizeof(unsigned char), rowSize, fp);

        fseek(fp, offset - i * rowSize, SEEK_CUR);
        fwrite(buffer, sizeof(unsigned char), rowSize, fp);
    }

    fclose(fp);
}

int main() {
    char filename[] = "image.bmp";

    printf("Welcome to the Image Editor!\n");
    printf("1. Convert to grayscale.\n");
    printf("2. Flip vertically.\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            grayscale(filename);
            printf("Grayscale conversion completed successfully!\n");
            break;
        case 2:
            flip(filename);
            printf("Vertical flip completed successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}