//FormAI DATASET v1.0 Category: Image Classification system ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define N 5
#define D 10

int main(){
    double img[N][D]; // 2d array to store image data
    int classes[N]; // array to store image class labels
    double weights[D]; // array to store weights for classification
    int iterations = 1000; // number of training iterations
    double learning_rate = 0.01; // learning rate for the gradient descent algorithm

    // loop to read image data and class labels from a file
    for(int i=0; i<N; i++){
        for(int j=0; j<D; j++){
            scanf("%lf", &img[i][j]);
        }
        scanf("%d", &classes[i]);
    }

    // initializing the weights randomly
    for(int i=0; i<D; i++){
        weights[i] = (double)rand() / RAND_MAX;
    }

    // training the classifier using gradient descent algorithm
    for(int i=0; i<iterations; i++){
        double sum_gradient[D] = {0}; // array to sum the gradients of each training example
        for(int j=0; j<N; j++){
            double dot_product = 0; // calculating the dot product of weights and image data
            for(int k=0; k<D; k++){
                dot_product += weights[k] * img[j][k];
            }
            double prob = 1 / (1 + exp(-dot_product)); // calculating the probability of image belonging to class 1
            double gradient[D]; // array to store the gradient for each weight
            for(int k=0; k<D; k++){
                gradient[k] = (classes[j] - prob) * img[j][k]; // calculating the gradient for each weight
                sum_gradient[k] += gradient[k]; // adding the gradient to the sum
            }
        }
        for(int j=0; j<D; j++){
            weights[j] += learning_rate * sum_gradient[j]; // updating the weights using the sum of gradients
        }
    }

    // testing the classifier on a new image
    double test_img[D] = {0.5, 0.2, 0.1, 0.3, 0.7, 0.6, 0.9, 0.8, 0.4, 0.5};
    double dot_product = 0;
    for(int i=0; i<D; i++){
        dot_product += weights[i] * test_img[i];
    }
    double test_prob = 1 / (1 + exp(-dot_product));

    // outputting the results
    printf("The probability of the test image belonging to class 1 is: %f", test_prob);

    return 0;
}