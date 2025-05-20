//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char r, g, b;
} pixel_t;

typedef struct
{
    pixel_t *pixels;
    size_t width;
    size_t height;
} bitmap_t;

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

void bitmap_write(bitmap_t *bitmap, const char *filename)
{
    FILE *fout = fopen(filename, "wb");
    fwrite("BM", 1, 2, fout);
    int offset = 54;
    int padding = 0;
    int filesize = offset + (bitmap->width * 3 + padding) * bitmap->height;
    fwrite(&filesize, sizeof(int), 1, fout);
    fwrite("\0\0\0\0", sizeof(int), 1, fout);
    fwrite(&offset, sizeof(int), 1, fout);
    int headersize = 40;
    fwrite(&headersize, sizeof(int), 1, fout);
    fwrite(&bitmap->width, sizeof(int), 1, fout);
    fwrite(&bitmap->height, sizeof(int), 1, fout);
    short planes = 1;
    fwrite(&planes, sizeof(short), 1, fout);
    short bits = 24;
    fwrite(&bits, sizeof(short), 1, fout);
    fwrite("\0\0\0\0", sizeof(int), 1, fout);
    int pixelsize = (bitmap->width * 3 + padding) * bitmap->height;
    unsigned char *pixeldata = (unsigned char*) malloc(pixelsize);
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            pixeldata[(i * bitmap->width + j) * 3] = bitmap->pixels[i * bitmap->width + j].b;
            pixeldata[(i * bitmap->width + j) * 3 + 1] = bitmap->pixels[i * bitmap->width + j].g;
            pixeldata[(i * bitmap->width + j) * 3 + 2] = bitmap->pixels[i * bitmap->width + j].r;
        }
        for (j = 0; j < padding; j++)
        {
            pixeldata[(i * bitmap->width * 3) + (bitmap->width * 3 + j)] = 0;
        }
    }
    fwrite(pixeldata, 1, pixelsize, fout);
    fclose(fout);
}

bitmap_t *bitmap_create(size_t width, size_t height)
{
    bitmap_t *bitmap = (bitmap_t*) malloc(sizeof(bitmap_t));
    if (!bitmap)
    {
        return NULL;
    }
    bitmap->pixels = (pixel_t*) calloc(width * height, sizeof(pixel_t));
    if (!bitmap->pixels)
    {
        free(bitmap);
        return NULL;
    }
    bitmap->width = width;
    bitmap->height = height;
    return bitmap;
}

void bitmap_destroy(bitmap_t *bitmap)
{
    free(bitmap->pixels);
    free(bitmap);
}

bitmap_t *bitmap_read(const char *filename)
{
    FILE *fin = fopen(filename, "rb");
    if (!fin)
    {
        return NULL;
    }
    unsigned char header[54], *data;
    fread(header, sizeof(unsigned char), 54, fin);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    int pixelsize = (width * 3 + padding) * height;
    data = (unsigned char*) malloc(pixelsize);
    fread(data, sizeof(unsigned char), pixelsize, fin);
    fclose(fin);
    bitmap_t *bitmap = bitmap_create(width, height);
    if (!bitmap)
    {
        free(data);
        return NULL;
    }
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            bitmap->pixels[i * bitmap->width + j].r = data[(i * (bitmap->width * 3 + padding)) + (j * 3) + 2];
            bitmap->pixels[i * bitmap->width + j].g = data[(i * (bitmap->width * 3 + padding)) + (j * 3) + 1];
            bitmap->pixels[i * bitmap->width + j].b = data[(i * (bitmap->width * 3 + padding)) + (j * 3)];
        }
    }
    free(data);
    return bitmap;
}

void bitmap_grayscale(bitmap_t *bitmap)
{
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            pixel_t *pixel = &bitmap->pixels[i * bitmap->width + j];
            unsigned char gray = 0.3 * pixel->r + 0.59 * pixel->g + 0.11 * pixel->b;
            pixel->r = gray;
            pixel->g = gray;
            pixel->b = gray;
        }
    }
}

void bitmap_flip_horizontal(bitmap_t *bitmap)
{
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width / 2; j++)
        {
            pixel_t temp = bitmap->pixels[i * bitmap->width + j];
            bitmap->pixels[i * bitmap->width + j] = bitmap->pixels[i * bitmap->width + bitmap->width - j - 1];
            bitmap->pixels[i * bitmap->width + bitmap->width - j - 1] = temp;
        }
    }
}

void bitmap_flip_vertical(bitmap_t *bitmap)
{
    int i, j;
    for (i = 0; i < bitmap->height / 2; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            pixel_t temp = bitmap->pixels[i * bitmap->width + j];
            bitmap->pixels[i * bitmap->width + j] = bitmap->pixels[(bitmap->height - i - 1) * bitmap->width + j];
            bitmap->pixels[(bitmap->height - i - 1) * bitmap->width + j] = temp;
        }
    }
}

void bitmap_invert(bitmap_t *bitmap)
{
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            bitmap->pixels[i * bitmap->width + j].r = 255 - bitmap->pixels[i * bitmap->width + j].r;
            bitmap->pixels[i * bitmap->width + j].g = 255 - bitmap->pixels[i * bitmap->width + j].g;
            bitmap->pixels[i * bitmap->width + j].b = 255 - bitmap->pixels[i * bitmap->width + j].b;
        }
    }
}

void bitmap_adjust_brightness(bitmap_t *bitmap, int level)
{
    int i, j;
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            bitmap->pixels[i * bitmap->width + j].r = maximum(0, minimum(255, bitmap->pixels[i * bitmap->width + j].r + level));
            bitmap->pixels[i * bitmap->width + j].g = maximum(0, minimum(255, bitmap->pixels[i * bitmap->width + j].g + level));
            bitmap->pixels[i * bitmap->width + j].b = maximum(0, minimum(255, bitmap->pixels[i * bitmap->width + j].b + level));
        }
    }
}

void bitmap_adjust_contrast(bitmap_t *bitmap, float level)
{
    int i, j;
    float factor = (259.0 * (level + 255.0)) / (255.0 * (259.0 - level));
    for (i = 0; i < bitmap->height; i++)
    {
        for (j = 0; j < bitmap->width; j++)
        {
            bitmap->pixels[i * bitmap->width + j].r = maximum(0, minimum(255, (int)(factor * (bitmap->pixels[i * bitmap->width + j].r - 128) + 128)));
            bitmap->pixels[i * bitmap->width + j].g = maximum(0, minimum(255, (int)(factor * (bitmap->pixels[i * bitmap->width + j].g - 128) + 128)));
            bitmap->pixels[i * bitmap->width + j].b = maximum(0, minimum(255, (int)(factor * (bitmap->pixels[i * bitmap->width + j].b - 128) + 128)));
        }
    }
}

int main()
{
    bitmap_t *bitmap = bitmap_read("input.bmp");
    if (!bitmap)
    {
        return 1;
    }
    bitmap_grayscale(bitmap);
    bitmap_flip_horizontal(bitmap);
    bitmap_flip_vertical(bitmap);
    bitmap_invert(bitmap);
    bitmap_adjust_brightness(bitmap, 50);
    bitmap_adjust_contrast(bitmap, 50);
    bitmap_write(bitmap, "output.bmp");
    bitmap_destroy(bitmap);
    return 0;
}