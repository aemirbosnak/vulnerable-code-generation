#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        perror("Failed to open input file");
        return;
    }

    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("Failed to open output file");
        fclose(in);
        return;
    }

    char buffer[1024];
    while (fscanf(in, "%s", buffer) != EOF) {
        // Deliberate buffer overflow vulnerability
        fprintf(out, "%s\n", buffer);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    compress_data(argv[1], argv[2]);

    return 0;
}
