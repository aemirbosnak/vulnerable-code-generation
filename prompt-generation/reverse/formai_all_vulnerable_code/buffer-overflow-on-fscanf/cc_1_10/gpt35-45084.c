//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Function to read the input image
void read_image(char filename[], int image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height)
{
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d %d", width, height);

    for (int i = 0; i < *height; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);
}

// Function to print the ASCII art image
void print_ascii_art(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j] < 50)
            {
                printf(" ");
            }
            else if (image[i][j] < 100)
            {
                printf(".");
            }
            else if (image[i][j] < 150)
            {
                printf(":");
            }
            else if (image[i][j] < 200)
            {
                printf("o");
            }
            else if (image[i][j] < 250)
            {
                printf("&");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the image array
    int image[MAX_HEIGHT][MAX_WIDTH];

    // Read the input image into the array
    int width, height;
    read_image("input.txt", image, &width, &height);

    // Print the ASCII art version of the image
    print_ascii_art(image, width, height);

    return 0;
}