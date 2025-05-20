//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASS_NUM 10

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
    ImageData **data = malloc(sizeof(ImageData *) * MAX_CLASS_NUM);
    for (int i = 0; i < MAX_CLASS_NUM; i++) {
        data[i] = malloc(sizeof(ImageData));
    }

    // Read image pixels
    for (int i = 0; i < MAX_CLASS_NUM; i++) {
        data[i]->pixels = malloc(sizeof(char *) * height);
        for (int j = 0; j < height; j++) {
            data[i]->pixels[j] = malloc(sizeof(char) * width);
            fscanf(fp, "%c ", data[i]->pixels[j]);
        }
    }

    // Read image label
    fscanf(fp, "%d", &data[0]->label);

    fclose(fp);
    return data;
}

int main() {
    // Load image data
    ImageData **data = loadData("image.txt");

    // Print image label
    printf("Label: %d\n", data[0]->label);

    // Free memory
    for (int i = 0; i < MAX_CLASS_NUM; i++) {
        free(data[i]->pixels);
        free(data[i]);
    }
    free(data);

    return 0;
}