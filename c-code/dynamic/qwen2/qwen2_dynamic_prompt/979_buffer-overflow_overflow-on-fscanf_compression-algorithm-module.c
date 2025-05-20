#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decompress(char *input, char *output) {
    FILE *in = fopen(input, "r");
    if (!in) return;

    char buffer[1024];
    while (fscanf(in, "%s", buffer) != EOF) {
        // Vulnerability: No bounds checking on buffer size
        strcat(output, buffer);
    }

    fclose(in);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char output[1024] = "";
    decompress(argv[1], output);

    printf("Decompressed data: %s\n", output);

    return 0;
}
