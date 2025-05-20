//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

typedef struct {
    int num_classes;
    float *weights;
    float *biases;
} Classifier;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(1);
    }

    Image image;
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);
    fread(&image.channels, sizeof(int), 1, fp);
    image.data = malloc(image.width * image.height * image.channels);
    fread(image.data, sizeof(unsigned char), image.width * image.height * image.channels, fp);
    fclose(fp);

    return image;
}

void free_image(Image image) {
    free(image.data);
}

Classifier load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(1);
    }

    Classifier classifier;
    fread(&classifier.num_classes, sizeof(int), 1, fp);
    classifier.weights = malloc(classifier.num_classes * sizeof(float));
    fread(classifier.weights, sizeof(float), classifier.num_classes, fp);
    classifier.biases = malloc(classifier.num_classes * sizeof(float));
    fread(classifier.biases, sizeof(float), classifier.num_classes, fp);
    fclose(fp);

    return classifier;
}

void free_classifier(Classifier classifier) {
    free(classifier.weights);
    free(classifier.biases);
}

int classify(Image image, Classifier classifier) {
    float *scores = malloc(classifier.num_classes * sizeof(float));
    for (int i = 0; i < classifier.num_classes; i++) {
        scores[i] = 0;
        for (int j = 0; j < image.width * image.height * image.channels; j++) {
            scores[i] += image.data[j] * classifier.weights[i * image.width * image.height * image.channels + j];
        }
        scores[i] += classifier.biases[i];
    }

    int max_score_index = 0;
    for (int i = 1; i < classifier.num_classes; i++) {
        if (scores[i] > scores[max_score_index]) {
            max_score_index = i;
        }
    }

    free(scores);
    return max_score_index;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        exit(1);
    }

    Image image = load_image(argv[1]);
    Classifier classifier = load_classifier(argv[2]);

    int class = classify(image, classifier);
    printf("Predicted class: %d\n", class);

    free_image(image);
    free_classifier(classifier);

    return 0;
}