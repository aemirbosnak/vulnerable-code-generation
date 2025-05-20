#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *fileName = argv[1];

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        // Dereference buffer beyond its bounds
        buffer[BUFFER_SIZE + 1];

        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }

    fclose(file);
    return 0;
}
