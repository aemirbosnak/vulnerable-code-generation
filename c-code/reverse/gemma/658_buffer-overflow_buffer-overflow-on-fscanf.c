#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    unsigned char img_data[1024];
    int img_size;

    fp = fopen("image.pgm", "r");
    fscanf(fp, "%d", &img_size);

    fscanf(fp, "%s", img_data);

    // Brightness and contrast adjustments
    for (int i = 0; i < img_size; i++)
    {
        img_data[i] = (img_data[i] * 2) / 3;
    }

    // Image flipping
    int i = 0;
    for (int j = img_size - 1; j >= 0; j--)
    {
        img_data[i] = img_data[j];
        i++;
    }

    fclose(fp);

    return 0;
}
