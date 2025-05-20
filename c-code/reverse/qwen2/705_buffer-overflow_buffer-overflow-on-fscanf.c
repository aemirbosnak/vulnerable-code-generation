#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGES 1000
#define IMAGE_SIZE 28 * 28

typedef struct {
    int label;
    float pixels[IMAGE_SIZE];
} Image;

void load_images(const char* filename, Image images[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%d", &images[*count].label) != EOF) {
        for (int i = 0; i < IMAGE_SIZE; ++i) {
            fscanf(file, "%f", &images[*count].pixels[i]);
        }
        (*count)++;
    }
    fclose(file);
}

void train_classifier(Image training_data[], int count) {
    // Placeholder for actual training logic
    printf("Training classifier with %d images...\n", count);
}

void test_classifier(Image testing_data[], int count) {
    // Placeholder for actual testing logic
    printf("Testing classifier with %d images...\n", count);
}

int main() {
    Image training_data[MAX_IMAGES], testing_data[MAX_IMAGES];
    int training_count = 0, testing_count = 0;

    printf("Enter path to training data file: ");
    char training_filename[256];
    scanf("%s", training_filename);
    load_images(training_filename, training_data, &training_count);

    printf("Enter path to testing data file: ");
    char testing_filename[256];
    scanf("%s", testing_filename);
    load_images(testing_filename, testing_data, &testing_count);

    train_classifier(training_data, training_count);
    test_classifier(testing_data, testing_count);

    return 0;
}
