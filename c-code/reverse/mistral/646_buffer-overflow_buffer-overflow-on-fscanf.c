#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 255
#define MAX_DIM 1000

int main() {
    FILE *file;
    int width, height;
    char filename[MAX_DIM];
    char *image;

    if (scanf("%s", filename) != 1 || (file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fscanf(file, "%d %d", &width, &height) != 2 || width > MAX_DIM || height > MAX_DIM) {
        fprintf(stderr, "Invalid image dimensions\n");
        fclose(file);
        return 1;
    }

    image = malloc(width * height);
    if (image == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 1;
    }

    size_t read;
    if (fread(image, 1, width * height, file) != width * height) {
        perror("Error reading file");
        free(image);
        fclose(file);
        return 1;
    }

    fclose(file);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (image[y * width + x] < 128)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }

    free(image);
    return 0;
}
