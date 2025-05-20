//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char* image_path, int width, int height);

int main(void)
{
    char image_path[50];
    int width, height;

    printf("Enter the path of the image: ");
    scanf("%s", image_path);
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    convert(image_path, width, height);

    return 0;
}

void convert(char* image_path, int width, int height)
{
    FILE* fp;
    fp = fopen(image_path, "rb");

    if(fp == NULL)
    {
        printf("Error: unable to open the image.\n");
        exit(1);
    }

    unsigned char* image_buffer = (unsigned char*)malloc(width * height * 4);
    unsigned char* ascii_buffer = (unsigned char*)malloc(width * height);

    fread(image_buffer, width * height * 4, 1, fp);

    int pixel_count = width * height;

    // Start processing
    for(int i = 0; i < pixel_count; i++)
    {
        unsigned char r = image_buffer[i * 4 + 0];
        unsigned char g = image_buffer[i * 4 + 1];
        unsigned char b = image_buffer[i * 4 + 2];
        // Conversion formula
        ascii_buffer[i] = 0.2126*r + 0.7152*g + 0.0722*b;
    }

    // Print the ASCII art
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int ascii_index = i * width + j;
            int pixel_index = ascii_buffer[ascii_index] / 25;

            const char* ascii_char = " .,-=+*#%@";
            printf("%c", ascii_char[pixel_index]);
        }

        printf("\n");
    }

    free(image_buffer);
    free(ascii_buffer);

    fclose(fp);
}