#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int image_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int width = 3;
    int height = 2;

    // Allocate memory for the image
    int *image = (int *)malloc(height * width * sizeof(int));

    // Copy the image data into the allocated memory
    memcpy(image, image_data, height * width * sizeof(int));

    // Free the memory allocated for the image
    free(image);

    return 0;
}
