#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 65536

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char fileName[256];
    FILE *file;
    long fileSize;

    printf("Upload a file: \n");

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    fileSize = strlen(buffer);

    if (fileSize > MAX_FILE_SIZE) {
        printf("File too large.\n");
        return 1;
    }

    sscanf(buffer, "%s", fileName);

    file = fopen(fileName, "wb");

    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return 1;
    }

    fwrite(buffer, 1, fileSize, file);
    fclose(file);

    printf("File uploaded: %s\n", fileName);
    return 0;
}
