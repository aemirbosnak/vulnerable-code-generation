#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_LENGTH];
    size_t read_size;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((read_size = fread(buffer, sizeof(char), MAX_LENGTH, file)) > 0) {
        printf("Received data: %.*s\n", (int)read_size, buffer);

        // Out-of-bounds read vulnerability here
        printf("%c", buffer[MAX_LENGTH]);
    }

    fclose(file);
    return 0;
}
