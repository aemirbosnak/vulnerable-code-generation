#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

typedef struct {
    char name[BUFFER_SIZE];
    char address[BUFFER_SIZE];
} Record;

void migrate_database(FILE *input, FILE *output) {
    Record record;
    int count = 0;

    while (sscanf(input, "%s%s", record.name, record.address) == 2) {
        fprintf(output, "%s\t%s\n", record.name, record.address);
        count++;
    }

    printf("Migrated %d records\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    migrate_database(input, output);
    fclose(input);
    fclose(output);

    return 0;
}
