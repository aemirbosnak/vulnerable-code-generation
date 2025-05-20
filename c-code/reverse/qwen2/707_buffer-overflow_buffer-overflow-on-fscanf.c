#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int label;
} ImageData;

void load_dataset(const char* filepath, ImageData* dataset, int* size) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open dataset file");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%s %d", dataset[*size].filename, &dataset[*size].label) != EOF) {
        (*size)++;
    }

    fclose(file);
}

void train_model(ImageData* dataset, int size) {
    // Placeholder for training logic
    printf("Training model with %d images...\n", size);
}

void test_model(ImageData* dataset, int size) {
    // Placeholder for testing logic
    printf("Testing model with %d images...\n", size);
}

int main() {
    const char* dataset_filepath = "images.txt";
    ImageData dataset[1000]; // Adjust size as needed
    int dataset_size;

    load_dataset(dataset_filepath, dataset, &dataset_size);

    train_model(dataset, dataset_size);
    test_model(dataset, dataset_size);

    return 0;
}
