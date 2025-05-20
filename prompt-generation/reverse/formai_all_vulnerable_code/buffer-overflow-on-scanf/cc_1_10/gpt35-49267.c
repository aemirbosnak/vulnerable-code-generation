//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void flip_image(unsigned char *image_data, int width, int height, int channels)
{
    unsigned char temp;
    int row, col, c;
    
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width/2; col++)
        {
            for(c = 0; c < channels; c++)
            {
                temp = image_data[(row*width + col)*channels + c];
                image_data[(row*width + col)*channels + c] = image_data[(row*width + (width-col-1))*channels + c];
                image_data[(row*width + (width-col-1))*channels + c] = temp;
            }
        }
    }
}

void adjust_brightness(unsigned char *image_data, int width, int height, int channels, int brightness)
{
    int row, col, c;
    int pixel_value;
    
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            for(c = 0; c < channels; c++)
            {
                pixel_value = image_data[(row*width + col)*channels + c] + brightness;
                if(pixel_value < 0)
                    pixel_value = 0;
                else if(pixel_value > 255)
                    pixel_value = 255;
                image_data[(row*width + col)*channels + c] = (unsigned char) pixel_value;
            }
        }
    }
}

void adjust_contrast(unsigned char *image_data, int width, int height, int channels, float contrast)
{
    int row, col, c;
    float factor = (259*(contrast + 255))/(255*(259-contrast));
    int pixel_value;
    
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            for(c = 0; c < channels; c++)
            {
                pixel_value = (int)((factor*(image_data[(row*width + col)*channels + c] - 128)) + 128);
                if(pixel_value < 0)
                    pixel_value = 0;
                else if(pixel_value > 255)
                    pixel_value = 255;
                image_data[(row*width + col)*channels + c] = (unsigned char) pixel_value;
            }
        }
    }
}

int main()
{
    int width = 100;
    int height = 100;
    int channels = 3;
    int flip_choice, brightness, contrast_choice;
    
    unsigned char *image_data = (unsigned char*)malloc(width*height*channels*sizeof(unsigned char));
    
    // initialize image_data here with random values
    
    printf("Enter your choice for flipping image:\n1. Vertical flip\n2. Horizontal flip\n");
    scanf("%d", &flip_choice);
    
    switch(flip_choice)
    {
        case 1:
            flip_image(image_data, width, height, channels);
            printf("Vertical flip completed.\n");
            break;
        case 2:
            // Rotate image 180 degrees
            flip_image(image_data, width, height, channels);
            flip_image(image_data, width, height, channels);
            printf("Horizontal flip completed.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("Enter brightness adjustment value (-255 to 255):\n");
    scanf("%d", &brightness);
    adjust_brightness(image_data, width, height, channels, brightness);
    printf("Brightness adjustment completed.\n");
    
    printf("Enter contrast adjustment factor (0.0 to 5.0):\n");
    scanf("%f", &contrast_choice);
    adjust_contrast(image_data, width, height, channels, contrast_choice);
    printf("Contrast adjustment completed.\n");
    
    free(image_data);
    return 0;
}