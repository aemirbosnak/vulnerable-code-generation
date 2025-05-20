#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* image_data = NULL;
    image_data = (int*)malloc(10 * sizeof(int));
    if (image_data == NULL)
    {
        return 1;
    }

    image_data[5] = 255;
    free(image_data);

    return 0;
}
