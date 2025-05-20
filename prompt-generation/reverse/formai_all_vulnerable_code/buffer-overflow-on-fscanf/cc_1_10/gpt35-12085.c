//FormAI DATASET v1.0 Category: Image Classification system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_FILENAME_LEN 100
#define MAX_NUM_IMAGES 100
#define IMAGE_WIDTH 28
#define IMAGE_HEIGHT 28

// Define structs
typedef struct Image {
    char filename[MAX_FILENAME_LEN];
    int label;
    int pixels[IMAGE_WIDTH][IMAGE_HEIGHT];
} Image;

typedef struct Dataset {
    int num_images;
    Image images[MAX_NUM_IMAGES];
} Dataset;

// Define functions
int read_image(char* filename, int pixels[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    // Read image file and fill in pixels array
    // Return 0 if successful, -1 if file not found
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            fscanf(fp, "%d", &pixels[i][j]);
        }
    }
    fclose(fp);
    return 0;
}

Dataset create_dataset(char* image_dir) {
    // Create a dataset from a directory of image files
    Dataset dataset;
    dataset.num_images = 0;
    char filepath[MAX_FILENAME_LEN];
    for (int i = 0; i < MAX_NUM_IMAGES; i++) {
        sprintf(filepath, "%s%d.txt", image_dir, i+1);
        int status = read_image(filepath, dataset.images[i].pixels);
        if (status == -1) {
            break;
        }
        dataset.num_images++;
        strcpy(dataset.images[i].filename, filepath);
    }
    return dataset;
}

bool is_equal(int A[IMAGE_WIDTH][IMAGE_HEIGHT], int B[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    // Compare two images pixel by pixel
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int classify_image(Image image, Dataset training_set) {
    // Classify an image by finding the image in the training set with the most similar pixels
    int best_match_idx = -1;
    int best_match_score = -1;
    for (int i = 0; i < training_set.num_images; i++) {
        int score = 0;
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            for (int k = 0; k < IMAGE_WIDTH; k++) {
                if (image.pixels[j][k] == training_set.images[i].pixels[j][k]) {
                    score++;
                }
            }
        }
        if (score > best_match_score) {
            best_match_score = score;
            best_match_idx = i;
        }
    }
    return training_set.images[best_match_idx].label;
}

int main() {
    // Use the classification system
    Dataset training_set = create_dataset("data/training/");
    Dataset test_set = create_dataset("data/test/");
    int correct_predictions = 0;
    for (int i = 0; i < test_set.num_images; i++) {
        Image test_image = test_set.images[i];
        int predicted_label = classify_image(test_image, training_set);
        printf("%s was predictied to be %d\n", test_image.filename, predicted_label);
        if (predicted_label == test_image.label) {
            correct_predictions++;
        }
    }
    printf("Accuracy: %.2f%%\n", 100 * (double) correct_predictions / test_set.num_images);
    return 0;
}