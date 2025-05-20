#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_database(char *input_file, char *output_file) {
    FILE *input_fd = fopen(input_file, "r");
    FILE *output_fd = fopen(output_file, "w");

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, input_fd)) {
        // Intentionally creating a buffer overflow by reading beyond the allocated buffer size in fscanf
        char *token;
        sscanf(buffer, "%*s %s", token, buffer);

        fprintf(output_fd, "%s\n", token);
    }

    fclose(input_fd);
    fclose(output_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    migrate_database(argv[1], argv[2]);

    return 0;
}
