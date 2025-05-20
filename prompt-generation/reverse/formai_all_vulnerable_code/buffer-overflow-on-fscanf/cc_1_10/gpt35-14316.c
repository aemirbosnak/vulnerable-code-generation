//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Defining the required constants
#define NUM_CLASSES 5
#define MAX_SAMPLES 100
#define NUM_FEATURES 10

// Function to read data from file
void readDataFromFile(float data[MAX_SAMPLES][NUM_FEATURES], int labels[MAX_SAMPLES], char* file_path) {
    FILE* fp = fopen(file_path, "r");
    if(fp == NULL) {
        printf("Error in opening file %s!\n", file_path);
        exit(1);
    }
    int i = 0;
    while(i < MAX_SAMPLES && fscanf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &data[i][4], &data[i][5], &data[i][6], &data[i][7], &data[i][8], &data[i][9], &labels[i]) != EOF) {
        i++;
    }
    fclose(fp);
}

// Function to classify input image
int classifyImage(float* input_img, float mean_images[NUM_CLASSES][NUM_FEATURES], float cov_images[NUM_CLASSES][NUM_FEATURES][NUM_FEATURES], float prior[NUM_CLASSES]) {
    float max_prob = 0.0;
    int max_class = 0;
    for(int i=0;i<NUM_CLASSES;i++) {
        float s[NUM_FEATURES];
        for(int j=0;j<NUM_FEATURES;j++) {
            s[j] = input_img[j] - mean_images[i][j];
        }
        float prob = 0.0;
        for(int j=0;j<NUM_FEATURES;j++) {
            for(int k=0;k<NUM_FEATURES;k++) {
                prob += s[j] * s[k] * cov_images[i][j][k];
            }
        }
        prob = -0.5 * prob;
        prob = prob - 0.5 * NUM_FEATURES * log(2*3.14);
        prob = prob + log(prior[i]);
        if(prob > max_prob) {
            max_prob = prob;
            max_class = i;
        }
    }
    return max_class;
}

int main() {
    // Read the input data from file
    float data[MAX_SAMPLES][NUM_FEATURES];
    int labels[MAX_SAMPLES];
    char* file_path = "sample_dataset.txt";
    readDataFromFile(data, labels, file_path);

    // Train the model using data
    float prior[NUM_CLASSES] = {0.0};
    float mean_images[NUM_CLASSES][NUM_FEATURES] = {{0.0}};
    float cov_images[NUM_CLASSES][NUM_FEATURES][NUM_FEATURES] = {{{0.0}}};
    int num_samples[NUM_CLASSES] = {0};
    for(int i=0;i<MAX_SAMPLES;i++) {
        int label = labels[i];
        num_samples[label]++;
        prior[label]++;
        for(int j=0;j<NUM_FEATURES;j++) {
            mean_images[label][j] += data[i][j];
        }
    }
    for(int i=0;i<NUM_CLASSES;i++) {
        for(int j=0;j<NUM_FEATURES;j++) {
            mean_images[i][j] /= num_samples[i];
        }
        for(int j=0;j<MAX_SAMPLES;j++) {
            if(labels[j] == i) {
                float s[NUM_FEATURES];
                for(int k=0;k<NUM_FEATURES;k++) {
                    s[k] = data[j][k] - mean_images[i][k];
                }
                for(int k=0;k<NUM_FEATURES;k++) {
                    for(int l=0;l<NUM_FEATURES;l++) {
                        cov_images[i][k][l] += s[k] * s[l];
                    }
                }
            }
        }
        for(int j=0;j<NUM_FEATURES;j++) {
            for(int k=0;k<NUM_FEATURES;k++) {
                cov_images[i][j][k] /= num_samples[i];
            }
        }
        prior[i] /= MAX_SAMPLES;
    }

    // Test the model
    printf("Input a test image of size %dx%d:\n", NUM_FEATURES, 1);
    float input_img[NUM_FEATURES];
    for(int i=0;i<NUM_FEATURES;i++) {
        scanf("%f", &input_img[i]);
    }
    int predicted_class = classifyImage(input_img, mean_images, cov_images, prior);
    printf("Predicted class: %d\n", predicted_class);

    return 0;
}