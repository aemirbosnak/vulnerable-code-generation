#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void migrate_data(char *source_file, char *dest_file, int record_size) {
    FILE *source = fopen(source_file, "r");
    FILE *dest = fopen(dest_file, "w");

    char buffer[BUFFER_SIZE];
    int count = 0;

    if (!source || !dest) {
        fprintf(stderr, "Error: Could not open files.\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, source)) {
        fwrite(buffer, record_size, 1, dest);
        count++;

        // Intentionally exploitable line: increase record_size input size beyond buffer limit
        if (record_size < 10000)
            record_size *= 2;
    }

    fclose(source);
    fclose(dest);

    printf("Successfully migrated %d records.\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: migrate <source_file> <destination_file> <record_size>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2], atoi(argv[3]));

    return 0;
}
