#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION 1000

void convertToAscii(char *imageData, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", imageData[y * width + x]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file;
    char filename[256];
    int width, height;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (fscanf(file, "%d %d", &width, &height) != 2) {
        fprintf(stderr, "Invalid file format\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (width <= 0 || height <= 0 || width > MAX_DIMENSION || height > MAX_DIMENSION) {
        fprintf(stderr, "Invalid dimensions\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    char *imageData = malloc(width * height * sizeof(char));
    if (!imageData) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (fread(imageData, sizeof(char), width * height, file) != width * height) {
        fprintf(stderr, "Failed to read image data\n");
        free(imageData);
        fclose(file);
        return EXIT_FAILURE;
    }

    fclose(file);

    convertToAscii(imageData, width, height);

    free(imageData);
    return EXIT_SUCCESS;
}
