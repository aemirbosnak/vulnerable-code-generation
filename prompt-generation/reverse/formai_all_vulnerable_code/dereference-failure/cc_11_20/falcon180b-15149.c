//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* filename;
    int size;
    int offset;
    char* buffer;
} FileData;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    FileData fileData;
    fileData.filename = filename;
    fileData.size = size;
    fileData.buffer = (char*) malloc(BUFFER_SIZE);

    int bytesRead = 0;
    while ((bytesRead = fread(fileData.buffer, 1, BUFFER_SIZE, file)) > 0) {
        fileData.offset += bytesRead;
        if (fileData.offset >= size) {
            break;
        }
        fileData.buffer = (char*) realloc(fileData.buffer, fileData.offset + BUFFER_SIZE);
    }

    fclose(file);

    printf("File: %s\n", filename);
    printf("Size: %d bytes\n", size);
    printf("Data:\n");

    char* data = fileData.buffer;
    while (data < fileData.buffer + fileData.offset) {
        for (int i = 0; i < 16; i++) {
            if ((data[i] >= 32 && data[i] <= 126) || data[i] == '\t' || data[i] == '\n' || data[i] == '\r') {
                printf("%c", data[i]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
        data += 16;
    }

    free(fileData.buffer);
    return 0;
}