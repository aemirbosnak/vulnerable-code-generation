#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y;
    int *img = (int *)malloc(1024 * 1024 * 3);

    for (i = 0; i < 1024; i++)
    {
        for (j = 0; j < 1024; j++)
        {
            img[i * 1024 * 3 + j * 3] = 255;
            img[i * 1024 * 3 + j * 3 + 1] = 255;
            img[i * 1024 * 3 + j * 3 + 2] = 255;
        }
    }

    free(img);
    return 0;
}
