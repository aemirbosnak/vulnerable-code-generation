//FormAI DATASET v1.0 Category: Image Classification system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IMAGE_SIZE 256
#define NUM_CLASSES 10

// Function to load the image data
void load_data(float* data, char* filename){
    FILE *fp;
    fp = fopen(filename, "rb");
    fread(data, sizeof(float), IMAGE_SIZE, fp);
    fclose(fp);
}

// Function to calculate the dot product of two vectors
float dot_product(float* v1, float* v2, int n){
    float result = 0;
    for(int i = 0; i<n; i++){
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to calculate the softmax of a vector
void softmax(float* v, int n){
    float sum = 0;
    for(int i = 0; i<n; i++){
        sum += exp(v[i]);
    }
    for(int i = 0; i<n; i++){
        v[i] = exp(v[i]) / sum;
    }
}

int main(){
    // Initialize the weights and biases
    float weights[NUM_CLASSES][IMAGE_SIZE];
    float biases[NUM_CLASSES];

    // Load the weights and biases from file
    load_data(weights, "weights.bin");
    load_data(biases, "biases.bin");

    // Declare the input image
    float image[IMAGE_SIZE];
    // Load the image from file
    load_data(image, "image.bin");

    // Declare the output vector
    float output[NUM_CLASSES];

    // Multiply the input image by the weights and add the biases
    for(int i = 0; i<NUM_CLASSES; i++){
        output[i] = dot_product(weights[i], image, IMAGE_SIZE) + biases[i];
    }

    // Apply the softmax function to get the probabilities
    softmax(output, NUM_CLASSES);

    // Print the probabilities
    printf("Probabilities:\n");
    for(int i = 0; i<NUM_CLASSES; i++){
        printf("%d: %f\n", i, output[i]);
    }

    // Determine the predicted class
    int predicted_class = 0;
    float highest_prob = 0;
    for(int i = 0; i<NUM_CLASSES; i++){
        if(output[i] > highest_prob){
            predicted_class = i;
            highest_prob = output[i];
        }
    }

    // Print the predicted class
    printf("Predicted Class: %d\n", predicted_class);

    return 0;
}