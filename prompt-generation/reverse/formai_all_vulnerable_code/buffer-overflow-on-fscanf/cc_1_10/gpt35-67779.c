//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Define constants for image dimensions and maximum pixel value
#define HEIGHT 480
#define WIDTH 640
#define MAX_PIXEL 255

// Function prototypes
void load_image(char* filename, int img[HEIGHT][WIDTH]);
void save_image(char* filename, int img[HEIGHT][WIDTH]);
void invert_image(int img[HEIGHT][WIDTH]);
void brighten_image(int img[HEIGHT][WIDTH], int brightness);
void sharpen_image(int img[HEIGHT][WIDTH]);

int main()
{
    // Declare an image array with the dimensions specified by the constants
    int image[HEIGHT][WIDTH];

    // Load an image file into the array
    load_image("input.pgm", image);

    // Invert the colors of the image
    invert_image(image);

    // Brighten the image by adding 50 to each pixel value
    brighten_image(image, 50);

    // Sharpen the image by applying a convolution filter
    sharpen_image(image);

    // Save the modified image as a new file
    save_image("output.pgm", image);

    return 0;
}

// Function to load an image file into a 2D array
void load_image(char* filename, int img[HEIGHT][WIDTH])
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file); // Read and discard the first line (magic number)
    fgets(buffer, sizeof(buffer), file); // Read and discard the second line (image dimensions)
    fgets(buffer, sizeof(buffer), file); // Read and discard the third line (maximum pixel value)
    
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            int value;
            if (fscanf(file, "%d", &value) != 1)
            {
                perror("Error reading pixel value");
                exit(EXIT_FAILURE);
            }
            img[i][j] = value;
        }
    }

    fclose(file);
}

// Function to save a 2D array as an image file
void save_image(char* filename, int img[HEIGHT][WIDTH])
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    fprintf(file, "%d\n", MAX_PIXEL);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            fprintf(file, "%d ", img[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to invert the colors of an image
void invert_image(int img[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            img[i][j] = MAX_PIXEL - img[i][j];
        }
    }
}

// Function to brighten an image by adding a constant value to each pixel
void brighten_image(int img[HEIGHT][WIDTH], int brightness)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            img[i][j] = img[i][j] + brightness;
            if (img[i][j] > MAX_PIXEL)
            {
                img[i][j] = MAX_PIXEL;
            }
        }
    }
}

// Function to sharpen an image using a convolution filter
void sharpen_image(int img[HEIGHT][WIDTH])
{
    int kernel[3][3] = {{-1, -1, -1},
                        {-1, 9, -1},
                        {-1, -1, -1}};

    int temp[HEIGHT][WIDTH];

    for (int i = 1; i < HEIGHT-1; i++)
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            int sum = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    sum += img[i+x][j+y] * kernel[x+1][y+1];
                }
            }
            if (sum > MAX_PIXEL)
            {
                temp[i][j] = MAX_PIXEL;
            }
            else if (sum < 0)
            {
                temp[i][j] = 0;
            }
            else
            {
                temp[i][j] = sum;
            }
        }
    }

    for (int i = 1; i < HEIGHT-1; i++)
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            img[i][j] = temp[i][j];
        }
    }
}