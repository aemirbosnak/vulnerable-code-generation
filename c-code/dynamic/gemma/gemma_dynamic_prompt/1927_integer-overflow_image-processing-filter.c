#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
    int pixel_value = 1000000000;
    pixel_value = pixel_value * pixel_value;
    pixel_value = pixel_value / pixel_value;

    printf("The pixel value is: %d", pixel_value);
}
