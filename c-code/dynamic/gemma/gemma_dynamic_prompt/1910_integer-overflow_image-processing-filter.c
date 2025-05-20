#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pixel_value = 214;
    int result = pixel_value * pixel_value;

    printf("Original pixel value: %d\n", pixel_value);
    printf("Result: %d\n", result);

    if (result > 255)
    {
        printf("Overflow!\n");
    }

    return 0;
}
