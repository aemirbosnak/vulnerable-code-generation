#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Allocate memory for an image
    int *image = (int *)malloc(1024);

    // Initialize the image with some data
    for(int i = 0; i < 1024; i++)
    {
        image[i] = i + 1;
    }

    // Apply a filter to the image
    for(int i = 0; i < 1024; i++)
    {
        image[i] = image[i] * 2;
    }

    // Print the image
    for(int i = 0; i < 1024; i++)
    {
        printf("%d ", image[i]);
    }

    // Free the memory allocated for the image
    free(image);

    return 0;
}
