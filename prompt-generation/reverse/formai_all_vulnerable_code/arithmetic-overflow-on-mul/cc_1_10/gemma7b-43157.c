//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct Image
{
    int width, height;
    unsigned char *data;
} Image;

Image *load_image(char *filename)
{
    Image *image = malloc(sizeof(Image));

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return NULL;
    }

    image->width = fread(&image->width, 1, sizeof(int), fp);
    image->height = fread(&image->height, 1, sizeof(int), fp);
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, 1, image->width * image->height * 3, fp);

    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        return;
    }

    fwrite(&image->width, 1, sizeof(int), fp);
    fwrite(&image->height, 1, sizeof(int), fp);
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    fclose(fp);
}

int main()
{
    Image *image = load_image("image.jpg");
    save_image(image, "image_edited.jpg");

    return 0;
}