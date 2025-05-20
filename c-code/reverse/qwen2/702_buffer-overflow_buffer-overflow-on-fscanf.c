#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void trainModel(const char* imagesFile, const char* labelsFile) {
    FILE *images = fopen(imagesFile, "r");
    FILE *labels = fopen(labelsFile, "r");

    if (!images || !labels) {
        printf("Error opening files.\n");
        return;
    }

    int numImages, numLabels;
    fscanf(images, "%d", &numImages);
    fscanf(labels, "%d", &numLabels);

    if (numImages != numLabels) {
        printf("Mismatch in number of images and labels.\n");
        fclose(images);
        fclose(labels);
        return;
    }

    // Simulate training process
    for (int i = 0; i < numImages; ++i) {
        int label;
        fscanf(labels, "%d", &label);
        // Dummy processing
        printf("Training image %d with label %d\n", i, label);
    }

    fclose(images);
    fclose(labels);
}

int main() {
    char imagesFilename[MAX_FILENAME_LENGTH];
    char labelsFilename[MAX_FILENAME_LENGTH];

    printf("Enter the path to the images file: ");
    scanf("%s", imagesFilename); // Vulnerable to buffer overflow

    printf("Enter the path to the labels file: ");
    scanf("%s", labelsFilename); // Vulnerable to buffer overflow

    trainModel(imagesFilename, labelsFilename);

    return 0;
}
