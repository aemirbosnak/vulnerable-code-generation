//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

struct pixel {
    char character;
    int red;
    int green;
    int blue;
};

void print_image(struct pixel image[MAX_HEIGHT][MAX_WIDTH]) {
    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            printf("%c", image[y][x].character);
        }
        printf("\n");
    }
}

void load_image(struct pixel image[MAX_HEIGHT][MAX_WIDTH], const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 54, SEEK_SET); // Skip header
    int width = fgetc(file) * 256 + fgetc(file);
    int height = fgetc(file) * 256 + fgetc(file);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions are too large.\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&image[y][x], sizeof(struct pixel), 1, file);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        exit(1);
    }

    struct pixel image[MAX_HEIGHT][MAX_WIDTH];
    load_image(image, argv[1]);

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", argv[2]);
        exit(1);
    }

    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            fprintf(output_file, "%c", image[y][x].character);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    return 0;
}