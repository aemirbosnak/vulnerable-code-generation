//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int channels;
    float *data;
} Image;

typedef struct {
    int num_classes;
    float *weights;
    float *biases;
} Classifier;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    // Read header
    int width, height, channels;
    fscanf(fp, "%d %d %d", &width, &height, &channels);

    // Read data
    float *data = malloc(width * height * channels * sizeof(float));
    fread(data, sizeof(float), width * height * channels, fp);

    fclose(fp);

    // Create image struct
    Image image = {
        .width = width,
        .height = height,
        .channels = channels,
        .data = data
    };

    return image;
}

Classifier load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    // Read header
    int num_classes;
    fscanf(fp, "%d", &num_classes);

    // Read weights
    float *weights = malloc(num_classes * sizeof(float));
    fread(weights, sizeof(float), num_classes, fp);

    // Read biases
    float *biases = malloc(num_classes * sizeof(float));
    fread(biases, sizeof(float), num_classes, fp);

    fclose(fp);

    // Create classifier struct
    Classifier classifier = {
        .num_classes = num_classes,
        .weights = weights,
        .biases = biases
    };

    return classifier;
}

void classify_image(Image image, Classifier classifier) {
    // Compute activations
    float *activations = malloc(classifier.num_classes * sizeof(float));
    for (int i = 0; i < classifier.num_classes; i++) {
        float activation = 0;
        for (int j = 0; j < image.width * image.height * image.channels; j++) {
            activation += image.data[j] * classifier.weights[i * image.width * image.height * image.channels + j];
        }
        activation += classifier.biases[i];
        activations[i] = activation;
    }

    // Find max activation
    int max_index = 0;
    float max_activation = -INFINITY;
    for (int i = 0; i < classifier.num_classes; i++) {
        if (activations[i] > max_activation) {
            max_index = i;
            max_activation = activations[i];
        }
    }

    // Print predicted class
    printf("Predicted class: %d\n", max_index);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image_filename> <classifier_filename>\n", argv[0]);
        exit(1);
    }

    // Load image
    Image image = load_image(argv[1]);

    // Load classifier
    Classifier classifier = load_classifier(argv[2]);

    // Classify image
    classify_image(image, classifier);

    // Free memory
    free(image.data);
    free(classifier.weights);
    free(classifier.biases);

    return 0;
}