#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void migrate_data(const char* input_file, const char* output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        fprintf(stderr, "Failed to open input file\n");
        return;
    }

    FILE *out = fopen(output_file, "w");
    if (!out) {
        fprintf(stderr, "Failed to open output file\n");
        fclose(in);
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fscanf(in, "%s", buffer) != EOF) {
        // Intentional buffer overflow vulnerability
        fprintf(out, "%s\n", buffer);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
