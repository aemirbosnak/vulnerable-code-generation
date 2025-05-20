//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_IMAGE_SIZE 1024

// Function prototypes
void flip_image(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, int axis);
void adjust_brightness(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, int delta);
void adjust_contrast(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, float factor);

int main()
{
    char filename[MAX_FILENAME_LEN];
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int width, height, axis, delta;
    float factor;

    // Read input filename from user
    printf("Enter image filename: ");
    scanf("%s", filename);

    // Read image data from file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return 1;
    }
    fscanf(file, "%d %d", &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);

    // Prompt user to select an operation
    printf("Select an operation:\n");
    printf("[1] Flip Image\n");
    printf("[2] Adjust Brightness\n");
    printf("[3] Adjust Contrast\n");
    int choice = 0;
    scanf("%d", &choice);

    // Apply selected operation
    switch (choice) {
        case 1:
            printf("Enter axis (0 for vertical, 1 for horizontal): ");
            scanf("%d", &axis);
            flip_image(image, width, height, axis);
            break;
        case 2:
            printf("Enter delta (-255 to 255): ");
            scanf("%d", &delta);
            adjust_brightness(image, width, height, delta);
            break;
        case 3:
            printf("Enter factor (0.1 to 10.0): ");
            scanf("%f", &factor);
            adjust_contrast(image, width, height, factor);
            break;
        default:
            printf("Error: Invalid choice\n");
            return 1;
    }

    // Save modified image data to file
    char outputFilename[MAX_FILENAME_LEN];
    sprintf(outputFilename, "modified_%s", filename);
    file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", outputFilename);
        return 1;
    }
    fprintf(file, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    printf("Output saved to '%s'\n", outputFilename);
    return 0;
}

// Flip the image along the specified axis (0 for vertical, 1 for horizontal)
void flip_image(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, int axis)
{
    int temp[MAX_IMAGE_SIZE];
    if (axis == 0) {
        for (int i = 0; i < height / 2; i++) {
            memcpy(temp, image[i], width * sizeof(int));
            memcpy(image[i], image[height - i - 1], width * sizeof(int));
            memcpy(image[height - i - 1], temp, width * sizeof(int));
        }
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width / 2; j++) {
                int temp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = temp;
            }
        }
    }
}

// Adjust the brightness of the image by the given delta value (-255 to 255)
void adjust_brightness(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, int delta)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] += delta;
            image[i][j] = (image[i][j] < 0) ? 0 : ((image[i][j] > 255) ? 255 : image[i][j]);
        }
    }
}

// Adjust the contrast of the image by the given factor (0.1 to 10.0)
void adjust_contrast(int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], int width, int height, float factor)
{
    float mean = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mean += (float)image[i][j];
        }
    }
    mean /= (float)(width * height);

    float stdDev = 0.0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            stdDev += ((float)image[i][j] - mean) * ((float)image[i][j] - mean);
        }
    }
    stdDev /= (float)(width * height);
    stdDev = sqrtf(stdDev);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = (int)((float)image[i][j] * factor + (mean - factor * mean));
            image[i][j] = (image[i][j] < 0) ? 0 : ((image[i][j] > 255) ? 255 : image[i][j]);
        }
    }
}