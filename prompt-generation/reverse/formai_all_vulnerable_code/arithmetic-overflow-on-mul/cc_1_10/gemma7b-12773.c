//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Declare variables
    int width, height, pixel, x, y, r, g, b, a;
    unsigned char *image;

    // Allocate memory for the image
    image = (unsigned char *)malloc(width * height * 4);

    // Get the image width and height
    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Create the image
    image = (unsigned char *)malloc(width * height * 4);

    // Set the pixel values
    printf("Enter the pixel values (r, g, b, a): ");
    scanf("%d, %d, %d, %d", &r, &g, &b, &a);

    // Loop over the image pixels
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            pixel = image[x * height * 4 + y * 4] = r;
            image[x * height * 4 + y * 4 + 1] = g;
            image[x * height * 4 + y * 4 + 2] = b;
            image[x * height * 4 + y * 4 + 3] = a;
        }
    }

    // Display the image
    printf("Your image:\n");
    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++)
        {
            printf("%c ", image[x * height * 4 + y * 4]);
        }
        printf("\n");
    }

    // Free the memory
    free(image);
}