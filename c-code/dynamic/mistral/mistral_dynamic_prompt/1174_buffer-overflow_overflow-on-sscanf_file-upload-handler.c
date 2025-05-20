#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_NAME_LENGTH 256

void process_file(char *buffer) {
    char fileName[MAX_FILE_NAME_LENGTH];
    char *pFile;
    FILE *file;

    sscanf(buffer, "%s %s", fileName, pFile);
    file = fopen(fileName, "rb");

    char bufferToRead[BUFFER_SIZE];
    while (fread(bufferToRead, sizeof(char), BUFFER_SIZE, file)) {
        // process bufferToRead here
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    process_file(input);

    return 0;
}
