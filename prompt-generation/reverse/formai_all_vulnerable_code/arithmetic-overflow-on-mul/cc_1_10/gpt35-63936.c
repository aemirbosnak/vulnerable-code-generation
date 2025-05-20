//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>

#define MAX_SIZE 1024 //maximum size of image

//Function to flip image horizontally
void flipHorizontally(int image[MAX_SIZE][MAX_SIZE], int width, int height)
{
    int temp;
    for(int j=0; j<height; j++)
    {
        for(int i=0; i<width/2; i++)
        {
            temp = image[i][j];
            image[i][j] = image[width-1-i][j];
            image[width-1-i][j] = temp;
        }
    }
}

//Function to change brightness of the image
void adjustBrightness(int image[MAX_SIZE][MAX_SIZE], int width, int height, float brightness)
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            image[i][j] *= brightness;
            if(image[i][j] > 255) //Checking if pixel value is above 255
                image[i][j] = 255;
            else if(image[i][j] < 0) //Checking if pixel value is below 0
                image[i][j] = 0;
        }
    }
}

//Function to change contrast of the image
void adjustContrast(int image[MAX_SIZE][MAX_SIZE], int width, int height, float contrast)
{
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if(image[i][j] > 255) //Checking if pixel value is above 255
                image[i][j] = 255;
            else if(image[i][j] < 0) //Checking if pixel value is below 0
                image[i][j] = 0;
        }
    }
}

//Main function
int main()
{
    int width, height;
    int image[MAX_SIZE][MAX_SIZE];
    
    //Reading image file
    FILE *fp = fopen("image.raw", "rb");
    if(fp == NULL)
    {
        printf("Error: Could not open image file!");
        return -1;
    }
    fread(image, sizeof(int), MAX_SIZE*MAX_SIZE, fp);
    fclose(fp);
    
    //Getting width and height of image
    printf("Enter width and height of image: ");
    scanf("%d %d", &width, &height);
    if(width > MAX_SIZE || height > MAX_SIZE)
    {
        printf("Error: Image size too large!");
        return -1;
    }
    
    //Flipping image horizontally
    flipHorizontally(image, width, height);
    
    //Adjusting brightness of image
    float brightness;
    printf("Enter brightness value (0.0 to 2.0): ");
    scanf("%f", &brightness);
    if(brightness < 0.0 || brightness > 2.0)
    {
        printf("Error: Invalid brightness value!");
        return -1;
    }
    adjustBrightness(image, width, height, brightness);
    
    //Adjusting contrast of image
    float contrast;
    printf("Enter contrast value (0.0 to 255.0): ");
    scanf("%f", &contrast);
    if(contrast < 0.0 || contrast > 255.0)
    {
        printf("Error: Invalid contrast value!");
        return -1;
    }
    adjustContrast(image, width, height, contrast);
    
    //Writing to output file
    fp = fopen("output.raw", "wb");
    if(fp == NULL)
    {
        printf("Error: Could not write to output file!");
        return -1;
    }
    fwrite(image, sizeof(int), width*height, fp);
    fclose(fp);
    
    printf("Image processed successfully and saved to output.raw file!");
    
    return 0;
}