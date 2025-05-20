#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *input_file, char *output_file) {
    char buffer[BUFFER_SIZE];
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        printf("Error: Unable to open files.\n");
        return;
    }

    printf("Migrating data from %s to %s...\n", input_file, output_file);

    while (fgets(buffer, BUFFER_SIZE, input)) {
        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);

    printf("Data migration complete.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate <input_file> <output_file>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
