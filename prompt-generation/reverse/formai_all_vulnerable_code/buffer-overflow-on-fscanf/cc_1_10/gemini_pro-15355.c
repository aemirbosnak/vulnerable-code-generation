//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_CLASSES 10
#define MAX_FEATURES 100

typedef struct {
    int class;
    float features[MAX_FEATURES];
} Image;

typedef struct {
    int num_classes;
    int num_features;
    float weights[MAX_CLASSES][MAX_FEATURES];
    float biases[MAX_CLASSES];
} Classifier;

Image* load_image(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Image* image = malloc(sizeof(Image));
    fscanf(fp, "%d", &image->class);
    for (int i = 0; i < MAX_FEATURES; i++) {
        fscanf(fp, "%f", &image->features[i]);
    }

    fclose(fp);
    return image;
}

Classifier* load_classifier(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    Classifier* classifier = malloc(sizeof(Classifier));
    fscanf(fp, "%d", &classifier->num_classes);
    fscanf(fp, "%d", &classifier->num_features);
    for (int i = 0; i < classifier->num_classes; i++) {
        for (int j = 0; j < classifier->num_features; j++) {
            fscanf(fp, "%f", &classifier->weights[i][j]);
        }
    }

    for (int i = 0; i < classifier->num_classes; i++) {
        fscanf(fp, "%f", &classifier->biases[i]);
    }

    fclose(fp);
    return classifier;
}

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

int classify_image(const Image* image, const Classifier* classifier) {
    float scores[MAX_CLASSES];
    for (int i = 0; i < classifier->num_classes; i++) {
        float score = classifier->biases[i];
        for (int j = 0; j < classifier->num_features; j++) {
            score += classifier->weights[i][j] * image->features[j];
        }
        scores[i] = sigmoid(score);
    }

    int predicted_class = 0;
    float max_score = scores[0];
    for (int i = 1; i < classifier->num_classes; i++) {
        if (scores[i] > max_score) {
            predicted_class = i;
            max_score = scores[i];
        }
    }

    return predicted_class;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <image file> <classifier file>\n", argv[0]);
        return 1;
    }

    Image* image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Classifier* classifier = load_classifier(argv[2]);
    if (classifier == NULL) {
        return 1;
    }

    int predicted_class = classify_image(image, classifier);
    printf("Predicted class: %d\n", predicted_class);

    free(image);
    free(classifier);
    return 0;
}