//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel
{
    int r;
    int g;
    int b;
} pixel;

// Function to read in an image from a given file path
pixel** readImage(char* filepath, int* width, int* height)
{
    FILE *file = fopen(filepath, "rb");

    // Check if file open was successful
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // Read in image header information
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0)
    {
        printf("Invalid image format.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);

    // Allocate memory for pixels
    pixel** image = malloc((*height) * sizeof(pixel*));
    for (int i = 0; i < (*height); i++)
    {
        image[i] = malloc((*width) * sizeof(pixel));
    }

    // Read in pixel data
    for (int i = 0; i < (*height); i++)
    {
        for (int j = 0; j < (*width); j++)
        {
            fread(image[i] + j, sizeof(pixel), 1, file);
        }
    }

    // Close file and return image
    fclose(file);
    return image;
}

// Function to write an image to a given file path
void writeImage(char* filepath, pixel** image, int width, int height)
{
    FILE *file = fopen(filepath, "wb");

    // Check if file open was successful
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // Write image header information
    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    // Write pixel data
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fwrite(image[i] + j, sizeof(pixel), 1, file);
        }
    }

    // Close file
    fclose(file);
}

// Function to flip an image horizontally
void flipHorizontal(pixel** image, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            pixel temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(pixel** image, int width, int height, int amount)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].r += amount;
            image[i][j].g += amount;
            image[i][j].b += amount;

            // Ensure values are within valid range
            if (image[i][j].r > 255)
            {
                image[i][j].r = 255;
            }
            else if (image[i][j].r < 0)
            {
                image[i][j].r = 0;
            }

            if (image[i][j].g > 255)
            {
                image[i][j].g = 255;
            }
            else if (image[i][j].g < 0)
            {
                image[i][j].g = 0;
            }

            if (image[i][j].b > 255)
            {
                image[i][j].b = 255;
            }
            else if (image[i][j].b < 0)
            {
                image[i][j].b = 0;
            }
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(pixel** image, int width, int height, double amount)
{
    double factor = (259 * (amount + 255)) / (255 * (259 - amount));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].r = factor * (image[i][j].r - 128) + 128;
            image[i][j].g = factor * (image[i][j].g - 128) + 128;
            image[i][j].b = factor * (image[i][j].b - 128) + 128;

            // Ensure values are within valid range
            if (image[i][j].r > 255)
            {
                image[i][j].r = 255;
            }
            else if (image[i][j].r < 0)
            {
                image[i][j].r = 0;
            }

            if (image[i][j].g > 255)
            {
                image[i][j].g = 255;
            }
            else if (image[i][j].g < 0)
            {
                image[i][j].g = 0;
            }

            if (image[i][j].b > 255)
            {
                image[i][j].b = 255;
            }
            else if (image[i][j].b < 0)
            {
                image[i][j].b = 0;
            }
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 5)
    {
        printf("Usage: ./imageprocessing [inputfile] [outputfile] [brightness] [contrast]\n");
        exit(EXIT_FAILURE);
    }

    char* inputfile = argv[1];
    char* outputfile = argv[2];
    int brightness = atoi(argv[3]);
    double contrast = atof(argv[4]);

    int width, height;
    pixel** image = readImage(inputfile, &width, &height);

    // Apply image processing operations
    flipHorizontal(image, width, height);
    adjustBrightness(image, width, height, brightness);
    adjustContrast(image, width, height, contrast);

    writeImage(outputfile, image, width, height);

    // Free memory
    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}