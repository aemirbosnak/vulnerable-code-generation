#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(char *input_image, char *output_image, int width, int height) {
    FILE *in_file = fopen(input_image, "r");
    FILE *out_file = fopen(output_image, "w");

    if (!in_file || !out_file) {
        printf("Error opening files\n");
        return;
    }

    fprintf(out_file, "%d %d\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r, g, b;
            fscanf(in_file, "%hhu %hhu %hhu", &r, &g, &b);
            unsigned char new_r = r + 10;
            unsigned char new_g = g + 10;
            unsigned char new_b = b + 10;
            fprintf(out_file, "%hhu %hhu %hhu ", new_r, new_g, new_b);
        }
        fprintf(out_file, "\n");
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    char input_image[MAX_IMAGE_SIZE];
    char output_image[MAX_IMAGE_SIZE];

    // Intentional buffer overflow vulnerability
    sscanf(argv[1], "%s%*[^ ]", input_image); // Overflow here
    sscanf(argv[2], "%s%*[^ ]", output_image); // Overflow here

    int width, height;
    printf("Enter image dimensions (width height): ");
    scanf("%d %d", &width, &height);

    apply_filter(input_image, output_image, width, height);

    return 0;
}
