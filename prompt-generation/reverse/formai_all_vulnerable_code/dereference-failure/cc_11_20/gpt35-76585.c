//FormAI DATASET v1.0 Category: Image Classification system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 5
#define MAX_FILENAME_LEN 100

int main() {

    char filenames[NUM_CLASSES][MAX_FILENAME_LEN] = {"cat.jpg", "dog.jpg", "bird.jpg", "fish.jpg", "rabbit.jpg"};
    int class_labels[NUM_CLASSES] = {1, 2, 3, 4, 5};
    
    // Load image data
    float *image_data = (float *)malloc(sizeof(float) * NUM_CLASSES * 100); // Dummy image data, assume each image has 100 features
    
    // Train the classifier
    float *model_weights = (float *)calloc(100 * NUM_CLASSES, sizeof(float));
    for (int i = 0; i < 100 * NUM_CLASSES; i++) {
        model_weights[i] = (float)rand() / RAND_MAX; // Random initialization
    }
    float learning_rate = 0.01;
    int num_iterations = 1000;
    for (int iter = 0; iter < num_iterations; iter++) {
        // Randomly select one training example
        int class_idx = rand() % NUM_CLASSES;
        int feature_idx = class_idx * 100 + rand() % 100;
        float y_true = class_labels[class_idx];
        // Calculate predicted score
        float *weights_ptr = model_weights + feature_idx;
        float score = 0;
        for (int i = 0; i < 100; i++) {
            score += image_data[class_idx * 100 + i] * weights_ptr[i];
        }
        // Gradient descent update
        float softmax[NUM_CLASSES];
        float sum_exp_scores = 0;
        for (int i = 0; i < NUM_CLASSES; i++) {
            softmax[i] = exp(model_weights[i * 100 + feature_idx] * image_data[feature_idx]);
            sum_exp_scores += softmax[i];
        }
        for (int i = 0; i < NUM_CLASSES; i++) {
            softmax[i] /= sum_exp_scores;
        }
        for (int i = 0; i < 100; i++) {
            weights_ptr[i] -= learning_rate * image_data[class_idx * 100 + i] * (softmax[class_idx] - y_true);
        }
    }
    
    // Test the classifier on some new images
    char test_filenames[3][MAX_FILENAME_LEN] = {"test1.jpg", "test2.jpg", "test3.jpg"};
    float *test_data = (float *)malloc(sizeof(float) * 3 * 100); // Dummy test data, assume each image has 100 features
    for (int i = 0; i < 3; i++) {
        // Load test image data
        // ...
        // Classify the image
        int max_class = 0;
        float max_score = -1;
        for (int c = 0; c < NUM_CLASSES; c++) {
            float *weights_ptr = model_weights + c * 100;
            float score = 0;
            for (int f = 0; f < 100; f++) {
                score += test_data[i * 100 + f] * weights_ptr[f];
            }
            if (score > max_score) {
                max_score = score;
                max_class = class_labels[c];
            }
        }
        printf("%s classified as class %d\n", test_filenames[i], max_class);
    }
    
    free(image_data);
    free(model_weights);
    free(test_data);
    return 0;
}