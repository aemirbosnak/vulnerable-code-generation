//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 28
#define WIDTH 28
#define PIXELS 784
#define CLASSES 10

// Function to load the MNIST dataset
void load_mnist_dataset(float data[][PIXELS], char labels[][10]) {
    FILE *fp;
    int i, j, c;

    fp = fopen("mnist_dataset.txt", "r");

    for (i = 0; i < 60000; i++) {
        for (j = 0; j < PIXELS; j++) {
            fscanf(fp, "%f", &data[i][j]);
        }
        fscanf(fp, "%s", labels[i]);
    }

    fclose(fp);
}

// Function to calculate the Euclidean distance between two vectors
float euclidean_distance(float vector1[], float vector2[]) {
    int i;
    float distance = 0.0;

    for (i = 0; i < PIXELS; i++) {
        distance += pow(vector1[i] - vector2[i], 2);
    }

    return sqrt(distance);
}

// Function to classify the input image
char classify_image(float input_image[][PIXELS], float dataset[][PIXELS], char labels[][10]) {
    int i, j;
    float min_distance = 1000.0;
    char predicted_label[10];

    for (i = 0; i < 60000; i++) {
        float distance = euclidean_distance(input_image, dataset[i]);

        if (distance < min_distance) {
            min_distance = distance;
            strcpy(predicted_label, labels[i]);
        }
    }

    return predicted_label[0];
}

int main() {
    float input_image[HEIGHT][WIDTH] = { {0.0} };
    float dataset[60000][PIXELS] = { {0.0} };
    char labels[60000][10] = { {0} };

    // Load the MNIST dataset
    load_mnist_dataset(dataset, labels);

    // Read the input image
    FILE *fp;
    fp = fopen("input_image.txt", "r");

    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%f", &input_image[i][j]);
        }
    }

    fclose(fp);

    // Classify the input image
    char predicted_label = classify_image(input_image, dataset, labels);

    printf("Predicted label: %c\n", predicted_label);

    return 0;
}