#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    unsigned char *img_data;
    int img_size;

    // Open image file
    fp = fopen("image.jpg", "r");
    if (fp == NULL)
    {
        return 1;
    }

    // Get image size
    img_size = fread(img_data, 1, 100000, fp);
    fclose(fp);

    // Allocate memory for image data
    img_data = (unsigned char *)malloc(img_size);

    // Read image data from file
    fp = fopen("image.jpg", "r");
    fread(img_data, 1, img_size, fp);
    fclose(fp);

    // Out-of-bounds read vulnerability
    img_data[img_size + 10] = 0xdeadbeef;

    // Free memory
    free(img_data);

    return 0;
}
