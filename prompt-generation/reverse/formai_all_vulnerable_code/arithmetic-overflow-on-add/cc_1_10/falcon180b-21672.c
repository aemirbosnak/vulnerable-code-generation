//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    int filesize;
    char *buffer;
} FileData;

int main() {
    char *filename = "example.txt";
    int filesize = 0;
    char *buffer = NULL;

    // Read the file into memory
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    buffer = (char *) malloc(filesize + 1);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        exit(1);
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    // Search for a specific string in the file
    char *searchString = "Sherlock Holmes";
    int searchStringLength = strlen(searchString);
    char *foundString = NULL;
    int foundStringLength = 0;
    int offset = 0;

    while (offset < filesize - searchStringLength) {
        if (strncmp(buffer + offset, searchString, searchStringLength) == 0) {
            foundString = buffer + offset;
            foundStringLength = strlen(foundString);
            break;
        }
        offset++;
    }

    // Print the results
    if (foundString == NULL) {
        printf("String not found in file\n");
    } else {
        printf("String found at offset %d:\n%s\n", offset, foundString);
    }

    // Free the memory
    free(buffer);
    return 0;
}