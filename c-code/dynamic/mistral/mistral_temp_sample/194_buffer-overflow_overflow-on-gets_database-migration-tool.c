#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *input_file, char *output_file) {
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    if (!input_fp || !output_fp) {
        printf("Error: Could not open files.\n");
        return;
    }

    printf("Reading input file...\n");
    while (fgets(input_buffer, BUFFER_SIZE, input_fp)) {
        strcpy(output_buffer, input_buffer);
        // Intentionally creating a buffer overflow by writing more characters than the buffer can hold
        strcat(output_buffer, "Extra data beyond buffer size\n");
        fputs(output_buffer, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("Migration completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: db_migration <input_file> <output_file>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);
    return 0;
}
