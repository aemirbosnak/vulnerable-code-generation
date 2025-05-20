//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH  80
#define MAX_HEIGHT  80

char charset[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};
int intensity[] = { 230,200,180,160,130,100,70,50,30};

void printAsciiArt(unsigned char pixels[MAX_HEIGHT][MAX_WIDTH], int height, int width)
{
    int row, col;
    float step = 256.0/sizeof(charset);
    unsigned char c;
    int value, idx;

    printf("\n\n");

    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            value = pixels[row][col];
            idx = value/step;
            c = charset[idx];
            printf("%c",c);
        }
        printf("\n");
    }
}

void readImage(char filename[], unsigned char pixels[MAX_HEIGHT][MAX_WIDTH], int *height, int *width)
{
    FILE *fp;
    char format_type[3];
    int max_color, pixel;
    int row, col;

    fp = fopen(filename,"rb");

    if(fp == NULL)
    {
        printf("\n\nSorry, could not open file: %s",filename);
        return;
    }

    fscanf(fp,"%s",format_type);

    if(strcmp(format_type,"P5") != 0)
    {
        printf("\n\nSorry, format type not supported: %s",format_type);
        fclose(fp);
        return;
    }

    fscanf(fp,"%d%d",&(*width),&(*height));

    if(*height > MAX_HEIGHT || *width > MAX_WIDTH)
    {
        printf("\n\nSorry, image dimensions larger than max size: %dx%d",MAX_WIDTH,MAX_HEIGHT);
        fclose(fp);
        return;
    }

    fscanf(fp,"%d",&max_color);

    for(row = 0; row < *height; row++)
    {
        for(col = 0; col < *width; col++)
        {
            pixel = fgetc(fp);
            pixels[row][col] = (unsigned char) pixel;
        }
    }

    fclose(fp);
}



int main(int argc, char **argv)
{

    char filename[100] = "happyface.pgm";
    unsigned char pixel_values[MAX_HEIGHT][MAX_WIDTH];
    int height, width;

    readImage(filename, pixel_values, &height, &width);

    if(height == 0 || width == 0)
    {
        printf("\n\nError reading image file: %s",filename);
        return 0;
    }

    printAsciiArt(pixel_values, height, width);

    return 0;
}