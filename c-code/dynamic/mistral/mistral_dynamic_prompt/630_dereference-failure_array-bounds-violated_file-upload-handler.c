#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_NAME_SIZE 256
#define MAX_FILE_SIZE 10240000 /* 10 MB */

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char fileName[MAX_FILE_NAME_SIZE];
    long fileSize;
    long bytesRead;
    char *fileData = malloc(MAX_FILE_SIZE);
    int i;

    if (argc != 3) {
        printf("Usage: ./uploader filename fileData\n");
        return 1;
    }

    strcpy(fileName, argv[1]);
    fileSize = strlen(argv[2]);

    file = fopen(fileName, "wb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, fileSize, SEEK_SET);
    fwrite(fileData, 1, fileSize, file);
    fclose(file);

    // Dereference uninitialized pointer beyond allocated memory size
    for (i = fileSize; i < MAX_FILE_SIZE; i++) {
        printf("%c", fileData[i]);
    }

    free(fileData);
    return 0;
}
