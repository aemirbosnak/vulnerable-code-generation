//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

// Function to flip an image horizontally
int horizontal_flip(unsigned char *image)
{
    unsigned char temp;
    int i, j;
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH/2; j++)
        {
            temp = image[i*WIDTH+j];
            image[i*WIDTH+j] = image[i*WIDTH+WIDTH-j-1];
            image[i*WIDTH+WIDTH-j-1] = temp;
        }
    }
    return 0;
}

// Function to change brightness of an image
int brightness_change(unsigned char *image, int brightness)
{
    int i;
    for(i=0; i<WIDTH*HEIGHT; i++)
    {
        if(image[i]+brightness > 255)
            image[i] = 255;
        else if(image[i]+brightness < 0)
            image[i] = 0;
        else
            image[i] += brightness;
    }
    return 0;
}

// Function to change contrast of an image
int contrast_change(unsigned char *image, float contrast)
{
    int i;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(i=0; i<WIDTH*HEIGHT; i++)
    {
        image[i] = (int)(factor * (image[i] - 128) + 128);
    }
    return 0;
}

int main()
{
    FILE *fp;
    unsigned char image[WIDTH*HEIGHT];
    char filename[20];
    int choice;
    int brightness;
    float contrast;
    int i;

    // read the image from file
    printf("Enter the filename of the image to be processed: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    fread(image, sizeof(unsigned char), WIDTH*HEIGHT, fp);
    fclose(fp);

    // menu driven interface for image processing
    printf("\nImage processing options:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Change brightness of the image\n");
    printf("3. Change contrast of the image\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            // flip the image horizontally
            horizontal_flip(image);
            break;
        
        case 2:
            // change brightness of the image
            printf("Enter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            brightness_change(image, brightness);
            break;
        
        case 3:
            // change contrast of the image
            printf("Enter the contrast value (0.0 to 10.0): ");
            scanf("%f", &contrast);
            contrast_change(image, contrast);
            break;
        
        default:
            printf("Invalid Choice\n");
            break;
    }

    // write the processed image to file
    printf("Enter the output filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "wb");
    fwrite(image, sizeof(unsigned char), WIDTH*HEIGHT, fp);
    fclose(fp);

    return 0;
}