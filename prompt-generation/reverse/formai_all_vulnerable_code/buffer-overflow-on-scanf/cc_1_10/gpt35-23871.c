//FormAI DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum file size to recover

void parseFile(FILE *fp);
char* getFileExtension(char *filename);

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the filename including the extension: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Failed to open the file.\n");
        exit(0);
    }

    parseFile(fp);

    fclose(fp);
    return 0;
}

void parseFile(FILE *fp) {
    char filename[MAX_SIZE];
    int fileSize;
    unsigned char buffer[MAX_SIZE];
    FILE *newFile;

    printf("Enter the new filename for the recovered file: ");
    scanf("%s", filename);

    fileSize = fread(buffer, sizeof(unsigned char), MAX_SIZE, fp);
    printf("File size is: %d bytes\n", fileSize);

    char *extension = getFileExtension(filename);
    if(extension == NULL) {
        printf("Failed to recover file. Invalid file extension.\n");
        return;
    }

    newFile = fopen(filename, "wb");
    fwrite(buffer, sizeof(unsigned char), fileSize, newFile);
    printf("Successfully recovered the file!\n");

    fclose(newFile);
}

char* getFileExtension(char *filename) {
    char *dot = strrchr(filename, '.');
    if(dot == NULL || dot == filename) {
        return NULL;
    }
    return dot + 1;
}