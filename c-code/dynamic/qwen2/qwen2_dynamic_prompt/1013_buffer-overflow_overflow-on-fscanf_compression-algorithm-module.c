#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        printf("Error opening input file\n");
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        fclose(in);
        printf("Error opening output file\n");
        return;
    }

    char buffer[1024];
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

    compress(argv[1], argv[2]);

    return 0;
}
