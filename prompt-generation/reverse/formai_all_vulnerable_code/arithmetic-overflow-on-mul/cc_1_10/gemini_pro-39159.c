//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    int width, height, channels;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&channels, sizeof(int), 1, fp);

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels * sizeof(float));
    fread(image->data, sizeof(float), width * height * channels, fp);

    fclose(fp);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Classifier *load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    int num_classes;
    fread(&num_classes, sizeof(int), 1, fp);

    Classifier *classifier = malloc(sizeof(Classifier));
    classifier->num_classes = num_classes;
    classifier->weights = malloc(num_classes * sizeof(float));
    classifier->biases = malloc(num_classes * sizeof(float));
    fread(classifier->weights, sizeof(float), num_classes, fp);
    fread(classifier->biases, sizeof(float), num_classes, fp);

    fclose(fp);

    return classifier;
}

void free_classifier(Classifier *classifier) {
    free(classifier->weights);
    free(classifier->biases);
    free(classifier);
}

int classify(Image *image, Classifier *classifier) {
    float *scores = malloc(classifier->num_classes * sizeof(float));

    for (int i = 0; i < classifier->num_classes; i++) {
        float score = 0;
        for (int j = 0; j < image->width * image->height * image->channels; j++) {
            score += image->data[j] * classifier->weights[i * image->width * image->height * image->channels + j];
        }
        score += classifier->biases[i];
        scores[i] = score;
    }

    int max_score_index = 0;
    float max_score = scores[0];
    for (int i = 1; i < classifier->num_classes; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            max_score_index = i;
        }
    }

    free(scores);

    return max_score_index;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image_file> <classifier_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    Classifier *classifier = load_classifier(argv[2]);
    if (!classifier) {
        return EXIT_FAILURE;
    }

    int prediction = classify(image, classifier);

    printf("Predicted class: %d\n", prediction);

    free_image(image);
    free_classifier(classifier);

    return EXIT_SUCCESS;
}