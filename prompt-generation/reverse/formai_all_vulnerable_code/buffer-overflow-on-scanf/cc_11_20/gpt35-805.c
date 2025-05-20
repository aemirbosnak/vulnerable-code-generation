//FormAI DATASET v1.0 Category: Image Classification system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 4
#define IMG_SIZE 28

typedef struct {
    unsigned char pixel_data[IMG_SIZE][IMG_SIZE];
    unsigned char label;
} image_t;

typedef struct {
    double weights[NUM_CLASSES][IMG_SIZE * IMG_SIZE];
    double biases[NUM_CLASSES];
} model_t;

int main() {
    char filename[100];
    int num_images, image_idx, i, j, k, max_class_idx;
    double max_score, score;
    model_t my_model;
    image_t my_image;
    FILE *fp;

    // Load the model weights and biases
    fp = fopen("model_weights.bin", "rb");
    fread(&my_model, sizeof(model_t), 1, fp);
    fclose(fp);

    // Get user input for image filename
    printf("Enter filename of image to classify: ");
    scanf("%s", filename);

    // Load the image
    fp = fopen(filename, "rb");
    fread(&my_image, sizeof(image_t), 1, fp);
    fclose(fp);

    // Flatten the 2D image array into a 1D array
    double image_data[IMG_SIZE * IMG_SIZE];
    for (i = 0; i < IMG_SIZE; i++) {
        for (j = 0; j < IMG_SIZE; j++) {
            image_data[i * IMG_SIZE + j] = my_image.pixel_data[i][j];
        }
    }

    // Calculate the scores for each class
    double class_scores[NUM_CLASSES];
    for (i = 0; i < NUM_CLASSES; i++) {
        score = 0.0;
        for (j = 0; j < IMG_SIZE * IMG_SIZE; j++) {
            score += image_data[j] * my_model.weights[i][j];
        }
        score += my_model.biases[i];
        class_scores[i] = score;
    }

    // Find the highest scoring class
    max_score = class_scores[0];
    max_class_idx = 0;
    for (i = 1; i < NUM_CLASSES; i++) {
        if (class_scores[i] > max_score) {
            max_score = class_scores[i];
            max_class_idx = i;
        }
    }

    // Print the classification result in a post-apocalyptic message
    printf("The image depicts ");
    switch (max_class_idx) {
        case 0:
            printf("a mutant zombie. RUN FOR YOUR LIFE!");
            break;
        case 1:
            printf("a mutated plant. Do not touch it!");
            break;
        case 2:
            printf("a survivalist with a gun. Approach with caution.");
            break;
        case 3:
            printf("a post-apocalyptic car. It looks ready to move some supplies.");
            break;
        default:
            printf("something unrecognizable. The future is truly bleak.");
            break;
    }
    printf("\n");

    return 0;
}