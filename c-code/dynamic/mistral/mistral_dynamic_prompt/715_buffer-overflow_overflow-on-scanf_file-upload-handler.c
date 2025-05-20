#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1048576

int main(int argc, char *argv[]) {
    char fileName[BUFFER_SIZE];
    char fileData[MAX_FILE_SIZE];
    FILE *file;

    if (argc != 2) {
        printf("Usage: ./uploader <filename>\n");
        return 1;
    }

    printf("Uploading file: %s\n", argv[1]);

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fgets(fileName, BUFFER_SIZE, stdin);
    printf("File name read from user: %s\n", fileName);

    fread(fileData, 1, MAX_FILE_SIZE, file);
    fclose(file);

    /* Vulnerable scanf call */
    scanf(fileName);

    return 0;
}
