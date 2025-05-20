//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASS_NUM 5

typedef struct ImageData {
    char **pixels;
    int width;
    int height;
    int label;
} ImageData;

ImageData **loadData(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read image width and height
    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    // Allocate memory for image data
    ImageData *data = malloc(sizeof(ImageData));
    data->pixels = malloc(height * width * sizeof(char *));
    data->width = width;
    data->height = height;
    data->label = -1;

    // Read image pixels
    for (int h = 0; h < height; h++) {
        data->pixels[h] = malloc(width * sizeof(char));
        for (int w = 0; w < width; w++) {
            fscanf(fp, "%c ", &data->pixels[h][w]);
        }
    }

    fclose(fp);

    return data;
}

int main() {
    // Load image data
    ImageData *data = loadData("image.txt");

    // Print image pixels
    for (int h = 0; h < data->height; h++) {
        for (int w = 0; w < data->width; w++) {
            printf("%c ", data->pixels[h][w]);
        }
        printf("\n");
    }

    // Print image label
    printf("Label: %d\n", data->label);

    // Free memory
    free(data->pixels);
    free(data);

    return 0;
}