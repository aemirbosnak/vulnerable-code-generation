//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double r;
    double g;
    double b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

typedef struct {
    int num_classes;
    double *weights;
} Classifier;

Image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int width, height;
    fread(&width, sizeof(int), 1, f);
    fread(&height, sizeof(int), 1, f);

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(Pixel) * width * height);

    fread(image->data, sizeof(Pixel), width * height, f);

    fclose(f);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Classifier *load_classifier(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int num_classes;
    fread(&num_classes, sizeof(int), 1, f);

    Classifier *classifier = malloc(sizeof(Classifier));
    classifier->num_classes = num_classes;
    classifier->weights = malloc(sizeof(double) * num_classes);

    fread(classifier->weights, sizeof(double), num_classes, f);

    fclose(f);

    return classifier;
}

void free_classifier(Classifier *classifier) {
    free(classifier->weights);
    free(classifier);
}

int classify_image(Image *image, Classifier *classifier) {
    double max_score = -INFINITY;
    int max_class = -1;

    for (int i = 0; i < classifier->num_classes; i++) {
        double score = 0.0;
        for (int j = 0; j < image->width * image->height; j++) {
            score += classifier->weights[i] * image->data[j].r;
            score += classifier->weights[i] * image->data[j].g;
            score += classifier->weights[i] * image->data[j].b;
        }

        if (score > max_score) {
            max_score = score;
            max_class = i;
        }
    }

    return max_class;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Classifier *classifier = load_classifier(argv[2]);
    if (classifier == NULL) {
        return 1;
    }

    int class = classify_image(image, classifier);

    printf("Image classified as: %d\n", class);

    free_image(image);
    free_classifier(classifier);

    return 0;
}