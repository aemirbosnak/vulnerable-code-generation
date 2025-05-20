#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *image_data = NULL;
    image_data = (int *)malloc(10 * sizeof(int));

    // Vulnerable code - dereference failure
    image_data[10] = 255;

    free(image_data);
    return 0;
}
