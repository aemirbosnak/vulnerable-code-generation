//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned char R, G, B;
} Pixel;

typedef struct 
{
    int width, height;
    Pixel* data;
} Image;

void flip(Image* img)
{
    int i, j;
    Pixel temp;
    for (i = 0; i < img->height/2; i++)
    {
        for (j = 0; j < img->width; j++)
        {
            temp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[(img->height-1-i)*img->width+j];
            img->data[(img->height-1-i)*img->width+j] = temp;
        }
    }
}

void changeBrightness(Image* img, int brightness)
{
    int i;
    for (i = 0; i < img->width*img->height; i++)
    {
        img->data[i].R += brightness;
        if (img->data[i].R > 255) img->data[i].R = 255;
        if (img->data[i].R < 0) img->data[i].R = 0;
        img->data[i].G += brightness;
        if (img->data[i].G > 255) img->data[i].G = 255;
        if (img->data[i].G < 0) img->data[i].G = 0;
        img->data[i].B += brightness;
        if (img->data[i].B > 255) img->data[i].B = 255;
        if (img->data[i].B < 0) img->data[i].B = 0;
    }
}

void changeContrast(Image* img, int contrast)
{
    int i;
    float factor = (259.0f*(contrast+255.0f))/(255.0f*(259.0f-contrast));
    for (i = 0; i < img->width*img->height; i++)
    {
        img->data[i].R = factor*(img->data[i].R-128.0f)+128.0f;
        if (img->data[i].R > 255) img->data[i].R = 255;
        if (img->data[i].R < 0) img->data[i].R = 0;
        img->data[i].G = factor*(img->data[i].G-128.0f)+128.0f;
        if (img->data[i].G > 255) img->data[i].G = 255;
        if (img->data[i].G < 0) img->data[i].G = 0;
        img->data[i].B = factor*(img->data[i].B-128.0f)+128.0f;
        if (img->data[i].B > 255) img->data[i].B = 255;
        if (img->data[i].B < 0) img->data[i].B = 0;
    }
}

void saveImage(Image* img, char* filename)
{
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");
    fwrite(img->data, sizeof(Pixel), img->width*img->height, fp);
    fclose(fp);
}

Image* loadImage(char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return NULL;
    char type[2];
    int width, height, max_val;
    fscanf(fp, "%s\n%d %d\n%d\n", type, &width, &height, &max_val);
    if (type[0] != 'P' || type[1] != '6' || max_val != 255) return NULL;
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel*)malloc(sizeof(Pixel)*width*height);
    fread(img->data, sizeof(Pixel), width*height, fp);
    fclose(fp);
    return img;
}

int main(int argc, char** argv)
{
    Image* img = loadImage("input.ppm");
    if (img == NULL) 
    {
        printf("Failed to load image\n");
        return 1;
    }

    flip(img);
    changeBrightness(img, 50);
    changeContrast(img, 50);
    saveImage(img, "output.ppm");

    return 0;
}