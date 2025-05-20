//FormAI DATASET v1.0 Category: Image Classification system ; Style: systematic
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#define IMAGE_SIZE 784   // Number of pixels in each image
#define NUM_CLASSES 10   // Number of classes (0-9 digits)
#define NUM_IMAGES_TRAIN 60000  // Number of training images
#define NUM_IMAGES_TEST 10000    // Number of testing images
#define EPOCHS 10        // Number of training epochs
#define BATCH_SIZE 100   // Number of images used in each training mini-batch
#define LEARNING_RATE 0.1  // Learning rate for gradient descent

// Function to read the MNIST image dataset
void read_mnist_images(char *filename, unsigned char *images, int num_images) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    // Read the header information
    unsigned char header[16];
    fread(header, sizeof(header), 1, fp);
    int num_images_file = (header[4] << 24) | (header[3] << 16) | (header[2] << 8) | header[1];
    int image_size = (header[7] << 24) | (header[6] << 16) | (header[5] << 8) | header[4];
    // Check parameters match those in the file
    if (num_images != num_images_file || image_size != IMAGE_SIZE) {
        printf("Error: file %s has unexpected parameters\n", filename);
        exit(1);
    }
    // Read each image in turn
    for (int i=0; i<num_images; i++) {
        fread(images+i*IMAGE_SIZE, sizeof(unsigned char), IMAGE_SIZE, fp);
    }
    fclose(fp);
}

// Function to read the MNIST label dataset
void read_mnist_labels(char *filename, unsigned char *labels, int num_labels) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    // Read the header information
    unsigned char header[8];
    fread(header, sizeof(header), 1, fp);
    int num_labels_file = (header[4] << 24) | (header[3] << 16) | (header[2] << 8) | header[1];
    // Check parameters match those in the file
    if (num_labels != num_labels_file) {
        printf("Error: file %s has unexpected parameters\n", filename);
        exit(1);
    }
    // Read each image in turn
    for (int i=0; i<num_labels; i++) {
        fread(labels+i, sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
}

// Function to initialize the weights for the neural network
void init_weights(double *weights) {
    for (int i=0; i<NUM_CLASSES*IMAGE_SIZE; i++) {
        weights[i] = ((double) rand() / RAND_MAX) - 0.5;  // Random weights between -0.5 and 0.5
    }
}

// Function to calculate the softmax of a vector
void softmax(double *x, double *y, int n) {
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += exp(x[i]);
    }
    for (int i=0; i<n; i++) {
        y[i] = exp(x[i]) / sum;
    }
}

