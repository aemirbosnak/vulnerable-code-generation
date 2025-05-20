#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void process_image(char* input_file, char* output_file, int width, int height, int* rgb) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    char buffer[MAX_SIZE];
    int x, y;

    fscanf(input, "%d %d\n", &width, &height);
    printf("Read input dimensions: %d x %d\n", width, height);

    for (y = 0; y < height; y++) {
        for (x = 0; x < width * 3; x += 3) {
            fscanf(input, "%hhu%hhu%hhu", &rgb[x], &rgb[x+1], &rgb[x+2]);
            fprintf(output, "%hhu%hhu%hhu", rgb[x], rgb[x+1], rgb[x+2]);
        }
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    int* rgb = malloc(width * height * 3);

    process_image(argv[1], argv[2], width, height, rgb);

    free(rgb);
    return 0;
}
