//FormAI DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_SIZE 50 // Assumes every image is 50x50 pixels
#define THRESHOLD 0.5 // Threshold for deciding whether an image is a cat or not

int main() {
    printf("Welcome to the Cat or Not Cat Image Classification System!\n");
    printf("Please enter the file name of the image you would like to classify: ");
    char filename[100];
    scanf("%s", filename);
    
    double image[IMG_SIZE][IMG_SIZE];
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }
    
    // Read in the image data
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            fscanf(file, "%lf", &image[i][j]);
        }
    }
    fclose(file);
    
    // Normalize the pixel values
    double sum = 0.0;
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            sum += image[i][j];
        }
    }
    double avg = sum / (IMG_SIZE * IMG_SIZE);
    double variance = 0.0;
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            variance += pow((image[i][j] - avg), 2);
        }
    }
    variance /= (IMG_SIZE * IMG_SIZE);
    double stddev = sqrt(variance);
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            image[i][j] = (image[i][j] - avg) / stddev;
        }
    }
    
    // Classify the image as a cat or not cat
    double score = 0.0;
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            score += image[i][j];
        }
    }
    score /= (IMG_SIZE * IMG_SIZE);
    if (score > THRESHOLD) {
        printf("This is a cat image!\n");
    } else {
        printf("This is not a cat image.\n");
    }
    
    return 0;
}