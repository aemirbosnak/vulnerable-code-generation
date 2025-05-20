//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>

#define HEIGHT 200
#define WIDTH 200

// Function to invert the RGB values of a pixel 
void invertPixel(unsigned char *R, unsigned char *G, unsigned char *B)
{
    *R = 255 - *R;
    *G = 255 - *G;
    *B = 255 - *B;
}

// Function to invert the colors of an image by iterating over each pixel
void invertColors(unsigned char image[][WIDTH][3])
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            invertPixel(&image[i][j][0], &image[i][j][1], &image[i][j][2]);
        }
    }
}

int main(void)
{
    // Open the image file
    FILE *imageFile = fopen("example_image.ppm", "rb");

    if(imageFile == NULL)
    {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the image data
    int imageType;
    fscanf(imageFile, "P%d\n", &imageType);
    fscanf(imageFile, "%*[^\n]\n");
    fscanf(imageFile, "%*[^\n]\n");
    fscanf(imageFile, "%*[^\n]\n");

    unsigned char image[HEIGHT][WIDTH][3];

    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            fscanf(imageFile, "%hhu", &image[i][j][0]);
            fscanf(imageFile, "%hhu", &image[i][j][1]);
            fscanf(imageFile, "%hhu", &image[i][j][2]);
        }
    }

    // Invert the colors of the image
    invertColors(image);

    // Create new file to save the inverted image
    FILE *invertedImageFile = fopen("inverted_image.ppm", "wb");

    if(invertedImageFile == NULL)
    {
        printf("Error creating inverted image file.\n");
        return 1;
    }

    // Copy the header data from the original image file
    fprintf(invertedImageFile, "P%d\n", imageType);
    fprintf(invertedImageFile, "%d %d\n", WIDTH, HEIGHT);
    fprintf(invertedImageFile, "255\n");

    // Write the inverted image data to the new file
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            fprintf(invertedImageFile, "%hhu ", image[i][j][0]);
            fprintf(invertedImageFile, "%hhu ", image[i][j][1]);
            fprintf(invertedImageFile, "%hhu ", image[i][j][2]);
        }
        fprintf(invertedImageFile, "\n");
    }

    // Close both files
    fclose(imageFile);
    fclose(invertedImageFile);

    printf("Inverted image created successfully.\n");

    return 0;
}