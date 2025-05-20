//FormAI DATASET v1.0 Category: Image Classification system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 784 // 28 x 28
#define NUM_LABELS 10 // 0-9

typedef struct {
    float weights[IMAGE_SIZE][NUM_LABELS];
    float biases[NUM_LABELS];
} Model;

void softmax(float *arr, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        arr[i] = expf(arr[i]);
        sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= sum;
    }
}

void predict(Model *model, float *image, int *label) {
    float output[NUM_LABELS];
    memset(output, 0, sizeof(output));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < NUM_LABELS; j++) {
            output[j] += image[i] * model->weights[i][j];
        }
    }
    for (int i = 0; i < NUM_LABELS; i++) {
        output[i] += model->biases[i];
    }
    softmax(output, NUM_LABELS);
    *label = 0;
    for (int i = 1; i < NUM_LABELS; i++) {
        if (output[i] > output[*label]) {
            *label = i;
        }
    }
}

int main() {
    Model model;
    FILE *fp = fopen("model.bin", "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open model file\n");
        return 1;
    }
    fread(&model, sizeof(model), 1, fp);
    fclose(fp);

    float test_image[IMAGE_SIZE];
    printf("Enter a %dx%d image:\n", (int)sqrt(IMAGE_SIZE), (int)sqrt(IMAGE_SIZE));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        scanf("%f", &test_image[i]);
    }

    int label;
    predict(&model, test_image, &label);
    printf("Predicted label: %d\n", label);

    return 0;
}