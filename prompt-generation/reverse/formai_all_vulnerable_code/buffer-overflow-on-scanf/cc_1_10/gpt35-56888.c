//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
// C Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast

#include <stdio.h>
#include <stdlib.h>

// Define constants for image size
#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000

// Define function prototypes for image processing operations
void flipImageHorizontally(int[][MAX_WIDTH], int, int);
void changeBrightness(int[][MAX_WIDTH], int, int, int);
void changeContrast(int[][MAX_WIDTH], int, int, int);

int main()
{
    int img[MAX_HEIGHT][MAX_WIDTH]; // Declare a 2D array to store the image
    int height, width, brightness, contrast; // Declare variables for user input

    // Get user input for image size
    printf("Enter the height of the image (maximum %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    printf("Enter the width of the image (maximum %d): ", MAX_WIDTH);
    scanf("%d", &width);

    // Get user input for image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("Enter the pixel value of image at row %d and column %d: ", i, j);
            scanf("%d", &img[i][j]);
        }
    }

    // Get user input for image processing operations
    printf("Enter the brightness level (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter the contrast level (-255 to 255): ");
    scanf("%d", &contrast);

    // Perform image processing operations on the image
    flipImageHorizontally(img, height, width);
    changeBrightness(img, height, width, brightness);
    changeContrast(img, height, width, contrast);

    // Print the processed image
    printf("\nProcessed Image:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to flip an image horizontally
void flipImageHorizontally(int img[][MAX_WIDTH], int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            int temp = img[i][j];
            img[i][j] = img[i][width-j-1];
            img[i][width-j-1] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(int img[][MAX_WIDTH], int height, int width, int brightness)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = img[i][j] + brightness;
            if (pixel < 0)
            {
                img[i][j] = 0;
            }
            else if (pixel > 255)
            {
                img[i][j] = 255;
            }
            else
            {
                img[i][j] = pixel;
            }
        }
    }
}

// Function to change the contrast of an image
void changeContrast(int img[][MAX_WIDTH], int height, int width, int contrast)
{
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel = factor * (img[i][j] - 128.0) + 128.0;
            if (pixel < 0)
            {
                img[i][j] = 0;
            }
            else if (pixel > 255)
            {
                img[i][j] = 255;
            }
            else
            {
                img[i][j] = pixel;
            }
        }
    }
}