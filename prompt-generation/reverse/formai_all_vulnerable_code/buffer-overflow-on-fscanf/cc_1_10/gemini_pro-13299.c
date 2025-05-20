//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the possible image classes
#define CAT 1
#define DOG 2
#define BIRD 3

// Define the size of the image data
#define IMAGE_SIZE 100

// Create a function to classify an image
int classify_image(int* image_data)
{
    // Check if the image contains a cat
    int cat_count = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        if (image_data[i] == CAT) {
            cat_count++;
        }
    }
    if (cat_count > 50) {
        return CAT;
    }

    // Check if the image contains a dog
    int dog_count = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        if (image_data[i] == DOG) {
            dog_count++;
        }
    }
    if (dog_count > 50) {
        return DOG;
    }

    // Check if the image contains a bird
    int bird_count = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        if (image_data[i] == BIRD) {
            bird_count++;
        }
    }
    if (bird_count > 50) {
        return BIRD;
    }

    // If the image does not contain any of the known classes, return -1
    return -1;
}

int main()
{
    // Create an array to store the image data
    int image_data[IMAGE_SIZE];

    // Read the image data from a file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < IMAGE_SIZE; i++) {
        fscanf(fp, "%d", &image_data[i]);
    }
    fclose(fp);

    // Classify the image
    int class = classify_image(image_data);

    // Print the classification result
    switch (class) {
        case CAT:
            printf("The image contains a cat.\n");
            break;
        case DOG:
            printf("The image contains a dog.\n");
            break;
        case BIRD:
            printf("The image contains a bird.\n");
            break;
        default:
            printf("The image could not be classified.\n");
    }

    return EXIT_SUCCESS;
}