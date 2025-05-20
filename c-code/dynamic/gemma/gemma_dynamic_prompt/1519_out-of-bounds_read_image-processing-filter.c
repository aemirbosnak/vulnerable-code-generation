#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int image_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pixel_value = image_data[100];
    printf("Pixel value at index 100: %d\n", pixel_value);
    return 0;
}
