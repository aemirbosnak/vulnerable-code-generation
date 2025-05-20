#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned char *img_data = (unsigned char *)malloc(100);
    img_data[0] = 255;
    img_data[1] = 0;
    img_data[2] = 0;
    img_data[3] = 255;

    printf("Original image data:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("%u ", img_data[i]);
    }

    printf("\nModified image data (out-of-bounds write):\n");
    img_data[-1] = 100;
    for(int i = 0; i < 4; i++)
    {
        printf("%u ", img_data[i]);
    }

    free(img_data);

    return 0;
}
