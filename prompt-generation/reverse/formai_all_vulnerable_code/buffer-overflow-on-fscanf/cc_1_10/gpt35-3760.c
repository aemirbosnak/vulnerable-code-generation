//FormAI DATASET v1.0 Category: Image Classification system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PIXELS 784 // 28 x 28 image
#define NUM_OUTPUTS 10 // 10 possible classifications

double sigmoid(double x);
double dot(double *arr1, double *arr2, int len);
int max_index(double *arr, int len);

int main() {

    // load image data and outputs
    double image[NUM_PIXELS];
    char filename[20];
    printf("Enter image filename: ");
    scanf("%19s", filename); // limit filename to 19 characters
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error loading file\n");
        exit(1);
    }
    for (int i = 0; i < NUM_PIXELS; i++) {
        fscanf(f, "%lf", &image[i]);
    }
    fclose(f);

    // load weights from file
    double weights[NUM_OUTPUTS][NUM_PIXELS];
    f = fopen("weights.txt", "r");
    if (f == NULL) {
        printf("Error loading file\n");
        exit(1);
    }
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        for (int j = 0; j < NUM_PIXELS; j++) {
            fscanf(f, "%lf", &weights[i][j]);
        }
    }
    fclose(f);

    // calculate output values for each classification
    double outputs[NUM_OUTPUTS];
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        outputs[i] = sigmoid(dot(weights[i], image, NUM_PIXELS));
    }

    // output predicted classification
    int pred = max_index(outputs, NUM_OUTPUTS);
    printf("Predicted Classification: %d\n", pred);

    return 0;
}

// sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// dot product of two arrays
double dot(double *arr1, double *arr2, int len) {
    double res = 0;
    for (int i = 0; i < len; i++) {
        res += arr1[i] * arr2[i];
    }
    return res;
}

// index of max value in array
int max_index(double *arr, int len) {
    int max_i = 0;
    for (int i = 1; i < len; i++) {
        if (arr[i] > arr[max_i]) {
            max_i = i;
        }
    }
    return max_i;
}