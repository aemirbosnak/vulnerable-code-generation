#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int width = 3;
    int height = 2;

    // Write out of bounds
    img_data[width * height + 1] = 11;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d ", img_data[i * width + j]);
        }
        printf("\n");
    }

    return 0;
}
