//FormAI DATASET v1.0 Category: Image Classification system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

float image_data[IMAGE_WIDTH][IMAGE_HEIGHT];

float weights[10][IMAGE_WIDTH * IMAGE_HEIGHT];
float bias[10];

int predict_image(void);
void load_weights(void);
void load_bias(void);

int main(void) {
    int i, j;

    // Load the image data from a file
    FILE *image_file = fopen("image_data.txt", "r");
    if (image_file == NULL) {
        printf("Error: could not open image_data.txt\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            float value;
            fscanf(image_file, "%f", &value);
            image_data[i][j] = value;
        }
    }
    fclose(image_file);

    // Load the weights and bias
    load_weights();
    load_bias();

    // Predict the digit
    int predicted_digit = predict_image();
    printf("Predicted digit: %d\n", predicted_digit);

    return EXIT_SUCCESS;
}

int predict_image() {
    int i, j, k;
    float score[10] = {0};

    for (k = 0; k < 10; k++) { // for each digit
        // Calculate the score for this digit
        for (i = 0; i < IMAGE_HEIGHT; i++) {
            for (j = 0; j < IMAGE_WIDTH; j++) {
                score[k] += image_data[i][j] * weights[k][i * IMAGE_WIDTH + j];
            }
        }
        score[k] += bias[k];
    }

    // Find the digit with the highest score
    int max_idx = 0;
    float max_score = score[0];
    for (i = 1; i < 10; i++) {
        if (score[i] > max_score) {
            max_idx = i;
            max_score = score[i];
        }
    }
    return max_idx;
}

void load_weights() {
    int i, j;
    FILE *weights_file = fopen("weights.txt", "r");
    if (weights_file == NULL) {
        printf("Error: could not open weights.txt\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 10; i++) { // for each digit
        for (j = 0; j < IMAGE_WIDTH * IMAGE_HEIGHT; j++) { // for each weight
            fscanf(weights_file, "%f", &weights[i][j]);
        }
    }
    fclose(weights_file);
}

void load_bias() {
    int i;
    FILE *bias_file = fopen("bias.txt", "r");
    if (bias_file == NULL) {
        printf("Error: could not open bias.txt\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < 10; i++) { // for each digit
        fscanf(bias_file, "%f", &bias[i]);
    }
    fclose(bias_file);
}