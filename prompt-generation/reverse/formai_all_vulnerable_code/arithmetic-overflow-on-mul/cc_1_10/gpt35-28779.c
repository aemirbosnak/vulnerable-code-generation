//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

//function to flip image horizontally
void flipHorizontal(int image[], int width, int height)
{
    int row, col;
    int temp;
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width/2; col++)
        {
            temp = image[row * width + col];
            image[row * width + col] = image[row * width + (width - col - 1)];
            image[row * width + (width - col - 1)] = temp;
        }
    }
}

//function to change brightness
void changeBrightness(int image[], int width, int height, int brightness)
{
    int row, col;
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            int pixelValue = image[row * width + col];
            pixelValue += brightness;
            if(pixelValue < 0)
            {
                pixelValue = 0;
            }
            else if(pixelValue > 255)
            {
                pixelValue = 255;
            }
            image[row * width + col] = pixelValue;
        }
    }
}

//function to change contrast
void changeContrast(int image[], int width, int height, float contrast)
{
    int row, col;
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            int pixelValue = image[row * width + col];
            pixelValue = (int)(pixelValue * contrast);
            if(pixelValue < 0)
            {
                pixelValue = 0;
            }
            else if(pixelValue > 255)
            {
                pixelValue = 255;
            }
            image[row * width + col] = pixelValue;
        }
    }
}

int main()
{
    int width, height, pixelCount, choice, brightness;
    float contrast;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    //dynamically allocating memory for image
    pixelCount = width * height;
    int *image = (int*)malloc(pixelCount * sizeof(int));

    //asking user to input pixel values
    int row, col;
    printf("Enter pixel values (0-255): \n");
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            scanf("%d", &image[row * width + col]);
        }
    }

    //giving user options to flip horizontally, change brightness, or change contrast
    printf("\nWhat would you like to do with the image?\n");
    printf("1. Flip horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    //selecting the appropriate function to execute based on user's choice
    switch(choice)
    {
        case 1:
            flipHorizontal(image, width, height);
            printf("\nImage flipped horizontally!\n");
            break;
        case 2:
            printf("\nEnter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            changeBrightness(image, width, height, brightness);
            printf("\nBrightness changed successfully!\n");
            break;
        case 3:
            printf("\nEnter the contrast value (0.1 to 10.0): ");
            scanf("%f", &contrast);
            changeContrast(image, width, height, contrast);
            printf("\nContrast changed successfully!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    //printing the modified image
    printf("\nModified image:\n");
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            printf("%d ", image[row * width + col]);
        }
        printf("\n");
    }

    free(image); //freeing the dynamically allocated memory

    return 0;
}