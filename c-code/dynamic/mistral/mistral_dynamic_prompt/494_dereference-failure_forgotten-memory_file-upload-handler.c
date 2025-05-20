#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Error: Failed to allocate memory for buffer\n");
        fclose(file);
        return;
    }

    size_t read = fread(buffer, size, 1, file);
    if (read != 1) {
        fprintf(stderr, "Error: Failed to read file\n");
        free(buffer);
        fclose(file);
        return;
    }

    printf("File contents:\n%s\n", buffer);
    free(buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    readFile(argv[1]);

    return 0;
}
