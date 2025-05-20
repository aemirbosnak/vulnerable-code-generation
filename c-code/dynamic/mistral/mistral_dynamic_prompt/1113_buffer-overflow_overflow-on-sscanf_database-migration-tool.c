#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void migrate_data(char *input_file, char *output_file) {
    FILE *in, *out;
    char buffer[BUFFER_SIZE];
    int id, columns;

    in = fopen(input_file, "r");
    out = fopen(output_file, "w");

    if (in && out) {
        while (fgets(buffer, BUFFER_SIZE, in)) {
            sscanf(buffer, "%d %d %*s %s", &id, &columns, buffer);

            if (id <= 0 || columns < 3)
                continue;

            fprintf(out, "ID: %d, Columns: %d, Data: %s\n", id, columns, buffer);
        }

        fclose(in);
        fclose(out);
    } else {
        printf("Failed to open files.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate input_file output_file\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