// Function to classify an image using the current weights
int classify_image(double *weights, unsigned char *image) {
    double output[NUM_CLASSES];
    double input[IMAGE_SIZE];
    // Convert image to double precision and normalize to be between 0 and 1
    for (int i=0; i<IMAGE_SIZE; i++) {
        input[i] = (double) image[i] / 255.0;
    }
    // Calculate the weighted sum for each class and apply the softmax function
    for (int j=0; j<NUM_CLASSES; j++) {
        double weighted_sum = 0;
        for (int i=0; i<IMAGE_SIZE; i++) {
            weighted_sum += weights[j*IMAGE_SIZE + i] * input[i];
        }
        output[j] = weighted_sum;
    }
    softmax(output, output, NUM_CLASSES);
    // Find the index of the largest output value
    int max_index = 0;
    for (int i=1; i<NUM_CLASSES; i++) {
        if (output[i] > output[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// Function to calculate the loss function for a mini-batch
double loss_function(double *weights, unsigned char *images, unsigned char *labels, int batch_size) {
    double loss = 0;
    for (int n=0; n<batch_size; n++) {
        double output[NUM_CLASSES];
        double input[IMAGE_SIZE];
        // Convert image to double precision and normalize to be between 0 and 1
        for (int i=0; i<IMAGE_SIZE; i++) {
            input[i] = (double) images[(n*IMAGE_SIZE)+i] / 255.0;
        }
        // Calculate the weighted sum for each class and apply the softmax function
        for (int j=0; j<NUM_CLASSES; j++) {
            double weighted_sum = 0;
            for (int i=0; i<IMAGE_SIZE; i++) {
                weighted_sum += weights[j*IMAGE_SIZE + i] * input[i];
            }
            output[j] = weighted_sum;
        }
        softmax(output, output, NUM_CLASSES);
        // Calculate the cross-entropy loss
        int label = labels[n];
        loss -= log(output[label]);
    }
    loss /= batch_size;
    return loss;
}

// Function to perform one epoch of gradient descent on the training set
void train_epoch(double *weights, unsigned char *images, unsigned char *labels, int num_images, int batch_size, double learning_rate) {
    // Shuffle the indices of the images
    int indices[num_images];
    for (int i=0; i<num_images; i++) {
        indices[i] = i;
    }
    for (int i=0; i<num_images; i++) {
        int j = rand() % num_images;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
    // Iterate through each mini-batch
    for (int n=0; n<num_images; n+=batch_size) {
        double gradients[NUM_CLASSES*IMAGE_SIZE];
        memset(gradients, 0, NUM_CLASSES*IMAGE_SIZE*sizeof(double));
        // Calculate the gradient for each image in the mini-batch
        for (int b=0; b<batch_size; b++) {
            double output[NUM_CLASSES];
            double input[IMAGE_SIZE];
            // Convert image to double precision and normalize to be between 0 and 1
            for (int i=0; i<IMAGE_SIZE; i++) {
                input[i] = (double) images[(indices[n+b]*IMAGE_SIZE)+i] / 255.0;
            }
            // Calculate the weighted sum for each class and apply the softmax function
            for (int j=0; j<NUM_CLASSES; j++) {
                double weighted_sum = 0;
                for (int i=0; i<IMAGE_SIZE; i++) {
                    weighted_sum += weights[j*IMAGE_SIZE + i] * input[i];
                }
                output[j] = weighted_sum;
            }
            softmax(output, output, NUM_CLASSES);
            // Calculate the gradient for each weight
            int label = labels[indices[n+b]];
            for (int j=0; j<NUM_CLASSES; j++) {
                for (int i=0; i<IMAGE_SIZE; i++) {
                    double gradient = input[i] * (j == label ? 1 : 0);
                    gradient -= input[i] * output[j];
                    gradients[j*IMAGE_SIZE + i] += gradient;
                }
            }
        }
        // Update the weights for this mini-batch
        for (int j=0; j<NUM_CLASSES; j++) {
            for (int i=0; i<IMAGE_SIZE; i++) {
                weights[j*IMAGE_SIZE + i] -= learning_rate * gradients[j*IMAGE_SIZE + i] / batch_size;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Set random seed for reproducibility
    srand(42);
    // Allocate memory for the data
    unsigned char *train_images = (unsigned char*) malloc(NUM_IMAGES_TRAIN * IMAGE_SIZE * sizeof(unsigned char));
    unsigned char *train_labels = (unsigned char*) malloc(NUM_IMAGES_TRAIN * sizeof(unsigned char));
    unsigned char *test_images = (unsigned char*) malloc(NUM_IMAGES_TEST * IMAGE_SIZE * sizeof(unsigned char));
    unsigned char *test_labels = (unsigned char*) malloc(NUM_IMAGES_TEST * sizeof(unsigned char));
    double *weights = (double*) malloc(NUM_CLASSES * IMAGE_SIZE * sizeof(double));
    // Read in the MNIST image and label datasets
    read_mnist_images("train-images-idx3-ubyte", train_images, NUM_IMAGES_TRAIN);
    read_mnist_labels("train-labels-idx1-ubyte", train_labels, NUM_IMAGES_TRAIN);
    read_mnist_images("t10k-images-idx3-ubyte", test_images, NUM_IMAGES_TEST);
    read_mnist_labels("t10k-labels-idx1-ubyte", test_labels, NUM_IMAGES_TEST);
    // Initialize the weights
    init_weights(weights);
    // Train the model for the specified number of epochs
    for (int epoch=0; epoch<EPOCHS; epoch++) {
        train_epoch(weights, train_images, train_labels, NUM_IMAGES_TRAIN, BATCH_SIZE, LEARNING_RATE);
        double train_loss = loss_function(weights, train_images, train_labels, NUM_IMAGES_TRAIN);
        double test_loss = loss_function(weights, test_images, test_labels, NUM_IMAGES_TEST);
        printf("Epoch %d: Training loss = %f, Test loss = %f\n", epoch+1, train_loss, test_loss);
    }
    // Test the model on some example images
    int num_examples = 10;
    for (int i=0; i<num_examples; i++) {
        int index = rand() % NUM_IMAGES_TEST;
        unsigned char *image = test_images + index*IMAGE_SIZE;
        int label = test_labels[index];
        int prediction = classify_image(weights, image);
        printf("Example %d: actual = %d, predicted = %d\n", i+1, label, prediction);
    }
    // Free memory used by data
    free(train_images);
    free(train_labels);
    free(test_images);
    free(test_labels);
    free(weights);
    return 0;
}