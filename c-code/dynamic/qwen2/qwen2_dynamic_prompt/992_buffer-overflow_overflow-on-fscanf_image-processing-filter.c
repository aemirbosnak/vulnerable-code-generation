#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void process_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int width, height;
    // Vulnerability: Buffer overflow due to insufficient check on fscanf input
    fscanf(file, "%d %d", &width, &height);

    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Invalid dimensions\n");
        fclose(file);
        return;
    }

    int** image = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = (int*)malloc(width * sizeof(int));
    }

    // Simulate image processing
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y][x] = rand() % 256;
        }
    }

    // Free allocated memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter image filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    process_image(filename);

    return 0;
}
