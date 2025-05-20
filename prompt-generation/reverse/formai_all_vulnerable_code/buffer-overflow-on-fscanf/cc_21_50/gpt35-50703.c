//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        printf("Usage: image_editor <input-image-path> [output-image-path]\n");
        return 1;
    }

    char* input_path = argv[1];
    char* output_path = argc == 3 ? argv[2] : "output.ppm";

    FILE* input_file = fopen(input_path, "r");
    if (!input_file) {
        printf("Error opening input file '%s': %s\n", input_path, strerror(errno));
        return 1;
    }

    char format[3];
    int width, height, max_color;
    fscanf(input_file, "%s\n%d %d\n%d\n", format, &width, &height, &max_color);

    if (strcmp(format, "P3") != 0 || width > MAX_WIDTH || height > MAX_HEIGHT || max_color != 255) {
        printf("Error: unsupported image format or size\n");
        return 1;
    }

    int pixels[MAX_HEIGHT][MAX_WIDTH][3];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(input_file, "%d %d %d", &pixels[y][x][0], &pixels[y][x][1], &pixels[y][x][2]);
        }
    }

    char operation;
    int arg1, arg2, arg3;
    while (scanf(" %c", &operation) == 1) {
        switch (operation) {
            case 'S':
                printf("Saving to '%s'\n", output_path);
                FILE* output_file = fopen(output_path, "w");
                if (!output_file) {
                    printf("Error opening output file '%s': %s\n", output_path, strerror(errno));
                    return 1;
                }
                fprintf(output_file, "P3\n%d %d\n%d\n", width, height, max_color);
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        fprintf(output_file, "%d %d %d ", pixels[y][x][0], pixels[y][x][1], pixels[y][x][2]);
                    }
                    fprintf(output_file, "\n");
                }
                fclose(output_file);
                break;
            case 'G':
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        int gray = (pixels[y][x][0] + pixels[y][x][1] + pixels[y][x][2]) / 3;
                        pixels[y][x][0] = gray;
                        pixels[y][x][1] = gray;
                        pixels[y][x][2] = gray;
                    }
                }
                break;
            case 'F':
                scanf("%d %d %d", &arg1, &arg2, &arg3);
                for (int y = arg2; y <= arg3; y++) {
                    for (int x = 0; x < width; x++) {
                        pixels[y][x][arg1] = max_color - pixels[y][x][arg1];
                    }
                }
                break;
            default:
                printf("Error: invalid operation '%c'\n", operation);
                break;
        }
    }

    return 0;
}