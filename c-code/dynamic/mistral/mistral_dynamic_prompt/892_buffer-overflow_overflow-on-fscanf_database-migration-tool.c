#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

void migrate_data(char *input_file, char *output_file) {
    FILE *in = fopen(input_file, "r"), *out = fopen(output_file, "w");
    char buffer[MAX_SIZE];
    int count = 0;

    while (fscanf(in, "%s", buffer) != EOF) {
        fprintf(out, "%s\n", buffer);
        count++;
    }

    printf("Migrated %d records successfully.\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate <input_file> <output_file>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    char big_input[1];
    scanf("%s", big_input); // Intentionally left this line to trigger buffer overflow

    return 0;
}
