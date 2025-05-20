//FormAI DATASET v1.0 Category: Image Classification system ; Style: visionary
// Our C Image Classification System Example Program

#include <stdio.h>
#include <stdlib.h>

#define ROWS 28
#define COLS 28

// Define our image structure
typedef struct Image {
    int rows;
    int cols;
    int pixels[ROWS][COLS];
    char label;
} Image;

// Define our neuron structure
typedef struct Neuron {
    double weights[ROWS][COLS];
    double bias;
} Neuron;

// Function to read in image data from file
void load_image_data(char* file_name, Image* image) {
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    fscanf(fp, "%d", &(image->rows));
    fscanf(fp, "%d", &(image->cols));
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            fscanf(fp, "%d", &(image->pixels[i][j]));
        }
    }
    fscanf(fp, " %c", &(image->label));
    fclose(fp);
}

// Function to initialize random weights and biases for a neuron
void init_neuron(Neuron* neuron) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            neuron->weights[i][j] = ((double)rand()/(double)RAND_MAX);
        }
    }
    neuron->bias = ((double)rand()/(double)RAND_MAX);
}

// Function to calculate the dot product of a neuron with an image
double dot_product(Neuron* neuron, Image* image) {
    double sum = 0.0;
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            sum += (neuron->weights[i][j] * image->pixels[i][j]);
        }
    }
    sum += neuron->bias;
    return sum;
}

// Function to train the neuron using gradient descent
void train_neuron(Neuron* neuron, Image* image, double learning_rate) {
    double predicted_value = dot_product(neuron, image);
    double error = (double)(image->label - predicted_value);
    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            neuron->weights[i][j] += learning_rate * error * image->pixels[i][j];
        }
    }
    neuron->bias += learning_rate * error;
}

int main() {
    // Load in the image data
    Image image;
    load_image_data("image.txt", &image);

    // Create a neuron
    Neuron neuron;
    init_neuron(&neuron);

    // Train the neuron on the image
    double learning_rate = 0.1;
    for (int i = 0; i < 1000; i++) {
        train_neuron(&neuron, &image, learning_rate);
    }

    // Classify the image
    double predicted_value = dot_product(&neuron, &image);
    if (predicted_value > 0.5) {
        printf("The image is classified as a '%c'\n", '1');
    } else {
        printf("The image is classified as not a '%c'\n", '1');
    }

    return 0;
}