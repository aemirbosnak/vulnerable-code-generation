#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(char *input, char *output) {
    FILE *in = fopen(input, "r");
    if (!in) {
        printf("Error opening input file\n");
        return;
    }

    int width, height;
    fscanf(in, "%d %d", &width, &height);
    int pixels[width][height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(in, "%d", &pixels[x][y]);
        }
    }

    fclose(in);

    FILE *out = fopen(output, "w");
    if (!out) {
        printf("Error opening output file\n");
        return;
    }

    fprintf(out, "%d %d\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(out, "%d ", pixels[x][y] + 10); // Overflow here
        }
        fprintf(out, "\n");
    }

    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    apply_filter(argv[1], argv[2]);

    return 0;
}
