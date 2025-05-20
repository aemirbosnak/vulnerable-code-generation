#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int image[1024] = {0};
    image[100] = 255;
    image[101] = 255;
    image[102] = 255;

    int i = 0;
    for (i = 0; i < 1024; i++)
    {
        if (image[i] > image[i-1])
        {
            image[i] = image[i-1];
        }
    }

    for (i = 0; i < 1024; i++)
    {
        printf("%d ", image[i]);
    }

    return 0;
}
