#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    unsigned char img_data[10000];
    int img_size;

    fp = fopen("image.pgm", "r");
    fscanf(fp, "%d", &img_size);
    fscanf(fp, "%s", img_data);
    fclose(fp);

    for (int i = 0; i < img_size; i++)
    {
        img_data[i] += 50;
    }

    fp = fopen("modified_image.pgm", "w");
    fprintf(fp, "PGM\n");
    fprintf(fp, "%d\n", img_size);
    fprintf(fp, "%s", img_data);
    fclose(fp);

    return 0;
}
