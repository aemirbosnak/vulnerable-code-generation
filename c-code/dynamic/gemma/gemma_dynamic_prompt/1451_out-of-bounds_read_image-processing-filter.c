#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int image_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pixel_offset = 12;

    // Accessing pixel beyond the bounds of the image data array
    int pixel_value = image_data[pixel_offset];

    // Printing the pixel value
    printf("Pixel value at offset %d: %d\n", pixel_offset, pixel_value);

    return 0;
}
