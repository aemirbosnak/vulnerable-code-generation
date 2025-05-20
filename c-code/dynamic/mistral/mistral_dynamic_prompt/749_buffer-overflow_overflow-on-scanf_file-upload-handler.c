#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char fileName[BUFFER_SIZE];
    char fileContent[16384];

    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    printf("Uploading file...\n");

    if (scanf("%s", fileName) != 1 || strlen(fileName) >= BUFFER_SIZE) {
        printf("Error: File name is too long.\n");
        return 1;
    }

    FILE *file = fopen(fileName, "rb");

    if (!file) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    size_t read = fread(fileContent, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    if (read < BUFFER_SIZE) {
        printf("File uploaded successfully.\n");
    } else {
        printf("Error: File is too large.\n");
    }

    return 0;
}
