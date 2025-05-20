//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int width;
    int height;
    unsigned char *data;
} IMAGE;

IMAGE* read_image(const char *filename)
{
    FILE *f;
    IMAGE *img;

    if ((f = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Error: Could not open image file %s\n", filename);
        return NULL;
    }

    img = (IMAGE*)malloc(sizeof(IMAGE));
    img->data = NULL;

    fseek(f, 18, SEEK_SET);
    fread(&img->width, sizeof(int), 1, f);
    fread(&img->height, sizeof(int), 1, f);
    fseek(f, 54, SEEK_SET);

    img->data = (unsigned char*)malloc(img->width * img->height * 3);

    if (img->data == NULL)
    {
        fprintf(stderr, "Error: Could not allocate memory for image data\n");
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(unsigned char), img->width * img->height * 3, f);
    fclose(f);

    return img;
}

void write_image(const char *filename, IMAGE *img)
{
    FILE *f;
    int file_size;

    if ((f = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "Error: Could not open image file %s\n", filename);
        return;
    }

    file_size = 54 + img->width * img->height * 3;

    fputc('B', f);
    fputc('M', f);
    fwrite(&file_size, sizeof(int), 1, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);
    fwrite("\x36\0\0\0", sizeof(char), 4, f);
    fwrite("\x28\0\0\0", sizeof(char), 4, f);
    fwrite(&img->width, sizeof(int), 1, f);
    fwrite(&img->height, sizeof(int), 1, f);
    fwrite("\x01\0\x18\0", sizeof(char), 4, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);
    fwrite(&file_size, sizeof(int), 1, f);
    fwrite("\x13\0\0\0", sizeof(char), 4, f);
    fwrite("\x13\0\0\0", sizeof(char), 4, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);
    fwrite("\0\0\0\0", sizeof(char), 4, f);

    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, f);

    fclose(f);
}

void flip_image_horizontally(IMAGE *img)
{
    int i, j;
    unsigned char tmp;

    for (j = 0; j < img->height; ++j)
    {
        for (i = 0; i < img->width / 2; ++i)
        {
            tmp = img->data[j * img->width * 3 + i * 3];
            img->data[j * img->width * 3 + i * 3] = img->data[j * img->width * 3 + (img->width - i - 1) * 3];
            img->data[j * img->width * 3 + (img->width - i - 1) * 3] = tmp;

            tmp = img->data[j * img->width * 3 + i * 3 + 1];
            img->data[j * img->width * 3 + i * 3 + 1] = img->data[j * img->width * 3 + (img->width - i - 1) * 3 + 1];
            img->data[j * img->width * 3 + (img->width - i - 1) * 3 + 1] = tmp;

            tmp = img->data[j * img->width * 3 + i * 3 + 2];
            img->data[j * img->width * 3 + i * 3 + 2] = img->data[j * img->width * 3 + (img->width - i - 1) * 3 + 2];
            img->data[j * img->width * 3 + (img->width - i - 1) * 3 + 2] = tmp;
        }
    }
}

int main(int argc, char **argv)
{
    IMAGE *img;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    img = read_image(argv[1]);

    if (img == NULL)
    {
        return 1;
    }

    flip_image_horizontally(img);

    write_image("flipped.bmp", img);

    free(img->data);
    free(img);

    return 0;
}