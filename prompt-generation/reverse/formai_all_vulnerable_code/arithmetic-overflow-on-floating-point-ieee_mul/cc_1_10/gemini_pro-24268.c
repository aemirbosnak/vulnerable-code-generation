//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fread(&image->channels, sizeof(int), 1, file);

    image->data = malloc(image->width * image->height * image->channels * sizeof(unsigned char));
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height * image->channels, file);
    fclose(file);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Classifier *load_classifier(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    Classifier *classifier = malloc(sizeof(Classifier));
    if (classifier == NULL) {
        fprintf(stderr, "Error allocating memory for classifier\n");
        fclose(file);
        return NULL;
    }

    fread(&classifier->num_classes, sizeof(int), 1, file);

    classifier->weights = malloc(classifier->num_classes * sizeof(float));
    if (classifier->weights == NULL) {
        fprintf(stderr, "Error allocating memory for classifier weights\n");
        fclose(file);
        free(classifier);
        return NULL;
    }

    classifier->biases = malloc(classifier->num_classes * sizeof(float));
    if (classifier->biases == NULL) {
        fprintf(stderr, "Error allocating memory for classifier biases\n");
        fclose(file);
        free(classifier->weights);
        free(classifier);
        return NULL;
    }

    fread(classifier->weights, sizeof(float), classifier->num_classes, file);
    fread(classifier->biases, sizeof(float), classifier->num_classes, file);
    fclose(file);

    return classifier;
}

void free_classifier(Classifier *classifier) {
    free(classifier->weights);
    free(classifier->biases);
    free(classifier);
}

int predict(Image *image, Classifier *classifier) {
    float *logits = malloc(classifier->num_classes * sizeof(float));
    if (logits == NULL) {
        fprintf(stderr, "Error allocating memory for logits\n");
        return -1;
    }

    for (int i = 0; i < classifier->num_classes; i++) {
        logits[i] = 0;
        for (int j = 0; j < image->width * image->height * image->channels; j++) {
            logits[i] += image->data[j] * classifier->weights[i * image->width * image->height * image->channels + j];
        }
        logits[i] += classifier->biases[i];
    }

    int prediction = -1;
    float max_logit = -INFINITY;
    for (int i = 0; i < classifier->num_classes; i++) {
        if (logits[i] > max_logit) {
            max_logit = logits[i];
            prediction = i;
        }
    }

    free(logits);
    return prediction;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Classifier *classifier = load_classifier(argv[2]);
    if (classifier == NULL) {
        free_image(image);
        return 1;
    }

    int prediction = predict(image, classifier);
    if (prediction == -1) {
        fprintf(stderr, "Error predicting image\n");
        free_image(image);
        free_classifier(classifier);
        return 1;
    }

    printf("Predicted class: %d\n", prediction);

    free_image(image);
    free_classifier(classifier);
    return 0;
}