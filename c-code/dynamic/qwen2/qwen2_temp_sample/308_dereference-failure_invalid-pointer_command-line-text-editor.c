#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit(char *buffer) {
    printf("Editing...\n");
    // Simulate invalid pointer dereference by accessing an unallocated memory
    buffer[100] = 'A';
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *buffer = NULL;

    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    buffer = malloc(size + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    fclose(file);

    edit(buffer); // This line will cause a segmentation fault

    free(buffer);

    printf("Edits saved.\n");

    return 0;
}
