#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGES 1000
#define IMAGE_SIZE 28 * 28

typedef struct {
    int label;
    float pixels[IMAGE_SIZE];
} Image;

void read_images(const char* filename, Image images[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    while (fscanf(file, "%d", &images[*count].label) != EOF) {
        for (int i = 0; i < IMAGE_SIZE; i++) {
            fscanf(file, "%f", &images[*count].pixels[i]);
        }
        (*count)++;
    }
    fclose(file);
}

float train_classifier(Image training_data[], int count) {
    // Simple dummy classifier: always predict class 0
    return 0.0;
}

float test_classifier(Image testing_data[], int count, float classifier) {
    int correct = 0;
    for (int i = 0; i < count; i++) {
        if (testing_data[i].label == 0) {
            correct++;
        }
    }
    return (float)correct / count;
}

int main() {
    Image training_data[MAX_IMAGES], testing_data[MAX_IMAGES];
    int training_count = 0, testing_count = 0;

    printf("Enter training data file name: ");
    char training_filename[100];
    scanf("%s", training_filename);
    read_images(training_filename, training_data, &training_count);

    printf("Enter testing data file name: ");
    char testing_filename[100];
    scanf("%s", testing_filename);
    read_images(testing_filename, testing_data, &testing_count);

    float classifier = train_classifier(training_data, training_count);
    float accuracy = test_classifier(testing_data, testing_count, classifier);

    printf("Classifier accuracy: %.2f%%\n", accuracy * 100);

    return 0;
}
