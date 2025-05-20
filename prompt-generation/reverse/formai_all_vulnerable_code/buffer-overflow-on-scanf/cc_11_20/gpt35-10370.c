//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

int main()
{
    char input_filename[50];
    char output_filename[50];
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int flipped_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int brightness_adjustment;
    float contrast_adjustment;
    int image_width, image_height;

    printf("Welcome to C Basic Image Processing!\n");

    // Input image file name
    printf("Enter input image file name: ");
    scanf("%s", input_filename);

    // Output image file name
    printf("Enter output image file name: ");
    scanf("%s", output_filename);

    // Read image file into memory
    FILE *input_file_ptr = fopen(input_filename, "r");
    if (input_file_ptr == NULL)
    {
        printf("Error opening input image file. Exiting...\n");
        return 1;
    }
    fscanf(input_file_ptr, "%d %d", &image_width, &image_height);
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            fscanf(input_file_ptr, "%d", &image[i][j]);
        }
    }
    fclose(input_file_ptr);

    // Flipping image
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            flipped_image[image_height - i - 1][j] = image[i][j];
        }
    }

    // Changing brightness
    printf("Enter brightness adjustment (0 to 255): ");
    scanf("%d", &brightness_adjustment);
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            image[i][j] += brightness_adjustment;
            if (image[i][j] > 255)
            {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0)
            {
                image[i][j] = 0;
            }
        }
    }

    // Changing contrast
    printf("Enter contrast adjustment (0.1 to 10.0): ");
    scanf("%f", &contrast_adjustment);
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            image[i][j] = (int)((image[i][j] - 127.5) * contrast_adjustment + 127.5);
            if (image[i][j] > 255)
            {
                image[i][j] = 255;
            }
            else if (image[i][j] < 0)
            {
                image[i][j] = 0;
            }
        }
    }

    // Output processed image to file
    FILE *output_file_ptr = fopen(output_filename, "w");
    if (output_file_ptr == NULL)
    {
        printf("Error opening output image file. Exiting...\n");
        return 1;
    }
    fprintf(output_file_ptr, "%d %d\n", image_width, image_height);
    for (int i = 0; i < image_height; i++)
    {
        for (int j = 0; j < image_width; j++)
        {
            fprintf(output_file_ptr, "%d ", image[i][j]);
        }
        fprintf(output_file_ptr, "\n");
    }
    fclose(output_file_ptr);

    printf("Image processing complete! Output file: %s\n", output_filename);

    return 0;
}