#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1MB
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char filename[256];
    long fileSize;

    if (argc != 3) {
        printf("Usage: %s <file_to_upload> <filename_to_save_as>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (!file) {
        perror("Error opening file to upload.");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);

    if (fileSize > MAX_FILE_SIZE) {
        printf("File too large, maximum allowed size is %ld bytes.\n", MAX_FILE_SIZE);
        fclose(file);
        return 1;
    }

    rewind(file);

    file = fopen(argv[2], "wb");
    while (!feof(file)) {
        memset(buffer, 0, BUFFER_SIZE);
        size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        fwrite(buffer, sizeof(char), bytesRead, file);
    }

    fclose(file);

    printf("File uploaded successfully.\n");
    return 0;
}
