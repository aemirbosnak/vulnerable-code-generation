//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    int width, height, channels;
    fscanf(fp, "%d %d %d", &width, &height, &channels);

    Image image;
    image.width = width;
    image.height = height;
    image.channels = channels;
    image.data = malloc(width * height * channels * sizeof(float));

    fread(image.data, sizeof(float), width * height * channels, fp);
    fclose(fp);

    return image;
}

Classifier load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    int num_classes;
    fscanf(fp, "%d", &num_classes);

    Classifier classifier;
    classifier.num_classes = num_classes;
    classifier.weights = malloc(num_classes * sizeof(float));
    classifier.biases = malloc(num_classes * sizeof(float));

    fread(classifier.weights, sizeof(float), num_classes, fp);
    fread(classifier.biases, sizeof(float), num_classes, fp);
    fclose(fp);

    return classifier;
}

void classify_image(Image image, Classifier classifier) {
    float *scores = malloc(classifier.num_classes * sizeof(float));

    for (int i = 0; i < classifier.num_classes; i++) {
        float score = 0;
        for (int j = 0; j < image.width * image.height * image.channels; j++) {
            score += image.data[j] * classifier.weights[i];
        }
        score += classifier.biases[i];
        scores[i] = score;
    }

    int max_index = 0;
    float max_score = -INFINITY;
    for (int i = 0; i < classifier.num_classes; i++) {
        if (scores[i] > max_score) {
            max_index = i;
            max_score = scores[i];
        }
    }

    printf("Predicted class: %d\n", max_index);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        exit(1);
    }

    Image image = load_image(argv[1]);
    Classifier classifier = load_classifier(argv[2]);

    classify_image(image, classifier);

    free(image.data);
    free(classifier.weights);
    free(classifier.biases);

    return 0;
}