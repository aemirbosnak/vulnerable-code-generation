//FormAI DATASET v1.0 Category: Image Classification system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the number of labels in the dataset
#define NUM_LABELS 10

// Define the size of each image
#define IMAGE_HEIGHT 28
#define IMAGE_WIDTH 28
#define IMAGE_SIZE (IMAGE_HEIGHT * IMAGE_WIDTH)

// Define the number of neurons in the hidden layer
#define HIDDEN_LAYER_SIZE 64

int main()
{
    // Declare variables
    int num_images, num_epochs, i, j, k, l, m, n, label, correct, total;
    double learning_rate, momentum, input[IMAGE_SIZE], output[NUM_LABELS], 
    hidden_weights[IMAGE_SIZE][HIDDEN_LAYER_SIZE], hidden_biases[HIDDEN_LAYER_SIZE], 
    output_weights[HIDDEN_LAYER_SIZE][NUM_LABELS], output_biases[NUM_LABELS], 
    hidden_output[HIDDEN_LAYER_SIZE], output_output[NUM_LABELS], 
    hidden_delta[HIDDEN_LAYER_SIZE], output_delta[NUM_LABELS], 
    input_hidden_weights_delta[IMAGE_SIZE][HIDDEN_LAYER_SIZE], 
    hidden_output_weights_delta[HIDDEN_LAYER_SIZE][NUM_LABELS], 
    input_hidden_biases_delta[HIDDEN_LAYER_SIZE], 
    hidden_output_biases_delta[NUM_LABELS];
    
    // Read in the number of images and epochs
    scanf("%d %d", &num_images, &num_epochs);
    
    // Read in the learning rate and momentum
    scanf("%lf %lf", &learning_rate, &momentum);
    
    // Initialize the weights and biases to random values
    srand(1);
    for (i = 0; i < IMAGE_SIZE; i++)
    {
        for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
        {
            hidden_weights[i][j] = ((double)rand() / RAND_MAX) - 0.5;
        }
    }
    for (i = 0; i < HIDDEN_LAYER_SIZE; i++)
    {
        hidden_biases[i] = ((double)rand() / RAND_MAX) - 0.5;
    }
    for (i = 0; i < HIDDEN_LAYER_SIZE; i++)
    {
        for (j = 0; j < NUM_LABELS; j++)
        {
            output_weights[i][j] = ((double)rand() / RAND_MAX) - 0.5;
        }
    }
    for (i = 0; i < NUM_LABELS; i++)
    {
        output_biases[i] = ((double)rand() / RAND_MAX) - 0.5;
    }
    
    // Train the network
    for (n = 0; n < num_epochs; n++)
    {
        correct = 0;
        total = 0;
        for (i = 0; i < num_images; i++)
        {
            // Read in the input image and label
            for (j = 0; j < IMAGE_SIZE; j++)
            {
                scanf("%lf", &input[j]);
            }
            scanf("%d", &label);
            
            // Initialize the output to all zeros
            for (j = 0; j < NUM_LABELS; j++)
            {
                output[j] = 0;
            }
            
            // Set the desired output to 1 for the correct label
            output[label] = 1;
            
            // Calculate the hidden layer output
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                hidden_output[j] = 0;
                for (k = 0; k < IMAGE_SIZE; k++)
                {
                    hidden_output[j] += input[k] * hidden_weights[k][j];
                }
                hidden_output[j] += hidden_biases[j];
                hidden_output[j] = 1 / (1 + exp(-hidden_output[j]));
            }
            
            // Calculate the output layer output
            for (j = 0; j < NUM_LABELS; j++)
            {
                output_output[j] = 0;
                for (k = 0; k < HIDDEN_LAYER_SIZE; k++)
                {
                    output_output[j] += hidden_output[k] * output_weights[k][j];
                }
                output_output[j] += output_biases[j];
                output_output[j] = 1 / (1 + exp(-output_output[j]));
            }
            
            // Check if the prediction is correct
            if (label == argmax(output_output, NUM_LABELS))
            {
                correct++;
            }
            total++;
            
            // Calculate the output layer delta
            for (j = 0; j < NUM_LABELS; j++)
            {
                output_delta[j] = (output[j] - output_output[j]) * output_output[j] * (1 - output_output[j]);
            }
            
            // Calculate the hidden layer delta
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                hidden_delta[j] = 0;
                for (k = 0; k < NUM_LABELS; k++)
                {
                    hidden_delta[j] += output_delta[k] * output_weights[j][k];
                }
                hidden_delta[j] *= hidden_output[j] * (1 - hidden_output[j]);
            }
            
            // Calculate the input-hidden weights delta
            for (j = 0; j < IMAGE_SIZE; j++)
            {
                for (k = 0; k < HIDDEN_LAYER_SIZE; k++)
                {
                    input_hidden_weights_delta[j][k] = learning_rate * input[j] * hidden_delta[k] + momentum * input_hidden_weights_delta[j][k];
                }
            }
            
            // Calculate the hidden-output weights delta
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                for (k = 0; k < NUM_LABELS; k++)
                {
                    hidden_output_weights_delta[j][k] = learning_rate * hidden_output[j] * output_delta[k] + momentum * hidden_output_weights_delta[j][k];
                }
            }
            
            // Calculate the input-hidden biases delta
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                input_hidden_biases_delta[j] = learning_rate * hidden_delta[j] + momentum * input_hidden_biases_delta[j];
            }
            
            // Calculate the hidden-output biases delta
            for (j = 0; j < NUM_LABELS; j++)
            {
                hidden_output_biases_delta[j] = learning_rate * output_delta[j] + momentum * hidden_output_biases_delta[j];
            }
            
            // Update the weights and biases
            for (j = 0; j < IMAGE_SIZE; j++)
            {
                for (k = 0; k < HIDDEN_LAYER_SIZE; k++)
                {
                    hidden_weights[j][k] += input_hidden_weights_delta[j][k];
                }
            }
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                hidden_biases[j] += input_hidden_biases_delta[j];
            }
            for (j = 0; j < HIDDEN_LAYER_SIZE; j++)
            {
                for (k = 0; k < NUM_LABELS; k++)
                {
                    output_weights[j][k] += hidden_output_weights_delta[j][k];
                }
            }
            for (j = 0; j < NUM_LABELS; j++)
            {
                output_biases[j] += hidden_output_biases_delta[j];
            }
        }
        printf("Epoch %d: Accuracy = %lf\n", n + 1, (double)correct / total);
    }
    
    return 0;
}

// Define the argmax function to find the index of the maximum element in an array
int argmax(double array[], int size)
{
    int i, max_index = 0;
    double max_value = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_value)
        {
            max_value = array[i];
            max_index = i;
        }
    }
    return max_index;
}