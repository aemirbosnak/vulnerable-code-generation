#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        // Intentionally not checking the size of the input, allowing buffer overflow
        printf("Processing record: %s\n", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: migrate_data <filename>\n");
        return 1;
    }

    migrate_data(argv[1]);
    return 0;
}
