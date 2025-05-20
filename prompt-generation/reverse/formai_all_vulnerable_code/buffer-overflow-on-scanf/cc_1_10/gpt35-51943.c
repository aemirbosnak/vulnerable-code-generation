//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main()
{
    char ascii[MAX_HEIGHT][MAX_WIDTH]; //matrix to store the ascii art
    char chars[10] = {' ', '.', ',', '*', '^', 'o', 'O', '0', '%', '@'}; 
    //characters to represent different shades of gray

    int width, height; //variables to store the width and height of the image
    scanf("%d %d", &width, &height); //reading the width and height

    //reading the image pixel values
    int pixels[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            scanf("%d", &pixels[i][j]);
        }
    }

    //scaling the pixel values to fit within the range of characters
    int max_pixel = 0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(pixels[i][j] > max_pixel)
            {
                max_pixel = pixels[i][j];
            }
        }
    }
    float scale_factor = (float)max_pixel / (float)9;

    //converting the pixel values to ascii characters
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int index = (int)(pixels[i][j] / scale_factor);
            ascii[i][j] = chars[index];
        }
    }

    //printing the ascii art
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }

    return 0;
}