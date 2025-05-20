//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char* greyscale_list = " .:-=+*#%@";

int get_greyscale_index(int value)
{
    int range = 255 / strlen(greyscale_list);
    return value / range;
}

int main()
{
    FILE *infile;
    char filename[100];
    unsigned char img[MAX_HEIGHT][MAX_WIDTH];
    
    printf("Enter the name and path of the image file: ");
    scanf("%s", filename);
    
    infile = fopen(filename, "rb");
    
    if (infile != NULL)
    {
        // read the image size
        int width, height;
        fscanf(infile, "%d %d", &width, &height);
        
        // read the pixel data
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                fscanf(infile, "%c", &img[row][col]);
            }
        }
        
        fclose(infile);
        
        // output the ASCII art
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                int grayscale_index = get_greyscale_index(img[row][col]);
                printf("%c", greyscale_list[grayscale_index]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Error opening file.\n");
        return 1;
    }
    
    return 0;
}