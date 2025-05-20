//FormAI DATASET v1.0 Category: Image Classification system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IMAGE_SIZE 28 // Define the image size 
#define NUM_CLASSES 10 // Number of classes for classification

// Define a structure for holding image data and its label
typedef struct {
    int pixels[IMAGE_SIZE][IMAGE_SIZE];
    int label;
} Image;

// Define a structure for holding neural network weights and biases
typedef struct {
    double inputLayer[IMAGE_SIZE * IMAGE_SIZE];
    double hiddenLayer[128];
    double outputLayer[NUM_CLASSES];
    double hidden_bias[128];
    double output_bias[NUM_CLASSES];
} Network;

// Function to load image data and its label from file
void loadImage(Image* image, FILE* file) {
    unsigned char data[IMAGE_SIZE * IMAGE_SIZE + 1];
    fread(data, sizeof(unsigned char), IMAGE_SIZE * IMAGE_SIZE + 1, file);
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            image->pixels[i][j] = (int)data[i * IMAGE_SIZE + j + 1];
        }
    }
    image->label = (int)data[0];
}

// Function to calculate sigmoid of a number
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Function to feed forward through the neural network and calculate output probabilities
void feedForward(Network* network, double probabilities[NUM_CLASSES]) {
    for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++) {
        network->hiddenLayer[i] = 0;
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        network->outputLayer[i] = 0;
    }
    for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++) {
        network->hiddenLayer[i / IMAGE_SIZE] += network->inputLayer[i];
    }
    for (int i = 0; i < 128; i++) {
        network->hiddenLayer[i] += network->hidden_bias[i];
        network->hiddenLayer[i] = sigmoid(network->hiddenLayer[i]);
    }
    for (int i = 0; i < NUM_CLASSES; i++) {
        for (int j = 0; j < 128; j++) {
            network->outputLayer[i] += network->hiddenLayer[j];
        }
        network->outputLayer[i] += network->output_bias[i];
        probabilities[i] = sigmoid(network->outputLayer[i]);
    }
}

int main() {
    // Load the pre-trained neural network weights and biases from file
    FILE* file;
    file = fopen("pretrained_network.txt", "r");
    Network network;
    fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
      &network.inputLayer[0], &network.inputLayer[1],
      &network.inputLayer[2], &network.inputLayer[3],
      &network.inputLayer[4], &network.inputLayer[5],
      &network.inputLayer[6], &network.inputLayer[7],
      &network.inputLayer[8], &network.inputLayer[9]);
    fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
      &network.hidden_bias[0], &network.hidden_bias[1],
      &network.hidden_bias[2], &network.hidden_bias[3],
      &network.hidden_bias[4], &network.hidden_bias[5],
      &network.hidden_bias[6], &network.hidden_bias[7],
      &network.hidden_bias[8], &network.hidden_bias[9]);
    fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
      &network.output_bias[0], &network.output_bias[1],
      &network.output_bias[2], &network.output_bias[3],
      &network.output_bias[4], &network.output_bias[5],
      &network.output_bias[6], &network.output_bias[7],
      &network.output_bias[8], &network.output_bias[9]);
    fclose(file);

    // Load the image to be classified
    Image image;
    file = fopen("image_to_classify.txt", "r");
    loadImage(&image, file);
    fclose(file);

    // Feed forward through the neural network to calculate output probabilities
    double probabilities[NUM_CLASSES];
    feedForward(&network, probabilities);

    // Print the classification result
    int maxIndex = 0;
    for (int i = 1; i < NUM_CLASSES; i++) {
        if (probabilities[i] > probabilities[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("The image is classified as %d\n", maxIndex);

    return 0;
}