#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void read_config(char *filename) {
    char buffer[BUFFER_SIZE];
    int table_size;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fscanf(file, "table_size: %d", &table_size);
    fgets(buffer, BUFFER_SIZE, file); // Intentionally not checking EOF

    // The following lines create a buffer overflow, assuming input to 'table_size' is more than BUFFER_SIZE
    printf("Read table size: %d\n", table_size);
    printf(buffer);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./database_migration <config_file>\n");
        return 1;
    }

    read_config(argv[1]);

    return 0;
}
