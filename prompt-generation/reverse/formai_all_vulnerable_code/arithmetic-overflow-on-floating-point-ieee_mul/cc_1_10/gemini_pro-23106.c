//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28
#define NUM_CLASSES 10

typedef struct {
    float pixels[IMAGE_WIDTH * IMAGE_HEIGHT];
    int label;
} image_t;

typedef struct {
    float weights[IMAGE_WIDTH * IMAGE_HEIGHT * NUM_CLASSES];
    float biases[NUM_CLASSES];
} model_t;

float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

void forward_pass(model_t *model, image_t *image, float *output) {
    for (int i = 0; i < NUM_CLASSES; i++) {
        float sum = 0;
        for (int j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) {
            sum += image->pixels[j] * model->weights[i * IMAGE_WIDTH * IMAGE_HEIGHT + j];
        }
        sum += model->biases[i];
        output[i] = sigmoid(sum);
    }
}

int main() {
    // Load the model
    model_t model;
    FILE *model_file = fopen("model.dat", "rb");
    fread(&model, sizeof(model), 1, model_file);
    fclose(model_file);

    // Load the image
    image_t image;
    FILE *image_file = fopen("image.dat", "rb");
    fread(&image, sizeof(image), 1, image_file);
    fclose(image_file);

    // Perform forward pass
    float output[NUM_CLASSES];
    forward_pass(&model, &image, output);

    // Find the predicted class
    int predicted_class = 0;
    float max_prob = 0;
    for (int i = 0; i < NUM_CLASSES; i++) {
        if (output[i] > max_prob) {
            max_prob = output[i];
            predicted_class = i;
        }
    }

    // Print the predicted class
    printf("Predicted class: %d\n", predicted_class);

    return 0;
}