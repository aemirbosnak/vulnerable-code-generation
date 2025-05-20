//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct 
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} PIXEL;

typedef struct 
{
    PIXEL *pixels;
    size_t height;
    size_t width;
} IMAGE;

IMAGE *read_ppm(const char *file_name) 
{
    FILE *file = fopen(file_name, "rb");
    if (!file) 
    {
        fprintf(stderr, "Unable to open file %s\n", file_name);
        return NULL;
    }

    char magic[3];
    fscanf(file, "%2s", magic);

    if (magic[0] != 'P' || magic[1] != '6') 
    {
        fprintf(stderr, "Invalid PPM format\n");
        fclose(file);
        return NULL;
    }

    size_t width, height;
    fscanf(file, "%zu %zu", &width, &height);
    size_t max_value;
    fscanf(file, "%zu", &max_value);

    if (max_value != 255) 
    {
        fprintf(stderr, "Invalid PPM max value\n");
        fclose(file);
        return NULL;
    }

    IMAGE *image = malloc(sizeof(IMAGE));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(PIXEL)*width*height);

    for (size_t i = 0; i < height; ++i) 
    {
        for (size_t j = 0; j < width; ++j) 
        {
            PIXEL pixel;
            size_t size = fread(&pixel, 1, 3, file);
            if (size != 3) 
            {
                fprintf(stderr, "Error reading PPM pixel\n");
                fclose(file);
                free(image->pixels);
                free(image);
                return NULL;
            }
            image->pixels[i*width+j] = pixel;
        }
    }

    fclose(file);
    return image;
}

void write_ppm(const char *file_name, const IMAGE *image) 
{
    FILE *file = fopen(file_name, "wb");
    if (!file) 
    {
        fprintf(stderr, "Unable to open file %s\n", file_name);
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%zu %zu\n", image->width, image->height);
    fprintf(file, "255\n");

    for (size_t i = 0; i < image->height; ++i) 
    {
        for (size_t j = 0; j < image->width; ++j) 
        {
            fwrite(&image->pixels[i*image->width+j], 1, 3, file);
        }
    }

    fclose(file);
}

void flip_horizontal(IMAGE *image) 
{
    for (size_t i = 0; i < image->height; ++i) 
    {
        for (size_t j = 0; j < image->width/2; ++j) 
        {
            PIXEL temp = image->pixels[i*image->width+j];
            image->pixels[i*image->width+j] = image->pixels[i*image->width+image->width-1-j];
            image->pixels[i*image->width+image->width-1-j] = temp;
        }
    }
}

void flip_vertical(IMAGE *image) 
{
    for (size_t i = 0; i < image->height/2; ++i) 
    {
        for (size_t j = 0; j < image->width; ++j) 
        {
            PIXEL temp = image->pixels[i*image->width+j];
            image->pixels[i*image->width+j] = image->pixels[(image->height-1-i)*image->width+j];
            image->pixels[(image->height-1-i)*image->width+j] = temp;
        }
    }
}

void adjust_brightness(IMAGE *image, int16_t value) 
{
    for (size_t i = 0; i < image->height; ++i) 
    {
        for (size_t j = 0; j < image->width; ++j) 
        {
            int16_t r = image->pixels[i*image->width+j].red+value;
            r = r < 0 ? 0 : r > 255 ? 255 : r;
            image->pixels[i*image->width+j].red = r;

            int16_t g = image->pixels[i*image->width+j].green+value;
            g = g < 0 ? 0 : g > 255 ? 255 : g;
            image->pixels[i*image->width+j].green = g;

            int16_t b = image->pixels[i*image->width+j].blue+value;
            b = b < 0 ? 0 : b > 255 ? 255 : b;
            image->pixels[i*image->width+j].blue = b;
        }
    }
}

void adjust_contrast(IMAGE *image, float value) 
{
    float factor = (259.0f*(value+255.0f))/(255.0f*(259.0f-value));

    for (size_t i = 0; i < image->height; ++i) 
    {
        for (size_t j = 0; j < image->width; ++j) 
        {
            int16_t r = (int16_t)(factor*(image->pixels[i*image->width+j].red-128.0f)+128.0f);
            r = r < 0 ? 0 : r > 255 ? 255 : r;
            image->pixels[i*image->width+j].red = r;

            int16_t g = (int16_t)(factor*(image->pixels[i*image->width+j].green-128.0f)+128.0f);
            g = g < 0 ? 0 : g > 255 ? 255 : g;
            image->pixels[i*image->width+j].green = g;

            int16_t b = (int16_t)(factor*(image->pixels[i*image->width+j].blue-128.0f)+128.0f);
            b = b < 0 ? 0 : b > 255 ? 255 : b;
            image->pixels[i*image->width+j].blue = b;
        }
    }
}

int main(int argc, char **argv) 
{
    if (argc != 5) 
    {
        fprintf(stderr, "Usage: %s [file_in] [file_out] [operation] [value]\n", argv[0]);
        fprintf(stderr, "\t[operation] can be hflip, vflip, brightness, contrast\n");
        fprintf(stderr, "\t[value] is an integer for brightness and a float for contrast\n");
        return 1;
    }

    IMAGE *image = read_ppm(argv[1]);
    if (!image) 
    {
        return 1;
    }

    if (strcmp(argv[3], "hflip") == 0) 
    {
        flip_horizontal(image);
    } 
    else if (strcmp(argv[3], "vflip") == 0) 
    {
        flip_vertical(image);
    } 
    else if (strcmp(argv[3], "brightness") == 0) 
    {
        int16_t value = atoi(argv[4]);
        adjust_brightness(image, value);
    } 
    else if (strcmp(argv[3], "contrast") == 0) 
    {
        float value = atof(argv[4]);
        adjust_contrast(image, value);
    } 
    else 
    {
        fprintf(stderr, "Invalid operation\n");
        free(image->pixels);
        free(image);
        return 1;
    }

    write_ppm(argv[2], image);

    free(image->pixels);
    free(image);

    return 0;
}