#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void compress_data(char *input_file, char *output_file) {
    FILE *in = fopen(input_file, "r");
    if (!in) {
        printf("Error opening input file\n");
        return;
    }

    FILE *out = fopen(output_file, "w");
    if (!out) {
        printf("Error opening output file\n");
        fclose(in);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fscanf(in, "%s", buffer) != EOF) {
        fprintf(out, "%s ", buffer);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    compress_data(argv[1], argv[2]);

    return 0;
}
