//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum file size
#define BLOCK_SIZE 1024 // Size of each block

typedef struct {
    char filename[MAX_SIZE];
    FILE *fp;
    char buffer[BLOCK_SIZE];
    int size;
    int checksum;
} file_t;

int main() {
    file_t file;

    // Open the file for reading
    printf("Enter the filename: ");
    scanf("%s", file.filename);
    file.fp = fopen(file.filename, "rb");
    if (file.fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Calculate the file size
    fseek(file.fp, 0, SEEK_END);
    file.size = ftell(file.fp);
    fseek(file.fp, 0, SEEK_SET);

    // Calculate the checksum
    file.checksum = 0;
    while (fread(file.buffer, BLOCK_SIZE, 1, file.fp) == 1) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            file.checksum += file.buffer[i];
        }
    }
    if (fread(file.buffer, BLOCK_SIZE, 1, file.fp)!= 1) {
        printf("Error: File is too large.\n");
        return 1;
    }

    // Print the results
    printf("Filename: %s\n", file.filename);
    printf("File size: %d bytes\n", file.size);
    printf("Checksum: %d\n", file.checksum);

    fclose(file.fp);
    return 0;
}